// Exercise1_Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1) return n;// điều kiện dừng fibonacci(0)=0, fibonacci(1)=1;
    return fibonacci(n - 1) + fibonacci(n - 2);// đệ quy để tính số fibonacci(n)
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    return 0;
}

