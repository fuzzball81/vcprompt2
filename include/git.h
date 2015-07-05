#ifndef GIT_H
#define GIT_H

#include <stdint.h>

#include "BaseVCS.h"

class Git : public BaseVCS
{

	public:
		Git(const std::string & path);
		virtual ~Git();

		// From BaseVCS
		virtual const std::string getVCSName() const;
		virtual const std::string getBranchName();
		virtual const std::string getPatchName();
		virtual const int32_t getRevisionNumber();
};

#endif
