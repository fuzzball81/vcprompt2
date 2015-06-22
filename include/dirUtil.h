#pragma once

#include <iostream>
#include <list>
#include <string>

#include <dirent.h>

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
					retList.push_back(std::string(ent->d_name));
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
}
