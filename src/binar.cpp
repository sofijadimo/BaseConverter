#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

int char_to_int(char c) {
	// (ASCII)
	return c - '0';
}

int to_dec()
{
	int from_base;
	cin >> from_base;
	vector <int> digits;
	string digits_str;
	cin >> digits_str;

	for (int i = 0; i < digits_str.size(); i++)
	{
		char digit_char = digits_str[i];
		int digit = char_to_int(digit_char);
		digits.push_back(digit);
	}

	int result = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		int digit = digits[i];
		result += digit * pow(from_base, i);
	}
	return result;
}


int main()
{
	cout << to_dec();
}
