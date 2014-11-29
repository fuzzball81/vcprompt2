#include <string>

class BaseVCS
{
	public:
		const std::string getVCSName() = 0;
		const std::string getBranchName() = 0;
		const std::string getPatchName() = 0;
		const int32_t getRevisionNumber() = 0;
};
