#include "git.h"
#include "gtest/gtest.h"

TEST(GitInterface, NameIsNotEmpty)
{
	Git g("");
	ASSERT_NE("", g.getVCSName());
}

TEST(GitInterface, NameIsCorrect)
{
	Git g("");
	ASSERT_EQ("git", g.getVCSName());
}

TEST(GitInterface, BranchNameWorksWithNull)
{
	Git g("");
	ASSERT_EQ("", g.getBranchName());
}
