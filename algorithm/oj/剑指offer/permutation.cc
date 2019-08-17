#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
/*using STL 
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};
*/

/*
对于一个排列的下一个排列：
例如 1 3 4 2，是1 4 2 3
例如 1 3 2，是2 1 3

步骤是：
1. 寻找从后往前，寻找第一个非递增数字，也就是 1 2 6 8 7 5 3 2 1中的6，
2. 然后再6 后面的部分寻找比6大的数字，交换：1 2 7 8 6 5 3 2 1
3. 然后将 之前6的位置后面的数逆序：1 2 7| 8 6 5 3 2 1 --> 1 2 7| 1 2 3 5 6 8
*/

class Solution
{
  public:
    bool nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 1;
        int sorted = 1;
        for (; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                //swap(nums[i],nums[i - 1]);
                sorted = 0;
                break;
            }
        }
        if (sorted)
        {
            sort(nums.begin(), nums.end());
            return 0;
        }

        for (int j = n - 1; j >= i; j--)
        {
            if (nums[j] > nums[i - 1])
            {
                swap(nums[j], nums[i - 1]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
        //能保证之前是正序
        return 1;
    }
};

int main()
{
    int N;
    cin >> N;
    std::vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
    }
    Solution S;
    int mm = 1;
    do
    {
    	cout<<mm++<<":\t";
        for (int i = 0; i < N; ++i)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    } while (S.nextPermutation(v));
}