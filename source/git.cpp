#include "git2/global.h"
#include "git.h"

Git::Git(const std::string & path)
{
	git_libgit2_init();
	repo = NULL;
	git_repository_open(&repo, path.c_str());
}

Git::~Git()
{
	git_libgit2_shutdown();
	git_repository_free(repo);
}

const std::string Git::getVCSName() const
{
	return "git";
}

const std::string Git::getBranchName()
{
	std::string retString = "";
	const char *branch = NULL;
	git_reference *head = NULL;

	git_repository_head(&head, repo);
	git_branch_name(&branch, head);
	git_reference_free(head);

	if (branch)
	{
		retString.assign(branch);
	}
	return retString;
}

const std::string Git::getPatchName()
{
	return "";
}

const std::string Git::getRevisionNumber()
{
	std::string retString = "";
	return retString;
}
