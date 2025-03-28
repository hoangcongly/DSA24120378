#include <iostream>
using namespace std;

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