#include "Utils.hpp"

std::string toFiveDigitString(int num)
{
	std::stringstream ss;
	ss << std::setw(5) << std::setfill('0') << num;//chuyển đổi số nguyên thành chuỗi để chiều dài là 5 và thêm số 0 vào đằng trc
	return ss.str();
}
