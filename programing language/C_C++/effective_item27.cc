#include<iostream>
#include <stdio.h>
using namespace std;
class A
{
public:
	void ThisA()
	{
		printf("A: %p\n", this);
		printf("a: %p\n", &a);
	}
	int a;
};
class B : public A
{
public:
	virtual void ThisB()
	{
		printf("B: %p\n", this);
		printf("b: %p\n", &b);
	}
	int b;
};
int main()
{
	B b;
	B* pb = &b;
	pb->ThisA();
	pb->ThisB();
	A* pa = &b;
	printf("A: %p\n", pa);
	printf("B: %p\n", pb);
	return 0;
}