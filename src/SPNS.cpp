#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <tuple>

using namespace std;

int dec_to_base_n(int decimal, int to_base)
{
	vector <int> remainders;
	int remainder;
	int quotient=decimal;

	while (quotient>0)
	{
		remainder = quotient % to_base;
		quotient = quotient / to_base;
		remainders.push_back(remainder);
	}

	// [1,2,3] -> 1 * 10^2 + 2 * 10^1 + 3 * 10^0 = 123
	int result = 0;
	for (int i = remainders.size() - 1; i >= 0; i--)
	{
		int digit = remainders[i];
		result += digit * pow(10, i);
	}
	return result;

}


int char_to_int(char c) {
	// (ASCII)
	return c - '0';
}


int base_n_to_dec(int number, int from_base)
{
	string digits_str = to_string(number);

	vector <int> digits;
	for (int i = 0; i < digits_str.size(); i++)
	{
		char digit_char = digits_str[i];
		int digit = char_to_int(digit_char);
		digits.push_back(digit);
	}

	int result = 0;
	for (int i = 0; i < digits.size(); i++)
	{
		int digit = digits[i];
		int exponent = digits.size() - i - 1;
		result += digit * pow(from_base, exponent);
	}
	return result;
}


int get_base()
{
	int base;
	cin >> base;
	while (base > 10)
	{
		cout << "Please choose a base less than 10:" << endl;
	    cin >> base;
	}
	return base;
}

int main()
{
	cout << "This program is used to convert a number from one to another Standard Positional Numeral System" << endl;

	cout << "Enter a base to convert from:" << endl;
	int from = get_base();
	cout << "Enter a base to convert to:" << endl;
	int to = get_base();

	int number;
	string restart;
	int result;
	do
	{
		cout << "Please enter a number to convert:" << endl;
		cin >> number;
		int dec = base_n_to_dec(number, from);
		result = dec_to_base_n(dec, to);

		cout << "Your number in SPNS with base " << to << " is "<< result << endl;
		cout << "Thank you for using this program! Would you like to restart it?" << endl;

		cin >> restart;
	} while (restart == "yes" || restart == "Yes"); // there are chances that the user will enter the answer with first capital letter

	cout<<"Thank you for using the program! Good bye!"<<endl;

	return 0;
}
