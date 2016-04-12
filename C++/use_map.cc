#include <map>
#include <iostream>

using namespace std;
class data
{
	public:
	data(int a)
	{
		x = a;
	}
	data(){};
	int x;
};

class dataD: public data
{
	int x;
};

int main()
{
	
	std::map<int, data> m;
	m[1] = data(1);
	cout<<"222222"<<endl;
}