#include <iostream>
using namespace std;

bool check(int* a, int n, int days, int capa)
{
	int i = 0;
	int d = 1;
	int sum = 0;
	while (i < n)
	{
		if (sum+a[i] <= capa)
		{
			sum = sum + a[i];
			i++;
		}
		else
		{
			sum = 0;
			d++;
		}
		if (d > days) return false;
	}
	return true;
}
int min_ship(int* a, int n, int days)
{
	int left = 0;
	int right = 0;
	for (int i = 0; i < n; i++)
	{
		if (left < a[i]) left = a[i];
		right = right + a[i];
	}
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (check(a, n, days, mid))
		{
			right = mid ;
		}
		else left = mid + 1;
	}
	return left;
}
int main()
{
	int n;
	int day;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> day;
	cout << min_ship(a, n, day) << endl;
	return 0;
}