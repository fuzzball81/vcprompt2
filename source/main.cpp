#include <iostream>
#include <dirent.h>

int main()
{
	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("./")) != NULL)
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL)
		{
			std::cout << ent->d_name << std::endl;
		}

		closedir (dir);
	}
	else
	{
		/* could not open directory */
		std::cout << "Could not open directory!!" << std::endl;
		return -1;
	}

	return 0;
}
