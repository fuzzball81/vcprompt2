#include "git2.h"

int git_libgit2_init(void)
{
	return 1;
}


int git_libgit2_shutdown(void)
{
	return 1;
}

int git_repository_open(git_repository **out, const char *path)
{
	return 1;
}

void git_repository_free(git_repository *repo)
{
	return;
}

int git_repository_head(git_reference **out, git_repository *repo)
{
	return 1;
}

void git_reference_free(git_reference *ref)
{
	return;
}

int git_branch_name(const char **out, const git_reference *ref)
{
	return 1;
}
