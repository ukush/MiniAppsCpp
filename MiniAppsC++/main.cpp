#include <iostream>
#include <Windows.h>
#include "MiniApps.h"

using namespace std;

int main()
{
	int value;	
	do {
		cout << "Mini Apps\n";
		cout << "---------\n";
		cout << "1. Keep Counting\n";
		cout << "2. Number Conversion\n";
		cout << "3. UPC Generator\n";
		cout << "4. UPC Checker\n";
		cout << "9. Quit\n";

		cout << "Please Enter an option\n";
		cin >> value;

		switch (value) {
		case 1: MiniApps::keepCounting(); break;
		case 2: MiniApps::numberConversion(); break;
		case 3: MiniApps::upcConverter(); break;
		case 4: MiniApps::upcChecker();
			break;
		case 9: break;
		default: cout << "Invalid input\n";
		}
	} while (value != 9);
	return 0;
}