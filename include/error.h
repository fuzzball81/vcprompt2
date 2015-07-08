#pragma once

#include <string>
#include <stdint.h>

class Error
{
	public:
		Error();
		~Error();

		void setErrorCode(int32_t code);
		void setErrorMessage(const char * message);

		const int32_t getErrorCode() const;
		const std::string getErrorMessage() const;

	private:
		int32_t error_code;
		std::string error_message;
};
