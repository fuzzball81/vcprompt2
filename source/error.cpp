#include "error.h"

Error::Error()
{
	error_code = 0;
	error_message = "";
}

Error::~Error()
{
}

void Error::setErrorCode(int32_t code)
{
	error_code = code;
}

void Error::setErrorMessage(const char * message)
{
	error_message.assign(message);
}

const int32_t Error::getErrorCode() const
{
	return error_code;
}

const std::string Error::getErrorMessage() const
{
	return error_message;
}
