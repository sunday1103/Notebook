#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int minSubArrayLen0(int target, vector<int>& nums) {
        int minLen = -1;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            int len = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum >= target) {
                    len = j - i + 1;
                    break;
                }
            }

            if (len == 0) {
                break;
            }

            if (minLen == -1 || minLen > len) {
                minLen = len;
            }
        }

        return minLen == -1 ? 0 : minLen;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size();
        int findFlag = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        for (; i < minLen; i++) {
            int j = 0;
            while (i < nums.size()) {
                sum += nums[j];
                if (sum >= target) {
                    
                }
            }
        }
    }
};


ostream & operator << (ostream &oso, vector<int> &v)
{
    for (int i = 0; i < v.size(); i++) {
        oso << v[i] << " ";
    }
    oso << endl;

    return oso;
}

int main()
{
    int a[] = {2,0,2,1,1,0};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    cout << v;
    Solution S;
    S.sortColors(v);
    cout << v;
}

/**
输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]
*/