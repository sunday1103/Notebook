#include "string"
#include "iostream"

using namespace std;

class Sales_data
{
    /*
    1. 非成员函数内访问了private数据，需要是类的友元;
    2. 友元不是类的成员，不受访问说明符限制，可以放在任何位置；
    3. 友元的声明不是通常的函数声明，如果需要对外提供接口，必须单独进行声明。
    */
    friend istream &read(istream&, Sales_data&);
    friend ostream &print(ostream&, const Sales_data&);

public:
    /*
    1. = default 定义默认构造函数，C++11；
    2. 构造函数初始值列表；
    */
    Sales_data() = default;

    /*接收单参数的构造函数定义了转换构造函数*/
    Sales_data(const string &s): bookNo(s) {}
    Sales_data(const string &s, unsigned int n, double p):
               bookNo(s), units_sold(n), revenue(p*n) {}
    /*转换构造函数如果需要抑制隐式转换，加explicit关键字：
    1. 抑制隐式转换；
    2. 不能通过拷贝初始化，即只能够直接初始化。
    */
    explicit Sales_data(istream &);

    /*
    1. bookNo相当于this->bookNo，函数在调用的时候会隐式传入当前调用对象的指针到this；
    2. this指针是一个常量指针，相当于 Sales_data * const this
    3. 函数声明后加const表示这个this指针是一个指向常量的常量指针，不能通过this改变对象的值
       这个时候这个函数叫做常量成员函数。
    4. 常量对象及其指针和引用都只能调用常量成员函数。
    */
    string isbn() const { return bookNo;}
    /*
    1. 这个函数是模拟的 += 运算符，返回自身的引用，这样就可以链式调用
       比如：total.combine(trans).combine(trans1)
    */
    Sales_data & combine(const Sales_data&);

private:
    double avg_price() const;
    string bookNo;
    /*
    1. C++11可以定义类内初始值，改值用来初始化变量；
    2. C++11之前不能这样使用，只能针对static变量可以：
    warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
    */
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

double Sales_data::avg_price() const
{
    if (units_sold)
    {
        return revenue / units_sold;
    }
    else
    {
        return 0;
    }
}

Sales_data& Sales_data::combine(const Sales_data& rhs)
{
    revenue  += rhs.revenue;
    units_sold += rhs.units_sold;

    return *this;
}


istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main()
{
    Sales_data total(cin);
    print(cout, total) << endl;
}