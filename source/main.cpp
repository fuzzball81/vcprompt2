#include <iostream>

#include "dirUtil.h"
#include "VcsTypes.h"

int main()
{
	std::string path = Utils::getFullPath();
	VCS::VcsTypes type = VCS::NONE;

	while (path != "/" && type == VCS::NONE)
	{
		std::cout << path << std::endl;
		std::list<std::string> dirs = Utils::getDirectories(path);

		for (auto iter = dirs.begin(); iter != dirs.end(); ++iter)
		{
			std::cout << "-> " << *iter << std::endl;
		}

		type = Utils::getTypeFromDir(dirs);

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
			case VCS::NONE:
				std::cout << "NOT in a REPO!!" << std::endl;
				path = Utils::removePathLevel(path);
				break;
			default:
				break;
		}
	}


	return 0;
}
