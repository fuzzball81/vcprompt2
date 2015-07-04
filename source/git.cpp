#include "git2/global.h"
#include "git.h"

Git::Git()
{
	git_libgit2_init();
}

Git::~Git()
{
	git_libgit2_shutdown();
}

const std::string Git::getVCSName() const
{
	return "git";
}

const std::string Git::getBranchName()
{
	return "";
}

const std::string Git::getPatchName()
{
	return "";
}

const int32_t Git::getRevisionNumber()
{
	return 0;
}
