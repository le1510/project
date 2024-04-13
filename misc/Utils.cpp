#include "Utils.hpp"

std::string toFiveDigitString(int num)
{
	std::stringstream ss;
	ss << std::setw(5) << std::setfill('0') << num;
	return ss.str();
}

