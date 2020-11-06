/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_init.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:53:34 by ldutriez          #+#    #+#             */
/*   Updated: 2020/11/06 12:18:23 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/class_init_data.hpp"

using namespace std;

c_class_init_data *g_data = new c_class_init_data;

static string   create_spaces(int nbr)
{
    string  result;

	if (nbr <= 0)
        result += ' ';
    for (int i(0); i < nbr; i++)
        result += ' ';
    return result;
}

static void quit(string msg)
{
    cout << msg << endl;
    exit(1);
}

static void catch_file_path(void)
{
    string  input;

    cout << "Please type the .h/.hpp file name with the relative path" << endl;
    getline(cin, input);
    g_data->set_path(input);
}

static void save_hpp_file(void)
{
    ifstream        h_file(g_data->path());
    vector<string>  vec_tmp;
    string          str_tmp;

    if (h_file.is_open() == false)
        quit("Error during header file opening");
    while (getline(h_file, str_tmp))
        vec_tmp.push_back(str_tmp);
    g_data->set_header_file(vec_tmp);
    h_file.close();
}

static void find_closing_bracket(void)
{
    for (unsigned long i(0); i < g_data->header_file().size(); i++)
        for (unsigned long j(0); g_data->header_file()[i][j]; j++)
            if (g_data->header_file()[i][j] == '}')
            {
                g_data->set_class_scope_end(i);
                return ;
            }
    quit("You need to have, at least the class scope, there is no closing bracket");
}

static void find_opening_bracket(void)
{
    for (unsigned long i(0); i < g_data->header_file().size(); i++)
        for (unsigned long j(0); g_data->header_file()[i][j]; j++)
            if (g_data->header_file()[i][j] == '{')
            {
                g_data->set_class_scope_start(i);
                return ;
            }
    quit("You need to have, at least the class scope, there is no opening bracket");
}

static void find_class_name(void)
{
    int c_n_start(0);

    for (unsigned long i(0); i < g_data->header_file().size(); i++)
    {
        c_n_start = g_data->header_file()[i].find("class ");
        if (c_n_start == -1 && i + 1 >= g_data->header_file().size())
            quit("There is no class name found");
        else if (c_n_start >= 0)
        {
            while (isspace(g_data->header_file()[i][c_n_start + 6]) == true)
                c_n_start++;
            g_data->set_class_name(g_data->header_file()[i].substr(c_n_start + 6));
            return ;
        }
    }
}

static void find_spaces_nbr(void)
{
    int     spaces(0);

    while (g_data->header_file()[g_data->class_scope_end() - 1][spaces] == ' '
			|| g_data->header_file()[g_data->class_scope_end() - 1][spaces] == '\t')
    {
		if (g_data->header_file()[g_data->class_scope_end() - 1][spaces] == '\t')
			spaces += 1;
		else if (g_data->header_file()[g_data->class_scope_end() - 1][spaces] == ' ')
			spaces++;
    }
    g_data->set_type_spacing(spaces);
    while (g_data->header_file()[g_data->class_scope_end() - 1][spaces] != '_')
    {
		if (g_data->header_file()[g_data->class_scope_end() - 1][spaces] == '\t')
			spaces += 1;
		else
			spaces++;

    }
    g_data->set_var_spacing(spaces);

}

static void find_var_info(void)
{
    int     info_len(0);
	int		line_nbr(0);
	string	**var_tab(NULL);

	line_nbr = g_data->class_scope_end() - (g_data->class_scope_start() + 1);
	var_tab = new string*[line_nbr];
	for (int i(0); i < line_nbr; i++)
		var_tab[i] = new string[3];
	for (int index(g_data->class_scope_start() + 1); index < g_data->class_scope_end(); index++)
    {
        info_len = 0;
        while (g_data->header_file()[index][g_data->type_spacing() + info_len] != '\0'
				&& isspace((g_data->header_file())[index][g_data->type_spacing() + info_len]) == false)
            info_len++;
		var_tab[index - (g_data->class_scope_start() + 1)][TYPE].assign(g_data->header_file()[index], g_data->type_spacing(), info_len);
        info_len = 0;
        while (g_data->header_file()[index][g_data->var_spacing() + info_len] != '\0'
				&& isspace(g_data->header_file()[index][g_data->var_spacing() + info_len]) == false)
            info_len++;
		var_tab[index - (g_data->class_scope_start() + 1)][NAME].assign(g_data->header_file()[index], g_data->var_spacing(), info_len - 1);
    }
	g_data->set_var_info(var_tab);
}

static void init_class_data(void)
{
    find_class_name();
    find_opening_bracket();
    find_closing_bracket();
    find_spaces_nbr();
    find_var_info();
}

static int	increm(int *nbr)
{
	(*nbr)++;
	return *nbr;
}

static void format_getters_prototype(int *l)
{
	string	tmp_name;

	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
	{
		tmp_name = g_data->var_info()[i][NAME];
		tmp_name.erase(0, 1);
		g_data->emplace_header_file(g_data->class_scope_end() + increm(l),
												create_spaces(g_data->type_spacing())
													+ g_data->var_info()[i][TYPE]
													+ create_spaces(g_data->var_spacing() - g_data->type_spacing() - g_data->var_info()[i][TYPE].size())
													+ tmp_name + "(void) const;");
	}
}

static void format_setters_prototype(int *l)
{
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
	{
		g_data->emplace_header_file(g_data->class_scope_end() + increm(l),
												create_spaces(g_data->type_spacing())
													+ "void"
													+ create_spaces(g_data->var_spacing() - g_data->type_spacing() - 4)
													+ "set"
													+ g_data->var_info()[i][NAME] + "(" + g_data->var_info()[i][TYPE]
													+ " value);");
	}
}

static void format_printers_prototype(int *l)
{
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
	{
		g_data->emplace_header_file(g_data->class_scope_end() + increm(l),
												create_spaces(g_data->type_spacing())
													+ "void"
													+ create_spaces(g_data->var_spacing() - g_data->type_spacing() - 4)
													+ "print"
													+ g_data->var_info()[i][NAME] + "(void) const;");
	}
}

static void format_hpp_file(void)
{
	int l(0);

	init_class_data();
	g_data->emplace_header_file(g_data->class_scope_start() + 1, create_spaces(g_data->type_spacing() / 2) + "private:");
	g_data->emplace_header_file(g_data->class_scope_end() + ++l, "");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), create_spaces(g_data->type_spacing() / 2) + "public:");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "// CONSTRUCTORS | DESTRUCTOR");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), create_spaces(g_data->var_spacing()) + g_data->class_name() + "();");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), create_spaces(g_data->var_spacing()) + g_data->class_name() + "(" + g_data->class_name() + " const &obj);");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), create_spaces(g_data->var_spacing()) + "~" + g_data->class_name() + "();");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "// ACCESSORS");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "	// GETTERS");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "");
	format_getters_prototype(&l);
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "	// SETTERS");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "");
	format_setters_prototype(&l);
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "	// PRINTERS");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "");
	format_printers_prototype(&l);
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "	// OPERATORS");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), "");
	g_data->emplace_header_file(g_data->class_scope_end() + increm(&l), create_spaces(g_data->type_spacing()) + g_data->class_name() + create_spaces(g_data->var_spacing() - g_data->class_name().size() - g_data->type_spacing()) + "&operator=(" + g_data->class_name() + " const &obj);");
}

static void	format_basic_constructor(int *l)
{
	string	init_list;

	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
		if (g_data->var_info()[i][TYPE].compare("int") != 0 && g_data->var_info()[i][TYPE].compare("char") != 0
			&& g_data->var_info()[i][TYPE].compare("float") != 0 && g_data->var_info()[i][TYPE].compare("double") != 0)
		{
			if (init_list.size() == 0)
				init_list += " : ";
			else
				init_list += " , ";
			init_list += g_data->var_info()[i][NAME];
			init_list += "()";
		}
	g_data->emplace_source_file(increm(l), create_spaces(g_data->var_spacing()) + g_data->class_name() + "::" + g_data->class_name() + "()" + init_list);
	g_data->emplace_source_file(increm(l), "{");
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
		if (g_data->var_info()[i][TYPE].compare("int") == 0 || g_data->var_info()[i][TYPE].compare("char") == 0
			|| g_data->var_info()[i][TYPE].compare("float") == 0 || g_data->var_info()[i][TYPE].compare("double") == 0)
		{
			g_data->emplace_source_file(increm(l), "	" + g_data->var_info()[i][NAME] + " = 0;");
		}
	g_data->emplace_source_file(increm(l), "}");
}

static void format_copy_constructor(int *l)
{
	g_data->emplace_source_file(increm(l), create_spaces(g_data->var_spacing()) + g_data->class_name() + "::" + g_data->class_name() + "(" + g_data->class_name() + " const &obj)");
	g_data->emplace_source_file(increm(l), "{");
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
		g_data->emplace_source_file(increm(l), "	" + g_data->var_info()[i][NAME] + " = obj." + g_data->var_info()[i][NAME] + ";");

	g_data->emplace_source_file(increm(l), "}");
}

static void	format_basic_destructor(int *l)
{
	g_data->emplace_source_file(increm(l), create_spaces(g_data->var_spacing()) + g_data->class_name() + "::~" + g_data->class_name() + "()");
	g_data->emplace_source_file(increm(l), "{");
	g_data->emplace_source_file(increm(l), "	//Don't forget to delete your allocated attributes here");
	g_data->emplace_source_file(increm(l), "}");
}

static void format_getters(int *l)
{
	string	name_tmp;
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
	{
		name_tmp = g_data->var_info()[i][NAME];
		name_tmp.erase(0, 1);
		g_data->emplace_source_file(increm(l), g_data->var_info()[i][TYPE] + create_spaces(g_data->var_spacing() - g_data->var_info()[i][TYPE].size()) + g_data->class_name() + "::" + name_tmp + "(void) const");
		g_data->emplace_source_file(increm(l), "{");
		g_data->emplace_source_file(increm(l), "	return " + g_data->var_info()[i][NAME] + ";");
		g_data->emplace_source_file(increm(l), "}");
		g_data->emplace_source_file(increm(l), "");
	}
}

static void format_setters(int *l)
{
	string	name_tmp;
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
	{
		name_tmp = g_data->var_info()[i][NAME];
		name_tmp.erase(0, 1);
		g_data->emplace_source_file(increm(l), "void" + create_spaces(g_data->var_spacing() - 4) + g_data->class_name() + "::set" + g_data->var_info()[i][NAME] + "(" + g_data->var_info()[i][TYPE] + " value)");
		g_data->emplace_source_file(increm(l), "{");
		g_data->emplace_source_file(increm(l), "	" + g_data->var_info()[i][NAME] + " = value;");
		g_data->emplace_source_file(increm(l), "}");
		g_data->emplace_source_file(increm(l), "");
	}
}

static void format_printers(int *l)
{
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
	{
		g_data->emplace_source_file(increm(l), "void" + create_spaces(g_data->var_spacing() - 4) + g_data->class_name() + "::print" + g_data->var_info()[i][NAME] + "(void) const");
		g_data->emplace_source_file(increm(l), "{");
		g_data->emplace_source_file(increm(l), "	cout << " + g_data->var_info()[i][NAME] + " << endl;");
		g_data->emplace_source_file(increm(l), "}");
		g_data->emplace_source_file(increm(l), "");
	}
}

static void	format_operators(int *l)
{
	g_data->emplace_source_file(increm(l), g_data->class_name() + create_spaces(g_data->var_spacing() - g_data->class_name().size()) + "&" + g_data->class_name() + "::operator=(" + g_data->class_name() + " const &obj)");
	g_data->emplace_source_file(increm(l), "{");
	for (int i = 0; i < g_data->class_scope_end() - (g_data->class_scope_start() + 1); i++)
		g_data->emplace_source_file(increm(l), "	" + g_data->var_info()[i][NAME] + " = obj." + g_data->var_info()[i][NAME] + ";");
	g_data->emplace_source_file(increm(l), "	return *this;");
	g_data->emplace_source_file(increm(l), "}");
	g_data->emplace_source_file(increm(l), "");
}

static void format_cpp_file(void)
{
	int	l(0);

	g_data->emplace_source_file(increm(&l), "#include \"" + g_data->path() + "\"");
	g_data->emplace_source_file(increm(&l), "");
	g_data->emplace_source_file(increm(&l), "using namespace std;");
	g_data->emplace_source_file(increm(&l), "");
	g_data->emplace_source_file(increm(&l), "// CONSTRUCTORS | DESTRUCTOR");
	g_data->emplace_source_file(increm(&l), "");
	format_basic_constructor(&l);
	g_data->emplace_source_file(increm(&l), "");
	format_copy_constructor(&l);
	g_data->emplace_source_file(increm(&l), "");
	format_basic_destructor(&l);
	g_data->emplace_source_file(increm(&l), "");
	g_data->emplace_source_file(increm(&l), "// ACCESSORS");
	g_data->emplace_source_file(increm(&l), "	// GETTERS");
	g_data->emplace_source_file(increm(&l), "");	
	format_getters(&l);
	g_data->emplace_source_file(increm(&l), "	// SETTERS");
	g_data->emplace_source_file(increm(&l), "");
	format_setters(&l);
	g_data->emplace_source_file(increm(&l), "	// PRINTERS");
	g_data->emplace_source_file(increm(&l), "");
	format_printers(&l);
	g_data->emplace_source_file(increm(&l), "	// OPERATORS");
	g_data->emplace_source_file(increm(&l), "");
	format_operators(&l);
}

void		upload_formated_files()
{
	ofstream	header_file;
	ofstream	source_file;
	string		source_path;
	int			index;

	source_path = g_data->path();
	index = source_path.find(".h");
	source_path.replace(index, 2, ".c");
	header_file.open(g_data->path());
	for (size_t i(0); i < g_data->header_file().size(); i++)
	{
		header_file.write(g_data->header_file()[i].c_str(), g_data->header_file()[i].size());
		header_file.write("\n", 1);
	}
	header_file.close();
	source_file.open(source_path);
	for (size_t i(0); i < g_data->source_file().size(); i++)
	{
		source_file.write(g_data->source_file()[i].c_str(), g_data->source_file()[i].size());
		source_file.write("\n", 1);
	}
	source_file.close();
}

int         main(void)
{
    catch_file_path();
    save_hpp_file();
    format_hpp_file();
    format_cpp_file();
    upload_formated_files();
    return 0;
}