#include <iostream>
using namespace std;
/*
	Hàm check_sum kiểm tra trong mảng đã sắp xếp có tồn tại 2 giá trị cộng lại bằng target hay không
	Vì mảng đã sắp xếp nên ta tính tổng của phần tử đầu và cuối mảng, nếu sum= target thì trả về true, 
	nếu sum > target thì giảm right, còn nếu sum<target thì ta tăng left, chạy cho đến khi left= right thì dừng
*/
bool check_sum(int* a, int n, int target)
{
	//  1 2 3 4 6, target=5
	int left = 0;
	int right = n - 1;
	int sum = 0;
	while (left < right)
	{
		sum = a[left] + a[right];
		if (sum == target) return true;
		if (sum > target)
		{
			right--;
		}
		else left++;
	}
	return false;
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
	int target;
	cin >> target;
	if (check_sum(a,n,target)) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}