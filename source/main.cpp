#include "game.h"
#include <string>
#include <iostream>

#ifdef WIN32
char const pathSeperator = '\\';
#else
char const pathSeperator = '/';
#endif

int main(int argc, char **argv)
{
	std::string executablePath{ argv[0] };
	auto lastSeperator = executablePath.find_last_of(pathSeperator);
	if(lastSeperator == std::string::npos)
	{
		std::cout << "Unable to work out application path" << std::endl;
		return 1;
	}
	std::string applicationPath{ executablePath.begin(), executablePath.begin() + lastSeperator + 1 };
	game_main(applicationPath);
    return 0;
}
