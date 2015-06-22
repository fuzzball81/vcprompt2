#include "dirUtil.h"
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
