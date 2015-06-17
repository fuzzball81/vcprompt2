#ifndef GIT_H
#define GIT_H

#include <stdint.h>

#include "BaseVCS.h"

class Git : public BaseVCS
{

	public:
		Git();
		virtual ~Git();

		// From BaseVCS
		virtual const std::string getVCSName() {return "git";}
		virtual const std::string getBranchName();
		virtual const std::string getPatchName();
		virtual const int32_t getRevisionNumber();
};

#endif
