# Insert sort
插入排序是将未排序的数插入到已经排好序的序列中。
版本三相对于版本1,2优点在于,对于每个未排序的数，该数仅仅需要移动到最终位置，而不需要挨个移动。
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

# Binary_insert_sort
二分插入排序在于，从上面版本三可以看到，如果找到已经排序的数中小于目标数的位置，那么只需要将该位置以及该位置以后的数
向后移动一个，然后将目标数放到该位置就好了。而找到该位置之前是一个一个比较的，现在通过二分查找的方法可以减少查找次数。

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
# 选择排序
选择排序是指在待排序序列中选择最小的数放于已排序序列最后，重复这个过程。

# 希尔排序
希尔排序将序列间隔一定值分为多个子序列，对每个子序列排序。
然后减小间隔值，继续该过程，直到间隔为1.
