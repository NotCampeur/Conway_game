# class_init
A program that automatize the creation of cpp class file and complete the hpp file.

# use exemple

	class c_class
	{
			std::string     _name;
			char            _arg_one;
			char            _arg_two;
			char            _arg_three;
			char            _arg_four;
			char            _arg_five;
	};

	is the minimal header require to make the program work

#TODO 
	-Correct the tab bug (which trunc letters)
	-Ask for a destination directory for the creation of Cpp
	-Add a ATTRIBUTES comment in hpp
	-Add a warning comment in cpp for the print method. (The class need a << operator)