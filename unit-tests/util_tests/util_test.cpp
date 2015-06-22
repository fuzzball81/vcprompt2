#include "dirUtil.h"
#include "gtest/gtest.h"

TEST(DirUtil, EmptyDirReturnEmptyList)
{
	std::list<std::string> retList = Utils::getDirectories("");
	ASSERT_EQ(true, retList.empty());
}

