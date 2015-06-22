#pragma once

#include <iostream>
#include <list>
#include <string>

#include <dirent.h>

namespace Utils
{
	static const std::list<std::string> getDirectories(const std::string & baseDir)
	{
		DIR *dir;
		struct dirent *ent;
		std::list<std::string> retList;
		if ((dir = opendir (baseDir.c_str())) != NULL)
		{
			/* print all the files and directories within directory */
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

		return retList;
	}
}
