
#include <iostream>
using namespace std;
/* 
     vd 4 5 6 7 1 2 3
    hàm tìm giá trị nhỏ nhất trong mảng đã xoay n lần, sử dụng phương pháp tìm kiếm nhị phân
    trong mỗi bước ta so sánh giá trị tại mid và tại right, nếu a[mid]>a[right] thì giá trị nhỏ nhất nằm ở
    nửa mảng bên phải, còn nếu a[mid]<a[right] thì giá trị nhỏ nhất nằm ở nửa mảng bên trái hoặc là ở mid, vòng lặp 
    while chạy cho đến khi left=right thì lúc đó a[left] là nhỏ nhất
*/
int min_element_of_arrays(int* a, int n)
{
    int left = 0;// gán left là phần tử đầu tiên của mảng
    int right = n - 1;// right là phần tử cuối cùng của mảng
   
    while (left <= right)
    {
        int mid = left + (right - left) / 2; 
        if (a[mid] > a[right])// nếu a[mid] > a[right] thì gtnn nằm ở nửa bên phải nên dịch left = mid + 1
        {
            left = mid + 1;
        }
        else // ngược lại thì gtnn nằm ở phía bên trái hoặc là nằm ở mid nên dịch right=mid
        {
            right = mid;
        }
    }
    return a[left];
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

