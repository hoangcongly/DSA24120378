#include <iostream>
using namespace std;

/*
	Hàm minLengOfArray tìm độ dài nhỏ nhất của mảng con mà tổng các phần tử của mảng con đó lớn hơn hoặc bằng target
	Với i là chỉ số bắt đầu của mảng con và j là chỉ số kết thúc của mảng con
	Duyệt mảng bằng j và thêm a[j] vào tổng sum, khi sum>= target thì kiểm tra độ dài của mảng con là (j-i+1) có nhỏ hơn
	minlen hay không, nếu nhỏ hơn cập nhật minlen=j-i+1 sau đó loại bỏ phần tử a[i] ra khỏi sum và tăng i lên cho đến khi sum < target
	Hàm trả về minlen là độ dài nhỏ nhất của mảng con thỏa điều kiện, nếu minlen= n+1 thì không tồn tại mảng con thỏa đk
*/
int minLengOfArray(int* a, int n, int target)
{

	// 2 3 1 2 4 3, target = 7
	int i = 0;
	int sum = 0;
	int minlen = n+1;// khởi tạo minlen bằng n+1 đảm bảo mọi dãy con đều so sánh được với minlen
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