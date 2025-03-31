// ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*
    Lưu giá trị cuối cùng của mảng vào biến last, sau đó gán giá trị cuối cùng của mảng bằng giá trị cần tìm
    Sau đó lặp qua mảng từ đầu cho đến khi tìm thấy giá trị cần tìm
    Sau đó gán lại giá trị cuối cùng của mảng 
    Kiểm tra nếu i < n-1 nghĩa là tìm thấy K trong mảng, và kiểm tra phần tử cuối cùng của mảng có bằng K không, 
    nếu có trả về i, nếu không có thì trả về -1;
*/
int Linear_Search_with_Sentinel(int* a, int n, int K)
{
    int last = a[n - 1];
    a[n - 1] = K;
    int i = 0;
    while (a[i] != K)
    {
        i++;
    }
    a[n - 1] = last;
    if (i < n - 1 || a[n - 1] == K) return i;
    return -1;
}
int main()
{
    int n, K;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> K;
    int idx = Linear_Search_with_Sentinel(a, n, K);
    cout << idx;
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
