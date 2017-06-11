#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

const int INIT_QUEUE_CAPACITY = 10;

class my_queue
{
public:
	bool push_back(int a);
	bool push_front(int a);
	bool pop_back();
	bool pop_front();
	int front();
	int back();
	int size();
	int capacity();
	void resize(int length, int padding);
	void reserve(int length);
	void clear();
	void list();
	int find(int a);
	bool empty();
	bool full();

public:
	my_queue();
	~my_queue();
private:
	int *data;
	int capacity_length;
	int head;
	int tail;
};

my_queue::my_queue()
{
	data = new int[INIT_QUEUE_CAPACITY];
	capacity_length = INIT_QUEUE_CAPACITY;
	head = 0;
	tail = 0;
}

my_queue::~my_queue()
{
	delete []data;
}

bool my_queue::empty()
{
	return head == tail;
}

bool my_queue::full()
{
	return (tail + 1) % capacity_length == head;
}

void my_queue::resize(int length, int padding)
{
	int s = size();
	if(length <= s)
	{
		tail = (head + length) % capacity_length;
	}
	else
	{
		if( length >= capacity_length )
		{
			cout << "capacity is "<< capacity_length<<", resize length is "<<length <<". auto increase capacity -> 2*length"<<endl;
			reserve(2 * length);
		}
		while(size() < length)
		{
			push_back(padding);
		}
	}
	
}

void my_queue::reserve(int length)
{
	if(length <= size())
	{
		return; //do nothing
	}
		
	int *p = new int[length];
	int new_head = 0;
	int new_tail = 0;
	while(!empty())
	{
		int val = front();
		pop_front();
		p[new_tail] = val;
		new_tail++;
	}
	head = new_head;
	tail = new_tail;
	delete []data;
	data = p;
	capacity_length = length;
}

int my_queue::capacity()
{
	return capacity_length;
}

int my_queue::size()
{
	return (tail - head + capacity_length) % capacity_length;
}

bool my_queue::push_back(int a)
{
	if(full())
		return false;
	else
	{
		data[tail] = a;
		tail = (tail + 1) % capacity_length;
	}
	
	return true;
}

bool my_queue::push_front(int a)
{
	if(full())
		return false;
	else
	{
		data[(head - 1 + capacity_length) % capacity_length] = a;
		head = (head - 1 + capacity_length) % capacity_length;
	}
	
	return true;
}

bool my_queue::pop_back()
{
	if(empty())
		return false;
	else
	{
		tail = (tail - 1 + capacity_length) % capacity_length;
	}
	
	return true;
}

bool my_queue::pop_front()
{
	if(empty())
		return false;
	else
	{
		head = (head + 1) % capacity_length;
	}
	
	return true;
}

int my_queue::front()
{
	if(empty())
		cerr << "error: empty" <<endl;
	return data[head];
}

int my_queue::back()
{
	if(empty())
		cerr << "error: empty" <<endl;
	return data[(tail-1 + capacity_length) % capacity_length];
}

void my_queue::list()
{
	int head_temp = head;
	cout<<"HEAD->\t";
	while(head_temp != tail)
	{
		cout<<data[head_temp]<<"\t";
		head_temp = (head_temp + 1) % capacity_length;
	}
	cout<<"<-TAIL"<<endl;
}

void my_queue::clear()
{
	head = 0;
	tail = 0;
}

int my_queue::find(int a)
{
	int head_temp = head;
	while(head_temp != tail)
	{
		if (data[head_temp] == a)
			return head_temp - head;
		head_temp = (head_temp + 1) % capacity_length;
	}
	return -1;
}




void print_help()
{
	cout<<"Usage:"<<endl;
	cout << "1. ti 1 \t\t(insert number 1 to the tail of queue) \n"
		 << "2. hi 1 \t\t(insert number 1 to the head of queue) \n"
		 << "3. to   \t\t(get the element from the tail of queue) \n"
		 << "4. ho   \t\t(get the element from the head of queue) \n"
		 << "5. popt \t\t(pop the tail element) \n"
		 << "6. poph \t\t(pop the head element) \n"
		 << "7. s 1  \t\t(search element 1 in queue) \n"
		 << "8. size \t\t(return the length of queue) \n"
         << "9. capacity \t\t(return the capacity of queue) \n"
		 << "10. ls  \t\t(list all element of queue) \n"
		 << "11. clear \t\t(clear all element) \n"
		 << "12. resize 10 2\t\t(resize queue, reference to the API of STL deque) \n"
		 << "13. reserve 10\t\t(reserve, reference to the API of STL vector.reserve()) \n";
		 
	cout << "--------"<<endl;
}

