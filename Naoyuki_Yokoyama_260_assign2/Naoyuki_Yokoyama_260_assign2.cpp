// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included

#include "pch.h"

#include <iostream>
#include <vector>
#include <string>

// NOTE: The ONLY files that should be #included for this assignment are iostream, vector, and string
// No other files should be #included


using namespace std;

int bin_to_dec(string);
string dec_to_bin(int);
int hex_to_dec(string);
string dec_to_hex(int);



int main()
{

	cout << "10000011 binary = " << bin_to_dec("10000011") << " decimal\n"; // you should get 131
	cout << "01010101 binary = " << bin_to_dec("01010101") << " decimal\n"; // you should get 85
	cout << "1111111111111111 binary = " << bin_to_dec("1111111111111111") << " decimal\n"; // you should get 65,535
	cout << "0111111111111111 binary = " << bin_to_dec("0111111111111111") << " decimal\n\n"; // you should get 32,767

	cout << "255 decimal = " << dec_to_bin(255) << " binary\n"; //you should get 11111111
	cout << "65532 decimal = " << dec_to_bin(65532) << " binary\n"; //you should get 1111111111111100
	cout << "12 decimal = " << dec_to_bin(12) << " binary\n"; //you should get 1100
	cout << "1000000 decimal = " << dec_to_bin(1000000) << " binary\n\n"; //you should get 11110100001001000000

	cout << "ABC hexadecimal = " << hex_to_dec("ABC") << " decimal\n"; //you should get 2,748
	cout << "F5 hexadecimal = " << hex_to_dec("F5") << " decimal\n"; //you should get 245
	cout << "1234 hexadecimal = " << hex_to_dec("1234") << " decimal\n"; //you should get 4,660
	cout << "FDECB hexadecimal = " << hex_to_dec("FDECB") << " decimal\n\n"; //you should get 1,040,075

	cout << "512 decimal = " << dec_to_hex(512) << " hexadecimal\n"; //you should get 200
	cout << "5000 decimal = " << dec_to_hex(5000) << " hexadecimal\n"; //you should get 1388
	cout << "900000 decimal = " << dec_to_hex(900000) << " hexadecimal\n"; //you should get DBBA0
	cout << "65525 decimal = " << dec_to_hex(65525) << " hexadecimal\n\n"; //you should get FFF5


	system("PAUSE");
	return 0;

}

// Converts any UNsigned binary number to decimal

int bin_to_dec(string s)
{
	int value = 0;
	for (int i = 0; i < s.size(); i++) {
		//value += (s[i] - '0')*pow(2, s.size() - 1 - i);
		int n = 1;
		for (int j = 0; j < s.size() - 1 - i; j++) {
			n *= 2;
		}
		value += (s[i] - '0')*n;
	}
	return value;
}

//Converts any non-negative decimal number to binary

string dec_to_bin(int n)
{
	string value;
	vector<int> temp;
	while (n > 0) {
		temp.push_back(n % 2);
		n /= 2;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		value.push_back(temp[i] + '0');
	}
	return value;
}

//Converts any UNsigned hexadecimal number to decimal

int hex_to_dec(string s)
{
	int value = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65) {
			//value += (s[i] - 55)*pow(16, s.size() - 1 - i);
			int n = 1;
			for (int j = 0; j < s.size() - 1 - i; j++) {
				n *= 16;
			}
			value += (s[i] - 55)*n;
		}
		else {
			//value += (s[i] - '0')*pow(16, s.size() - 1 - i);
			int n = 1;
			for (int j = 0; j < s.size() - 1 - i; j++) {
				n *= 16;
			}
			value += (s[i] - '0')*n;
		}
	}
	return value;
}


//Converts any non-negative decimal number to hexadecimalConverts any non-negative decimal number to hexadecimal

string dec_to_hex(int n)
{
	string value;
	vector<int> temp;
	while (n > 0) {
		temp.push_back(n % 16);
		n /= 16;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		if (temp[i] >= 10) {
			value.push_back(temp[i] + 55);
		}
		else
			value.push_back(temp[i] + '0');
	}
	return value;
}



