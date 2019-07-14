#include <iostream>
#include <cstring>

using namespace std;

class my_string
{
public:
	my_string(char *);
	my_string();
	my_string(const my_string & s);
	my_string & operator=(const my_string & rhs);
	~my_string();
	void swap(my_string &ss);
public:
	char *s;
	int length;
};

ostream & operator<<(ostream &o, my_string &s)
{
	cout<<s.s<<endl;
}

my_string::my_string(char *cp)
{
	if(cp == NULL)
	{
		length = 0;
		s = new char[1];
		*s = '\0';
		return;
	}
	length = strlen(cp) + 1;
	s = new char[length];
	strcpy(s,cp);
	cout<<"construct over! length = "<<length<<"  "<<s<<endl;
}

my_string::my_string()
{
	length = 1;
	s = new char[1];
	*s = '\0';	
	cout<<"construct over! (length = 0) "<<s<<endl;
}

my_string::my_string(const my_string & ms)
{
	s = new char[ms.length];
	length = ms.length;
	strcpy(s,ms.s);
	cout<<"copy construct over! length = "<<length<<"  "<<s<<endl;
}

my_string & my_string::operator=(const my_string & rhs)
{
	my_string tmp(rhs);
	swap(tmp);
	cout<<"= construct over! length = "<<length<<"  "<<s<<endl;
	return *this;
}

void my_string::swap(my_string &ss)
{
	std::swap(s,ss.s);
}


my_string::~my_string()
{
	delete []s;
}

int main()
{
	my_string mys;
	char s[] = "this";
	cout<<s<<endl;
	my_string ss(s);
	cout<<ss<<endl;
	
	my_string ss1(ss);
	cout<<ss1<<endl;
	
	my_string ss2;
	ss2 = ss1;
	cout<<ss2<<endl;
	
	char s1[10];
	cin >> s1;
	my_string ss3(s1);
	cout<<ss3<<endl;
}