#include <vector>
#include <iostream>

using namespace std;
int main()
{
	int a[2] = {1,2};
	cout<<a[3]<<endl;
	vector<int> b;
	b.push_back(1);
	cout<<b[10]<<endl;
	b.at(12);
}