/*
#include <algorithm>

class Solution
{
  public:
    void push(int value)
    {
    	v.push_back(value);
    }
    void pop()
    {
    	v.erase(v.end()-1);
    }
    int top()
    {
    	if (v.empty())
    	{
    		;
    	}
    	return v.at(v.size()-1);
    }
    int min()
    {
    	return *(min_element(v.begin(), v.end()));
    }

  private:
  	int m;
  	std::vector<int> v;
};
*/

class Solution
{
  public:
    void push(int value)
    {
        st1.push(value);
        if (!st2.empty() && value > st2.top())
        {
            st2.push(st2.top());
        }
        else
        {
            st2.push(value);
        }
    }
    void pop()
    {
        st1.pop();
        st2.pop();
    }
    int top()
    {
        return st1.top();
    }
    int min()
    {
        return st2.top();
    }

  private:
    stack<int> st1;
    stack<int> st2;
};
