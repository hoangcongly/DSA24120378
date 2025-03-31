#include <iostream>
#include <vector>
using namespace std;
// Hàm Quick_Sort dùng để sắp xếp mảng 
void Quick_Sort(vector<int>& nums, int left, int right)
{
	if (left >= right) return;
	int pivot = nums[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (nums[j] <= pivot)
		{
			i++;
			int temp = nums[i];  
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	int temp = nums[i + 1];
	nums[i + 1] = nums[right];
	nums[right] = temp;
	int pivotIndex = i + 1;
	Quick_Sort(nums, left, pivotIndex - 1);
	Quick_Sort(nums, pivotIndex + 1, right);
}

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> result;
	Quick_Sort(nums, 0, nums.size() - 1);
	for (int i = 0; i < nums.size(); i++)// duyệt qua từng phần tử trong mảng, trong đó mỗi phần tử là số đầu tiên của bộ 3
	{
		if (i>0&& nums[i] == nums[i - 1]) continue;// kiểm tra trùng lặp, nếu trùng thì bỏ qua
		int left = i + 1;// khởi tạo left ngay sau i và right là phần tử cuối của mảng
		int right = nums.size() - 1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0)
			{
				result.push_back({ nums[i],nums[left],nums[right] });// nếu sum = 0 thì thêm bộ 3 đó vào result và bỏ qua các số trùng để tránh bộ 3 trùng lặp
				while (left < right && nums[left] == nums[left + 1]) left++;
				while (left < right && nums[right] == nums[right - 1]) right--;
				left++;// sau đó dịch chuyển 2 con trỏ
				right--;
			}
			else if (sum > 0)// nếu sum> 0 thì giảm right
			{
				right--;
			}
			else left++;// nếu sum<0 thì tăng left
		}
	}
	return result;
}
int main()
{
	vector<int> nums = {-5,4,-1,0,1,2,-1,-4 };
	vector<vector<int>> result = threeSum(nums);

	cout << "Cac bo ba co tong bang 0:\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
	}

	return 0;
}