#pragma once
#include<stack>
#include<string>
#include <assert.h>     /* assert */

bool isValid(char c) {
	//Check if A-Z or a-z or 0-9
	return (c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57);
}
int validPrefix(std::string& prefix) {
	std::string::iterator it = prefix.begin();
	int ops = 0;

	for (;it != prefix.end();it++) {
		if (*it == '+' || *it == '-' || *it == '/' || *it == '*' || *it == '^') { ops++; }
		else if (isValid(*it)) { continue; }//do nothing
		else { return -1; }
	}
	return ops;
};

std::string prefix_to_infix(std::string prefix) {
	int ops = validPrefix(prefix);
	if (ops!=-1) {
		std::stack<char> ops; //operator stack
		//std::stack<char> bracks; // ')' stack
		std::string::iterator it = prefix.begin();
		std::string infix;
		for (;it != prefix.end();it++) {
			if (isValid(*it)) {
				infix.push_back(*it);
				if (!ops.empty()) {
					while (ops.top() == ')') {
						infix.push_back(ops.top());ops.pop();
						if (ops.empty()) { break; }
					}
					if (!ops.empty()) { infix.push_back(ops.top());ops.pop(); }
				}
			}//is operand
			else {
				ops.push(')');ops.push(*it);infix.push_back('(');
			}//must be operator
		}
		return infix;
	}
	else { std::cout << "Invalid prefix input string."; return ""; }
}