#include <iostream>

using namespace std;

/* 1. 第一种单例模式  -  饿汉模式
- 将构造函数设置为private，以避免创建调用构造函数
- 提供一个返回唯一实例的函数，get()，该函数在中判断是否创建了实例，
	如果创建了，就返回该实例，如果没有，则创建实例。
- 这种单例模式线程不安全
	在判断是否创建的位置，有可能多个线程同时判为真
*/
class singleton
{
  private:
    static singleton *p;
    singleton()
    {
        data = 1;
    }
    singleton(singleton &);
    ~singleton();

  public:
    int data;

  public:
    static singleton &get()
    {
        if (p == NULL)
        {
            p = new singleton;
        }
        return *p;
    }
};
singleton *singleton::p = 0;

/* 第二种单例模式   -   双重检锁
- Lazy Singleton的一种线程安全改造是在Instance()中每次判断是否为NULL前加锁，但是加锁是很慢的。 
而实际上只有第一次实例创建的时候才需要加锁。
既然只需要在第一次初始化的时候加锁，那么在这之前判断一下实例有没有被创建就可以了，所以多在加锁之前多加一层判断，需要判断两次所有叫Double-Checked。

- 问题：
instance = new Singleton()；这句话并不是原子的，其实包含了3个操作.因此JIT进行指令重排的时候就有可能出现返回了地址给instance(非null)但是却还没有调用构造方法完成对象的初始化，其他线程这时抢占后依然会返回instance，然后执行操作就会报错。
	
*/
class singleton2
{
  private:
    static singleton2 *instance_;
    singleton2()
    {
        data = 1;
    }
    singleton2(singleton2 &);
    ~singleton2();

  public:
    int data;

  public:
    static singleton2 &Instance()
    {
        if (instance_ == NULL)
        {
            Lock lock; //基于作用域的加锁，超出作用域，自动调用析构函数解锁
            if (instance_ == NULL)
            {
                instance_ = new singleton2;
            }
        }
        return *instance_;
    }
};
singleton2 *singleton2::instance_ = 0;

/* 第三种单例模式  -  饱汉模式
- 在执行main之前就创建对象的实例，在上面方法中也是创建了一个东西，不是实例而是执行实例的指针。
- 问题在于，non-local static对象的创建先后问题，effective c++ item 4
- 注意，声明和定义的区别
*/
class Singleton1
{
  public:
    static Singleton1 &Instance()
    {
        return instance;
    }
    int data;

  private:
    Singleton1()
    {
        data = 11;
    }
    ~Singleton1()
    {
    }
    Singleton1(const Singleton1 &);
    Singleton1 &operator=(const Singleton1 &);

  private:
    static Singleton1 instance;
};
Singleton1 Singleton1::instance;

/* 第四种单例模式  -  Meyers Singleton
	C++0x之后是该实现线程安全的，有兴趣可以读相关的标准草案（section 6.7）编译器支持程度不一定,但是G++4.0及以上是支持的。
*/

class Singleton3  
{
    public:
    static Singleton3& Instance()
    {
        static Singleton3 instance;
        return instance;
    }
    private:
        Singleton3();
        ~Singleton3();
        Singleton3(const Singleton3&);
        Singleton3& operator=(const Singleton3&);
};

/* 第五种单例模式  -  利用pthread_once
*/

template<typename T>  
class Singleton : boost::noncopyable  
{
    public:
        static T& instance()
        {
            pthread_once(&ponce_, &Singleton::init);
            return *value_;
        }

        static void init()
        {
            value_ = new T();
        }
    private:
        static pthread_once_t ponce_;
       static T* value_;
};
template<typename T>  
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>  
T* Singleton<T>::value_ = NULL;  

 
int main()
{
    int &a = (singleton::get()).data;
    cout << a << endl;

    a = 9;
    cout << a << endl;
	
	int &b = (Singleton1::Instance()).data;
	cout << b << endl;

    b = 99;
    cout << b << endl;
}