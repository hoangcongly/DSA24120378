// Ex5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isAscending(int a[], int n)// hàm kiểm tra mảng có sắp xếp tăng dần hay không
{
    if (n == 1 || n == 0) return true;// nếu mảng chỉ có 1 phần tử hoặc không còn phần tử nào thì mảng đã sắp xếp
    if (a[0] > a[1]) return false;// nếu phần từ đứng trước lớn hơn phần tử đứng sau thì mảng chưa sắp xếp tăng dần
    return isAscending(a + 1, n - 1);// kiểm tra tiếp phần còn lại của mảng
}
bool isDescending(int a[], int n)// hàm kiểm tra mảng có sắp xếp giảm dần hay không
{
    if (n == 1 || n == 0) return true;// nếu mảng chỉ có 1 phần tử hoặc không còn phần tử nào thì mảng đã sắp xếp 
    if (a[0] < a[1]) return false;// nếu phần từ đứng trước nhỏ hơn phần tử đứng sau thì mảng chưa sắp xếp giảm dần
    return isDescending(a + 1, n - 1);// kiểm tra tiếp phần còn lại của mảng
}
int main()
{
    int n;
    int a[100];
    cin >> n; 
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (isAscending(a, n)) cout << "Mang da duoc sap xep tang dan" << endl;
    else if (isDescending(a, n)) cout << "Mang da duoc sap xep giam dan" << endl;
    else cout << "Mang chua duoc sap xep" << endl;
    return 0;
}

