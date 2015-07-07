#include <iostream>

#include "dirUtil.h"
#include "git.h"
#include "VcsTypes.h"

int main()
{
	std::string path = Utils::getFullPath();
	VCS::VcsTypes type = VCS::NONE;
	BaseVCS *vcs = NULL;

	while (path != "/" && type == VCS::NONE)
	{
		std::list<std::string> dirs = Utils::getDirectories(path);

		type = Utils::getTypeFromDir(dirs);

		switch(type)
		{
			case VCS::GIT:
				vcs = new Git(path);
				break;
			case VCS::MERCURIAL:
				std::cout << "MERCURIAL REPO!!" << std::endl;
				break;
			case VCS::SUBVERSION:
				std::cout << "SUBVERSION REPO!!" << std::endl;
				break;
			case VCS::NONE:
				path = Utils::removePathLevel(path);
				break;
			default:
				break;
		}
	}

	if (vcs)
	{
		std::string name = vcs->getVCSName();
		std::string branch = vcs->getBranchName();
		std::string tag = "";
		std::string rev = vcs->getRevisionNumber();

		if (vcs->getBranchName().empty())
		{
			tag = vcs->getTagName();
		}

		std::string output = name + " " + branch + " " + tag + " " + rev;
		std::cout << output << std::endl;
		delete vcs;
	}

	return 0;
}
