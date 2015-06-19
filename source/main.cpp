#include <iostream>
#include <dirent.h>

int main()
{
	std::cout << "Hello World" << std::endl;

	DIR *dir;
	struct dirent *ent;
	if ((dir = opendir ("./")) != NULL)
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL)
		{
			printf ("%s\n", ent->d_name);
		}

		closedir (dir);
	}
	else
	{
		/* could not open directory */
		perror ("");
		return EXIT_FAILURE;
	}

	return 0;
}
