#include "git2.h"
#include "mockgit2.h"

int set_branch = 0;

void setupBranch(void)
{
	set_branch = 1;
}

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
	if (set_branch)
	{
		*out = "test_branch_name";
	}

	return 1;
}

int git_reference_name_to_id(git_oid *out, git_repository *repo, const char *name)
{
	return 1;
}

char * git_oid_tostr(char *out, size_t n, const git_oid *id)
{
	return "abcdefg";
}
