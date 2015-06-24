#include <iostream>

#include "dirUtil.h"
#include "VcsTypes.h"

int main()
{
	std::list<std::string> dirs = Utils::getDirectories("./");

	for (auto iter = dirs.begin(); iter != dirs.end(); ++iter)
	{
		std::cout << "-> " << *iter << std::endl;
	}

	VCS::VcsTypes type = Utils::getTypeFromDir(dirs);

	std::cout << "We are ";
	switch(type)
	{
		case VCS::GIT:
			std::cout << "in a GIT REPO!!" << std::endl;
			break;
		case VCS::MERCURIAL:
			std::cout << "in a MERCURIAL REPO!!" << std::endl;
			break;
		case VCS::SUBVERSION:
			std::cout << "in a SUBVERSION REPO!!" << std::endl;
			break;
		default:
			std::cout << "NOT in a REPO!!" << std::endl;
			break;
	}

	return 0;
}
