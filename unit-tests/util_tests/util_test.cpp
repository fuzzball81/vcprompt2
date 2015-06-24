#include "dirUtil.h"
#include "VcsTypes.h"

#include "gtest/gtest.h"

TEST(DirUtil, EmptyDirReturnEmptyList)
{
	std::list<std::string> retList = Utils::getDirectories("");
	ASSERT_EQ(true, retList.empty());
}

TEST(DirUtil, ValidDirReturnsList)
{
	std::list<std::string> retList = Utils::getDirectories("/tmp");
	ASSERT_EQ(false, retList.empty());
}

TEST(DirUtil, InvalidDirReturnsEmptyList)
{
	std::list<std::string> retList = Utils::getDirectories("/badDir");
	ASSERT_EQ(true, retList.empty());
}

TEST(GetType, EmptyReturnsNone)
{
	std::list<std::string> dirList;
	ASSERT_EQ(VCS::NONE, Utils::getTypeFromDir(dirList));
}

TEST(GetType, NoVcsDirsReturnsNone)
{
	std::list<std::string> dirList;
	dirList.push_back("A");
	dirList.push_back("B");
	dirList.push_back("C");
	dirList.push_back("D");
	ASSERT_EQ(VCS::NONE, Utils::getTypeFromDir(dirList));
}

TEST(GetType, GitDirReturnsGit)
{
	std::list<std::string> dirList;
	dirList.push_back(".git");
	ASSERT_EQ(VCS::GIT, Utils::getTypeFromDir(dirList));
}

TEST(GetType, HgDirReturnsMercurial)
{
	std::list<std::string> dirList;
	dirList.push_back(".hg");
	ASSERT_EQ(VCS::MERCURIAL, Utils::getTypeFromDir(dirList));
}

TEST(GetType, SvnReturnsSubversion)
{
	std::list<std::string> dirList;
	dirList.push_back(".svn");
	ASSERT_EQ(VCS::SUBVERSION, Utils::getTypeFromDir(dirList));
}

