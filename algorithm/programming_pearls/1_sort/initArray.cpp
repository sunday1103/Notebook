#include <iostream>

using namespace std;

#define MAX_NUM 10

class myArray {
private:
    int data[MAX_NUM];
    int from[MAX_NUM];
    int to[MAX_NUM];
    int top;

    bool valid(int loc);
public:
    explicit myArray(int top): top(top) {}
    int get(int loc);
    void set(int loc, int value);
    void print();
};

int myArray::get(int loc) {
    if (!valid(loc)) {
        set(loc, 0);
    }

    return data[loc];
}

bool myArray::valid(int loc) {
    if (from[loc] > top) {
        return false;
    }

    return to[from[loc]] == loc;
}

void myArray::set(int loc, int value) {
    data[loc] = value;
    from[loc] = top;
    to[top] = loc;
    top++;
}

void myArray::print() {
    cout << "=======begin=======" << endl;
    for (auto i: data) {
        cout << i << "\t";
    }
    cout << endl;

    for (auto i: from) {
        cout << i << "\t";
    }
    cout << endl;

    for (auto i: to) {
        cout << i << "\t";
    }
    cout << endl;

    cout << top << endl;
    cout << "=======end=======" << endl << endl;
}


int main() {
    myArray m(0);
    m.print();

    m.set(0,10);
    m.get(0);
    m.get(3);

    m.print();
}