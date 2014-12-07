#ifndef BASE_VCS_H
#define BASE_VCS_H

#include <string>

class BaseVCS
{
	public:
		virtual const std::string getVCSName() = 0;
		virtual const std::string getBranchName() = 0;
		virtual const std::string getPatchName() = 0;
		virtual const int32_t getRevisionNumber() = 0;
};

#endif
