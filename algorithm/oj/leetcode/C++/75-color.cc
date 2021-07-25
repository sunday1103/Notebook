#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void sortColors1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }

    void sortColors(vector<int>& nums) {
        int a[3] = {0};
        for (int i = 0; i < nums.size(); i++) {
            a[nums[i]] += 1;
        }

        int n = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < a[i]; j++) {
                nums[n] = i;
                n++;
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