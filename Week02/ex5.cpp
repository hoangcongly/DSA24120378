#include <iostream>
using namespace std;


int minLengOfArray(int* a, int n, int target)
{

	// 2 3 1 2 4 3, target = 7
	int i = 0;
	int sum = 0;
	int minlen = n+1;
	for (int j = 0; j < n; j++)
	{
		sum = sum + a[j];
		while (sum >= target)
		{
			if (minlen > (j - i + 1)) minlen = j - i + 1;
			sum = sum - a[i];
			i++;
		}
	}
	return minlen;
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
	cout << minLengOfArray(a, n, target);
}