class Solution {
 public:
  int minNumberInRotateArray(vector<int> rotateArray) {
    int n = rotateArray.size();
    int begin = 0;
    int end = n - 1;
    int mid = 0;
    while (begin != end && begin + 1 != end) {
      mid = (begin + end) / 2;
      if (rotateArray[mid] >= rotateArray[begin])
        begin = mid;
      else
        end = mid;
    }
    if (begin == end)
      return rotateArray[begin];
    else
      return rotateArray[begin] > rotateArray[begin + 1]
                 ? rotateArray[begin + 1]
                 : rotateArray[begin];
  }
};