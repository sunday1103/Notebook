#include <iostream>
#include <sstream>
#include <string>

#define MAXLEN 100

using namespace std;

class bigInt
{
  public:
    int data[MAXLEN / 4 + 1];
    bigInt();
    bigInt(string s);
	bigInt(const bigInt &b);
	bigInt & operator=(const bigInt &b);
};

bigInt::bigInt(const bigInt &b)
{
	for (int i = 0; i < MAXLEN / 4 + 1; i++)
    {
        data[i] = b.data[i];
    }
	cout<<"copy constructor is invoked"<<endl;
}

bigInt & bigInt::operator=(const bigInt &b)
{
	if(this == &b)
	{
		return *this;
	}
	for (int i = 0; i < MAXLEN / 4 + 1; i++)
    {
        data[i] = b.data[i];
    }
	cout<<"copy = is invoked"<<endl;
	return *this;
}

bigInt::bigInt(string s)
{
    for (int i = 0; i < MAXLEN / 4 + 1; i++)
    {
        data[i] = 0;
    }
    int k = 0;
    for (int i = s.length() - 1; i >= 0; i -= 4)
    {
        int high = i - 3 > 0 ? i - 3 : 0;
        int low = i;
		for(int j = high; j <= low; j++)
		{
			data[k] = data[k] * 10 + s[j] - '0';
		}
		//cout<<data[k]<<" - ";
        k++;
    }
	//cout<<endl;
}

bigInt::bigInt()
{
    for (int i = 0; i < MAXLEN / 4 + 1; i++)
    {
        data[i] = 0;
    }
}

bigInt operator+(bigInt &x, bigInt &y)
{
    bigInt z;
    int cc = 0;
    for (int i = 0; i < MAXLEN / 4; i++)
    {
        cc = x.data[i] + y.data[i] + z.data[i];
        z.data[i] = cc % 10000;
        z.data[i + 1] = cc / 10000;
    }
    cc = x.data[MAXLEN / 4] + y.data[MAXLEN / 4] + z.data[MAXLEN / 4];
    z.data[MAXLEN / 4] = cc % 10000;
    if (cc / 10000)
        std::cerr << "overflow !!" << std::endl;
    return z;
}

ostream &operator<<(ostream &o, bigInt &b)
{
    int flag = 0;
    for (int i = MAXLEN / 4; i >= 0; i--)
    {
        if (flag == 0 && b.data[i] != 0)
            flag = 1;
        if (flag == 1)
        {
<<<<<<< HEAD
            o << b.data[i] / 1000 << (b.data[i] % 1000) / 100 << (b.data[i] % 100) / 10 << (b.data[i] % 10) / 1;
=======
            o << b.data[i];
>>>>>>> 91349356403eb4487ab1ffd4e757b87dd06e74b3
        }
    }
	if(flag == 0)
		o<<0;
	return o;
}

int main()
{
    string a, b;
    cin >> a >> b;
    bigInt x(a), y(b);
<<<<<<< HEAD
    cout <<"x------------"<< x << endl;
    cout<<"+"<<endl;
    cout <<"y------------"<< y << endl;
    cout<<"="<<endl;
    bigInt z = x + y;
    cout <<"z------------" <<z << endl;
=======
    cout << x << endl;
    cout << y << endl;
    bigInt z = x + y;
    cout << z << endl;
>>>>>>> 91349356403eb4487ab1ffd4e757b87dd06e74b3
	bigInt d;
	cout<<d<<endl;
	
	bigInt e(x);
	cout<<e<<endl;
	
	bigInt f = x;
	cout<<f<<endl;
	
	f = y;
	cout<<f<<endl;
}
