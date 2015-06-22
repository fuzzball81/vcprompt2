#include <iostream>

#include "dirUtil.h"

int main()
{
	std::list<std::string> dirs = Utils::getDirectories("./");

	for (auto iter = dirs.begin(); iter != dirs.end(); ++iter)
	{
		std::cout << "-> " << *iter << std::endl;
	}

	return 0;
}
