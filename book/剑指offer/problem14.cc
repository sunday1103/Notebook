#include <algorithm>

// using stable_sort
/* 
bool myf(int a, int b)
{
    if ((a % 2 == 0 && b % 2 == 0) || (a % 2 == 1 && b % 2 == 1))
    {
        return 0;
    }

    if (a % 2 == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
    	stable_sort(array.begin(),array.end(),myf);
    }
};

*/

//using stable_partition

/*
bool myf(int a)
{
	if (a % 2 == 1)
	{
		return 1;
	}

	return 0;
}

class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
    	stable_partition(array.begin(),array.end(),myf);
    }
};
*/

// using insert sort method

bool is_odd(int a)
{
    return a % 2 == 1 ? 1 : 0;
}

class Solution
{
  public:
    void reOrderArray(vector<int> &array)
    {
        int mid = 0;
        for (int i = 0; i < array.size(); ++i)
        {
            if (is_odd(array[i]))
            {
                int tt = array[i];
                for (int j = i; j > mid; j--)
                {
                    array[j] = array[j - 1];
                }
                array[mid] = tt;
                mid++;
            }
        }
    }
};
