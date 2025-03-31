#include <iostream>
using namespace std;
/*
	Hàm check mục đích để kiểm tra điều kiện phân chia mảng a thành days mảng con sao cho tổng của mỗi mảng con 
	không vượt quá capa
*/
bool check(int* a, int n, int days, int capa)
{
	int i = 0;// chỉ số của phần tử hiện tại trong mảng a
	int d = 1;// biến đếm số lượng mảng con 
	int sum = 0;// tổng các giá trị trong mảng con 
	while (i < n) // chạy từng phần tử trong mảng
	{
		if (sum+a[i] <= capa)
			/*
			kiểm tra nếu tổng các giá trị trong mảng con cộng với giá trị a[i] còn nhỏ hơn hoặc bằng capa
			thì cộng a[i] vào sum cho đến khi nó lớn hơn capa thì không cộng nữa, lúc này sum=0 và cộng các phần 
			tử trong mảng con mới và tăng biến đếm số lượng mảng con d lên 1 đơn vị
			*/
		{
			sum = sum + a[i];
			i++;
		}
		else
		{
			sum = 0;
			d++;
		}
		if (d > days) return false;// kiểm tra nếu biến đếm số mảng con d mà lớn hơn số mảng con cần chia là days thì trả về false
	}
	return true;// nếu biến đếm số mảng con d nhỏ hơn hoặc bằng số mảng con cần chia là days thì trả về true
}
/*
	Hàm min_ship để tìm ra tải trọng nhỏ nhất cần thiết để vận chuyển tất cả phần tử của mảng a trong tối đa days ngày 
	left là giá trị nhỏ nhất trong mảng a, vì mỗi chuyến vận chuyển ít nhất số tải trọng của hàng hóa
	right là tổng tất cả giá trị trong mảng a
	mid là giá trị trung bình của left và right
	Sau đó gọi hàm check để kiểm tra với tải trọng là mid thì có thể chia mảng thành days nhóm mà tổng mỗi nhóm không vượt 
	quá mid hay ko, nếu check đúng thì ta tìm xem còn giá trị nào nhỏ hơn mid mà vẫn thỏa điuề kiện không, còn nếu check sai 
	thì tải trọng mid quá nhỏ nên ta tăng left=mid+1.
	cho đến khi vòng lặp kết thúc thì giá trị left là tải trọng nhỏ nhất cần tìm
*/
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