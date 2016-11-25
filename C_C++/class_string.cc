#include <iostream>

using namespace std;

class my_string
{
public:
	my_string(char *);
	my_string();
	my_string(const my_string & s);
	my_string & operator=(const my_string & rhs);
	~my_string();
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
	char *t = cp;
	length = 0;
	while(*t++ != '\0')
		length++;
	length++;
	s = new char[length];
	t = s;
	while(*cp != '\0')
		*t++ = *cp++;
	*t = '\0';
	cout<<"construct over! length = "<<length<<"  "<<s<<endl;
}

my_string::my_string()
{
	length = 0;
	s = new char[1];
	*s = '\0';	
	cout<<"construct over! (length = 0) "<<s<<endl;
}

my_string::my_string(const my_string & ms)
{
	s = new char[ms.length];
	length = ms.length;
	char *t = s;
	char *cp = ms.s;
	while(*cp != '\0')
		*t++ = *cp++;
	*t = '\0';
	cout<<"copy construct over! length = "<<length<<"  "<<s<<endl;
}

my_string & my_string::operator=(const my_string & rhs)
{
	if(&rhs == this)
	{
		return *this;
	}
	char *ss = new char[rhs.length];
	delete []s;
	s = ss;
	length = rhs.length;
	char *t = s;
	char *cp = rhs.s;
	while(*cp != '\0')
		*t++ = *cp++;
	*t = '\0';
	cout<<"= construct over! length = "<<length<<"  "<<s<<endl;
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
	
	my_string ss3("use convert");
	cout<<ss3<<endl;
}