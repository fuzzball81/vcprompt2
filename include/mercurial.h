#ifndef MERCURIAL_H
#define MERCURIAL_H

#include "BaseVCS.h"

class Mercurial : public BaseVCS
{

	public:
		Mercurial();
		virtual ~Mercurial();

		// From BaseVCS
		virtual const std::string getVCSName() {return "hg";}
		virtual const std::string getBranchName();
		virtual const std::string getPatchName();
		virtual const int32_t getRevisionNumber();
};

#endif
