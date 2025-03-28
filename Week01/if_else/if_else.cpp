// if_else.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int num;
	cout << "Enter a number: ";
	cin >> num;
	if (num % 2 == 0)
	{
		cout << num << " is even." << endl;
	}
	else
	{
		cout << num << " is odd." << endl;
	}
	return 0;
}