void print_elment(deque<int> d)
{
	if(d.empty())
	{
		cout<<"(empty)";
	}
	
	while(!d.empty())
	{
		cout<<d.front()<<"\t";
		d.pop_front();
	}
	cout<<endl;
}



void test_STL_deque()
{
	cout << "----------\n"
	     << "STL deque Test\n"
	     << "----------\n";
	print_help();
	cout<<"Please input command, H/h for help\n";
	
	deque<int> mq;

	string command;
	do
	{
		cin >> command;
		
		if (command == "h" || command == "H")
		{
			print_help();
		}
		
		if (command == "ls")
		{
			print_elment(mq);
		}
		
		if (command == "clear")
		{
			mq.clear();
		}
		
		if (command == "ti")
		{
			int number;
			cin >> number;
			mq.push_back(number);
		}
		
		if (command == "hi")
		{
			int number;
			cin >> number;
			mq.push_front(number);
		}

		if (command == "to")
		{
			int number;
			number = mq.back();
			cout << "Get last element: "<<number<<endl;
		}
		
		if (command == "ho")
		{
			int number;
			number = mq.front();
			cout << "Get head element: "<<number<<endl;
		}
		
		if (command == "popt")
		{
			mq.pop_back();
		}
		
		if (command == "poph")
		{
			mq.pop_front();
		}
		
		if (command == "size")
		{
			cout<< "size is " << mq.size()<<endl;
		}
		
		if (command == "capacity")
		{
			// mq.shrink_to_fit(); // C++ 11
			cout<< "size is " << mq.max_size()<<endl;
		}
		
		if (command == "resize")
		{
			int length;
			int padding;
			cin >> length >> padding;
			mq.resize(length, padding);
		}
		
		if (command == "reserve")
		{
			int length;
			cin >> length;
			cout << "STL deque has no method of reserve" <<endl;
			// reserve use the API in STL vector reserve, http://www.cplusplus.com/reference/vector/vector/reserve/
		}
		
		if (command == "s")
		{
			int val;
			cin >> val;
			deque<int>::iterator it = find(mq.begin(), mq.end(), val);
			//cout<< *mq.begin() << " " << *(mq.end() - 1)<<endl;
			if (it != mq.end())
			{
				cout << it - mq.begin() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}

	}while(command != "q" && command != "Q");
}



void test_my_queue()
{
	cout << "----------\n"
	     << "my_queue Test\n"
	     << "----------\n";
	print_help();
	cout<<"Please input command, H/h for help\n";
	
	my_queue mq;

	string command;
	do
	{
		cin >> command;
		
		if (command == "h" || command == "H")
		{
			print_help();
		}
		
		if (command == "ls")
		{
			mq.list();
		}
		
		if (command == "clear")
		{
			mq.clear();
		}
		
		if (command == "ti")
		{
			int number;
			cin >> number;
			bool b = mq.push_back(number);
			if(!b)
				cout << "push fail" <<endl;
			else
				cout << "push success"<<endl;
		}

		if (command == "hi")
		{
			int number;
			cin >> number;
			bool b = mq.push_front(number);
			if(!b)
				cout << "push fail" <<endl;
			else
				cout << "push success"<<endl;
		}
		
		if (command == "to")
		{
			int number;
			number = mq.back();
			cout << "Get tail element: "<<number<<endl;
		}
		
		if (command == "ho")
		{
			int number;
			number = mq.front();
			cout << "Get head element: "<<number<<endl;
		}
		
		if (command == "popt")
		{
			bool b = mq.pop_back();
			if(!b)
				cout << "pop fail" <<endl;
			else
				cout << "pop success"<<endl;
		}
		
		if (command == "poph")
		{
			bool b = mq.pop_front();
			if(!b)
				cout << "pop fail" <<endl;
			else
				cout << "pop success"<<endl;

		}
		
		if (command == "size")
		{
			cout<< "size is " << mq.size()<<endl;
		}
		
		if (command == "capacity")
		{
			cout<< "capacity is " << mq.capacity()<<endl;
		}
		
		if (command == "resize")
		{
			int length;
			int padding;
			cin >> length >> padding;
			mq.resize(length, padding);
		}
		
		if (command == "reserve")
		{
			int length;
			cin >> length;
			mq.reserve(length);
		}
		
		if (command == "s")
		{
			int val;
			cin >> val;
			cout<<mq.find(val)<<endl;
		}

	}while(command != "q" && command != "Q");
}

int main()
{
	test_my_queue();
	//test_STL_deque();
}
