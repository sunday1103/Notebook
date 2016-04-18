# Insert sort

## Version 1
```cpp
void insert_sort(std::vector<int> &data, const int start, const int end)
{
    //int n = data.size();
    //bool ok = false;
    int j;
    for(int i = start + 1; i < end; i++)
    {
        for (j = i; j > start ; j--)
        {
        	if(data[j] < data[j-1])
        	{
        		int temp = data[j];
        	    data[j] = data[j-1];
        	    data[j] = temp;
        	}
        }
    }
}
```
For a 50000 randn vector:
```
[huangyang@eda-linux sort]$ ./sort < input.txt
input vector ended with a non-number:
start_time is 10000
end_time is 24140000
total 24130000
total 24130000  clock
total time 24.13  sec
```
## Version 2
```cpp
void insert_sort(std::vector<int> &data, const int start, const int end)
{
    //int n = data.size();
    //bool ok = false;
    int j;
    for(int i = start + 1; i < end; i++)
    {
        for (j = i; j > start && data[j] < data[j-1] ; j--)
        {
    		int temp = data[j];
    	    data[j] = data[j-1];
    	    data[j] = temp;
        }
    }
}
```
Running Time is
```
input vector ended with a non-number:
start_time is 10000
end_time is 17310000
total 17300000
total 17300000  clock
total time 17.3  sec
```


## Version 3
```cpp
void insert_sort(std::vector<int> &data, const int start, const int end)
{
    //int n = data.size();
    bool ok = false;
    int j;
    for(int i = start + 1; i < end; i++)
    {
        int temp = data[i];
        for (j = i; j > start && temp < data[j-1]; j--)
        {
            data[j] = data[j-1];
        }
        data[j] = temp;
    }
}
```
Running Time is:
```
input vector ended with a non-number:
start_time is 20000
end_time is 9320000
total 9300000
total 9300000  clock
total time 9.3  sec
```

Binary_insert_sort
---------
```c++
void binary_insert_sort(std::vector<int> &data, const int start, const int end)
{
    for(int i = start + 1; i < end; i++)
    {
        int temp = data[i];

        //find the position from [start,i-1] subject to data[pos] <= temp <= data[pos+1]
        int left = start;
        int right = i-1;
        int mid = right;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (temp < data[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        for (int m = i; m > left; m--)
        {
            data[m] = data[m-1];
        }

        data[left] = temp;
    }
}
```
