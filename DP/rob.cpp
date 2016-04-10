
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums;// = {10,12,1,4,15,1,47,22,45,1,6,4,5,1,4,15,74,75,12};
	nums.push_back(10);
	nums.push_back(12);
	nums.push_back(11);
	nums.push_back(120);
	nums.push_back(29);
	nums.push_back(9);
	nums.push_back(10);
	int N = nums.size();
	if(N == 0)
	{
		return 0;
	}
	vector<int> Sums;
	Sums.resize(N);
	Sums[0] = nums[0];
	//状态：
	//i个房屋抢劫的最大值
	//以第i个数结尾的或者以第i个数前一个结尾的抢劫的最大值
	//转移： sums[i] = max{sums[i-1], sums[i-2] + nums[i]}
	if(N == 1)
	{
		return nums[0];
	}
	if(nums[1] < nums[0])
	{
		Sums[1] = nums[0];
	}
	else
	{
		Sums[1] = nums[1];
	}
	
	if(N == 2)
	{
		return Sums[1];
	}
	
	for(int i = 2; i < N; i++)
	{
		if( Sums[i-1] < Sums[i-2] + nums[i])
		{
			Sums[i] = Sums[i-2] + nums[i];
		}
		else
		{
			Sums[i] = Sums[i-1];
		}
	}
	return Sums[N-1];
	
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums; // = {10,12,1,4,15,1,47,22,45,1,6,4,5,1,4,15,74,75,12};
  nums.push_back(10);
  nums.push_back(12);
  nums.push_back(11);
  nums.push_back(120);
  nums.push_back(29);
  nums.push_back(9);
  nums.push_back(10);
  int N = nums.size();
  if (N == 0) {
    return 0;
  }
  vector<int> Sums;
  Sums.resize(N);
  Sums[0] = nums[0];
  //状态：
  // i个房屋抢劫的最大值
  //以第i个数结尾的或者以第i个数前一个结尾的抢劫的最大值
  //转移： sums[i] = max{sums[i-1], sums[i-2] + nums[i]}
  if (N == 1) {
    return nums[0];
  }
  if (nums[1] < nums[0]) {
    Sums[1] = nums[0];
  } else {
    Sums[1] = nums[1];
  }

  if (N == 2) {
    return Sums[1];
  }

  for (int i = 2; i < N; i++) {
    if (Sums[i - 1] < Sums[i - 2] + nums[i]) {
      Sums[i] = Sums[i - 2] + nums[i];
    } else {
      Sums[i] = Sums[i - 1];
    }
  }
  return Sums[N - 1];
}
