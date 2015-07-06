#ifndef BASE_VCS_H
#define BASE_VCS_H

#include <string>

class BaseVCS
{
	public:
		virtual ~BaseVCS() {};
		virtual const std::string getVCSName() const = 0;
		virtual const std::string getBranchName() = 0;
		virtual const std::string getPatchName() = 0;
		virtual const std::string getRevisionNumber() = 0;
		virtual const std::string getTagName() = 0;
};

#endif
