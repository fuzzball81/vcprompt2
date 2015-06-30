#pragma once

#include <algorithm>
#include <dirent.h>
#include <iostream>
#include <list>
#include <string>

#include "VcsTypes.h"

namespace Utils
{
	static const std::list<std::string> getDirectories(const std::string & baseDir)
	{
		std::list<std::string> retList;
		if (!baseDir.empty())
		{
			DIR *dir;
			struct dirent *ent;
			if ((dir = opendir (baseDir.c_str())) != NULL)
			{
				while ((ent = readdir (dir)) != NULL)
				{
					if (ent->d_type == DT_DIR)
					{
						retList.push_back(std::string(ent->d_name));
					}
				}

				closedir (dir);
			}
			else
			{
				/* could not open directory */
				std::cout << "Could not open directory!!" << std::endl;
			}
		}

		return retList;
	}

	static VCS::VcsTypes getTypeFromDir(const std::list<std::string> & dirs)
	{
		VCS::VcsTypes retType = VCS::NONE;
		if (std::find(dirs.begin(), dirs.end(), ".git") != dirs.end())
		{
			retType = VCS::GIT;
		}
		else if (std::find(dirs.begin(), dirs.end(), ".hg") != dirs.end())
		{
			retType = VCS::MERCURIAL;
		}
		else if (std::find(dirs.begin(), dirs.end(), ".svn") != dirs.end())
		{
			retType = VCS::SUBVERSION;
		}
		else
		{
			retType = VCS::NONE;
		}

		return retType;
	}
}
