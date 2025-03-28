#include <iostream>
#include <vector>
using namespace std;
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
	for (int i = 0; i < nums.size(); i++)
	{
		if (i>0&& nums[i] == nums[i - 1]) continue;
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right)
		{
			int sum = nums[i] + nums[left] + nums[right];
			if (sum == 0)
			{
				result.push_back({ nums[i],nums[left],nums[right] });
				while (left < right && nums[left] == nums[left + 1]) left++;
				while (left < right && nums[right] == nums[right - 1]) right--;
				left++;
				right--;
			}
			else if (sum > 0)
			{
				right--;
			}
			else left++;
		}
	}
	return result;
}
int main()
{
	vector<int> nums = { -1,0,1,2,-1,-4 };
	vector<vector<int>> result = threeSum(nums);
	for (const auto& triplet : result)
	{
		for (int num : triplet)
		{
			cout <<num << "\t";
		}
		cout << endl;
	}
}