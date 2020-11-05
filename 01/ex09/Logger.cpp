#include "Logger.hpp"

// CREATORS || DESTRUCTOR
			Logger::Logger() : _file_name()
{
	std::cerr << "A Logger have been created whitout argument, " <<
				"the file name will be \"log.txt\"" << std::endl;
	_file_name = "log.txt";
}

			Logger::Logger(std::string	file_name) : _file_name()
{
	_file_name = file_name;
}

			Logger::~Logger()
{
}

// METHOD
	// PRIVATE
void		Logger::logToConsole(std::string message)
{
	std::cout << makeLogEntry(message) << std::endl;
}

void		Logger::logToFile(std::string message)
{
	std::ofstream file;

	file.open(_file_name, std::ios::app);
	file << makeLogEntry(message) << std::endl;
	file.close();
}

std::string	Logger::makeLogEntry(std::string message)
{
	std::string	result;
	time_t	now(0);

	now = time(0);
	result = ctime(&now);
	result.erase(result.end() - 1);
	result += " : " + message;
	return result;
}

	// PUBLIC

void		Logger::log(std::string const &dest, std::string const &message)
{
	void		(Logger::*function[2])(std::string message);
	std::string	destinations[2];

	function[0] = &Logger::logToConsole;
	destinations[0] = "Console";
	function[1] = &Logger::logToFile;
	destinations[1] = "File";
	for (int i(0); i < 2; i++)
	{
		if (dest == destinations[i])
		{
			(this->*function[i])(message);
			return ;
		}
	}
	std::cerr << "The destination must be either \"Console\" or \"File\"" << std::endl;
}