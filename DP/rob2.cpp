
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = {10,12,1,4,15,1,47,22,45,1,6,4,5,1,4,15,74,75,12};
	int N = nums.size();
	if(N == 0)
	{
		return 0;
	}
	int sum_1 = nums[0];
	int sum_2 = sum_1;
	if(N == 1)
	{
		return nums[0];
	}
	if(nums[1] < nums[0])
	{
		sum_2 = nums[1];
	}
	
	if(N == 2)
	{
		return sum_2;
	}
	
	for(int i = 2; i < N; i++)
	{
		if(sum_1 < sum_2 + nums[i])
		{
			sum_1 = sum_2 + nums[i];
			sum_2 = sum_1;
		}
		else
		{
			sum_1 = sum_1;
			sum_2 = sum_1;
		}
	}
	return sum_1;
	
}