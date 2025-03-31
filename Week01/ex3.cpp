// Generate_All_Binary_Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void generateBinaryStrings(int n, string str)
{
    if (str.length() == n)// nếu độ dài của chuỗi dài n thì in ra và kết thúc
    {
        cout << str << endl;
        return;
    }
    generateBinaryStrings(n, str + "0");// thêm số 0 vào chuỗi hiện tại và tiếp tục sinh chuỗi mới
    generateBinaryStrings(n, str + "1");// thêm số 1 vào chuỗi hiện tại và tiếp tục sinh chuỗi mới
}
int main()
{
    int n;
    cin >> n; 
    generateBinaryStrings(n, "");
    return 0;
}

