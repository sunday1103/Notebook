class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnNum;
        for (int i = 0; i < nums.size(); i++) {
            int target1 = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == target1) {
                    returnNum.push_back(i);
                    returnNum.push_back(j);
                    return returnNum;
                }
            }
        }

        return returnNum;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnNum;
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int gap = target - nums[i];
            if (m.count(gap) != 0 && m[gap] != i)
            {
                returnNum.push_back(i);
                returnNum.push_back(m[gap]);
                break;
            }
            
        }

        return returnNum;
    }
};