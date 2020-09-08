#pragma once
#include <string>

/* Question : Function to convert a given binary string to gray code string
 as explained in the problem description. */
std::string binarytoGray(std::string binary) {
	std::string gray; //empty string
	std::string::iterator it = binary.begin();
	gray+= *it;//Same MSB
	bool a, b;
	std::string::iterator j = --binary.end();
	while (it != j)
	{
		a = (*it == '1');
		it++;
		b = (*it == '1');
		gray += (a != b) ? "1" : "0";
	};
	return gray;
};

/* Question : Function to convert a gray code string to binary string
 as explained in the problem description. */
std::string graytoBinary(std::string gray) {
	std::string binary; //empty string
	std::string::iterator it = gray.begin();
	binary += *it;//Same MSB
	char bin_prev = *it;
	it++;
	for (;it != gray.end();it++)
	{
		if (*it == '0') {//copy previous binary bit
			binary += bin_prev;
		}
		else {//copy inverse of previous binary bit
			bin_prev = bin_prev == '0' ? '1' : '0';
			binary += bin_prev;
		};
	};
	return binary;
}
