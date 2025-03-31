// ex01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
/*
    Tìm kiếm tuyến tính: duyệt qua các phần tử trong mảng và so sánh từng giá trị với giá trị cần tìm
    sau đó trả về chỉ số của giá trị đó, nếu k tìm thấy thì trả về -1
*/
int LinearSearch(int a[], int n, int K)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == K) return i;
    }
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
    int idx=LinearSearch(a, n, K);
    cout << idx;
    delete[]a;
}

