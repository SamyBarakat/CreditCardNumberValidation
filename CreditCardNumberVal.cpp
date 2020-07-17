
// Author: Samy Barakat
// Assignment: 02
// Credit Card Number Validation

#include <string>
#include <vector>
#include <iomanip>
#include<iostream>

using namespace std;

bool isvalidcc(const string&);

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2) << i << " "
			<< setw(17) << *itr
			<< ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}

bool isvalidcc(const string& str) {
	string temp;

	int evenCount = 0;

	int oddCount = 0;

	// Loop 

	for (int i = 0; i < str.length(); i++) {
		if ((i % 2) == (str.length() % 2)) {
			char c = str.at(i);
			int x = c - '0';
			x = x * 2;

			// Here, we get ten place

			int tenDigit = (x / 10) % 10;

			// Here, we get the unit place

			int unit = x % 10;

			// Here, we have sum of even place numbers

			evenCount += (tenDigit + unit);
			temp += to_string(tenDigit + unit);
		}
		else {
			char c = str.at(i);
			int x = c - '0';

			// Here, we have sum of odd place numbers

			oddCount += x;
			temp += c;
		}
	}

	return ((evenCount + oddCount) % 10) == 0;
}