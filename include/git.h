#ifndef GIT_H
#define GIT_H

#include "BaseVCS.h"

class Git : public BaseVCS
{

	public:
		Git();
		virtual ~Git();

		// From BaseVCS
		virtual const std::string getVCSName();
		virtual const std::string getBranchName();
		virtual const std::string getPatchName();
		virtual const int32_t getRevisionNumber();
};

#endif
