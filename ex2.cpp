// Exercise2_Factorial_Of_A_Number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0) return 1;// điều kiện dừng 0!=1
    return n * factorial(n - 1); // đệ quy n!=n*(n-1)!
}
int main()
{
    int n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}


