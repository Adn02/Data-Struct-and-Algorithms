// Name: Aidan Cowan
// Date: 9/13/23
// Program: ECGR 3180 - Homework 3: Reverse String Recursion
// Description:
// 
// Write a short recursive C++ function that determines if a string s is a
// palindrome, that is, it is equal to its reverse. For example, "racecar"
// and "gohangasalamiimalasagnahog" are palindromes.
// Note: Your implementation has to be recursive. Zero points for non-recursive code even if it's correct.

#include <iostream>
#include <string>

using namespace std;

bool isPalinHelper(string& s, int begin, int end) {
	if (begin >= end) {
		return true;
	}else if (s.at(begin) == s.at(end)) {
		return isPalinHelper(s, begin + 1, end - 1);
	}else {
		return false;
	}
}

bool isPalin(string& s) {
	return isPalinHelper(s, 0, s.size()-1);
}

int main() {
	string s1{ "racecar" }; // palindrome
	string s2{ "racecars" }; // not a palindrome
	string s3{ "gohangasalamiimalasagnahog" };

	if (isPalin(s1)) {
		cout << s1 << " is a palindrome" << endl;
	}
	else {
		cout << s1 << " is not a palindrome" << endl;
	}

	if (isPalin(s2)) {
		cout << s2 << " is a palindrome" << endl;
	}
	else {
		cout << s2 << " is not a palindrome" << endl;
	}

	if (isPalin(s3)) {
		cout << s3 << " is a palindrome" << endl;
	}
	else {
		cout << s3 << " is not a palindrome" << endl;
	}
}
