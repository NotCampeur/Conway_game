/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_init_data.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:57:23 by ldutriez          #+#    #+#             */
/*   Updated: 2020/09/17 20:43:07 by ldutriez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_INIT_DATA_HPP
# define CLASS_INIT_DATA_HPP

# include <iostream>
# include <fstream>
# include <vector>

# define TYPE 0
# define NAME 1

class c_class_init_data
{
    private:
        std::string                 _path;
        std::vector<std::string>    _header_file;
        std::vector<std::string>    _source_file;
        std::string                 **_var_info;
        std::string                 _class_name;
        int                         _type_spacing;
        int                         _var_spacing;
        int                         _class_scope_start;
        int                         _class_scope_end;

    public:
// CONSTRUCTORS | DESTRUCTOR

                                    c_class_init_data();
                                    ~c_class_init_data();
// ACCESSORS
    // GETTERS

        std::string                 path(void) const;
        std::vector<std::string>    header_file(void) const;
        std::vector<std::string>    source_file(void) const;
        std::string                 **var_info(void) const;
        std::string                 class_name(void) const;
        int                         type_spacing(void) const;
        int                         var_spacing(void) const;
        int                         class_scope_start(void) const;
        int                         class_scope_end(void) const;
    // SETTERS

        void                        set_path(std::string path);
        void                        set_header_file(std::vector<std::string> header_file);
        void                        set_source_file(std::vector<std::string> source_file);
        void                        set_var_info(std::string **tab);
        void                        emplace_header_file(int pos, std::string new_str);
        void                        emplace_source_file(int pos, std::string new_str);
        void                        set_class_name(std::string class_name);
        void                        set_type_spacing(int nbr);
        void                        set_var_spacing(int nbr);
        void                        set_class_scope_start(int line);
        void                        set_class_scope_end(int line);
    // PRINTERS

        void                        print_path(void) const;
        void                        print_header_file(void) const;
        void                        print_source_file(void) const;
        void                        print_var_info(void) const;
        void                        print_class_name(void) const;
        void                        print_type_spacing(void) const;
        void                        print_var_spacing(void) const;
        void                        print_class_scope_start(void) const;
        void                        print_class_scope_end(void) const;
};

extern  c_class_init_data *g_data;

#endif