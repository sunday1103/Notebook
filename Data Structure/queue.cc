#include <iostream>
#include <deque>
#include <string>

using namespace std;

class my_queue
{
public:
	bool push_back(int a);
	bool push_front(int a);
	int pop_back();
	int pop_front();
	int front();
	int back();
	int size();
	int capacity();

private:
	int *a;
};

int main()
{
	cout << "----------\n"
	     << "Queue Test\n"
	     << "----------\n"

	my_queue mq;

	string command;
	do
	{
		cin >> command;
		if (command == "ti")
		{
			int number;
			cin >> number;
			if(mq.push_back(number))
				cout<<"push_back "<<number<<" suecess"<<endl;
			else
				cout<<"push_back "<<number<<" fail"<<endl;
		}

		if (command == "hi")
		{
			int number;
			cin >> number;
			if(mq.push_front(number))
				cout<<"push_front "<<number<<" suecess"<<endl;
			else
				cout<<"push_front "<<number<<" fail"<<endl;
		}

		if (command == "to")
		{
			int number;
			number = mp.pop_back();
			cin >> number;
			if(mq.push_back(number))
				cout<<"push_back "<<number<<" suecess"<<endl;
			else
				cout<<"push_back "<<number<<" fail"<<endl;
		}

	}while(command != "q" || command != "Q");
}
