#ifndef SUBVERSION_H
#define SUBVERSION_H

#include "BaseVCS.h"

class Subversion : public BaseVCS
{

	public:
		Subversion();
		virtual ~Subversion();

		// From BaseVCS
		virtual const std::string getVCSName();
		virtual const std::string getBranchName();
		virtual const std::string getPatchName();
		virtual const int32_t getRevisionNumber();
};

#endif
