// ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int min_element_of_arrays(int* a, int n)
{
    // 4 5 6 7 9 0 1 2 3 mid=4, a[mid]=9, amid<aright
    // 8 9 1 2 3 4 5 6 7 mid =4, amid=3, amid
    // 4 5 6 7 8 9 0 1 2
    // 3 4 5 6 8 1 2
    // 6 7 0 1 2 3 4
    int left = 0;
    int right = n - 1;
    int mid = left + (right - left) / 2;
    while (left <= right)
    {
        
        if (a[mid] > a[right])
        {
            left = mid + 1;
            mid = left + (right - left) / 2;
        }
        else
        {
            right = mid;
            mid = left + (right - left) / 2;
        }
        return a[left];
    }
   
}
int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << min_element_of_arrays(a, n);
    delete[]a;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
