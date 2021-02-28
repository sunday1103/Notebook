#include <algorithm> // sort
#include <functional>
#include <iostream> // cout
#include <vector>   // vector

using namespace std;

struct element {
    int data;
    string name;
};

vector<element> g_vector;

bool myfunction(const element &i, const element &j) { return (i.data < j.data); }

struct myclass {
    bool operator()(element &i, element &j) { return (i.data < j.data); }
} myobject;

void InitData() {
    g_vector.clear();
    g_vector.push_back({32, "strsd"});
    g_vector.push_back({71, "str1"});
    g_vector.push_back({71, "str2"});
    g_vector.push_back({71, "str3"});
    g_vector.push_back({26, "str26"});
    g_vector.push_back({80, "str80"});
    g_vector.push_back({53, "str53"});
    g_vector.push_back({33, "str33"});
}

void PrintData() {
    for (auto &i : g_vector) {
        cout << i.data << "-" << i.name;
        cout << " | ";
    }
    cout << endl;
}

void UseSort() {
    cout << "各种排序算法" << endl;
    PrintData();
    sort(g_vector.begin(), g_vector.end(), myfunction);
    PrintData();

    InitData();
    stable_sort(g_vector.begin(), g_vector.end(), myfunction);
    PrintData();

    InitData();
    sort(g_vector.begin(), g_vector.end(), myobject);
    PrintData();

    cout << "部分排序" << endl;
    InitData();
    partial_sort(g_vector.begin(), g_vector.begin() + 3, g_vector.end(), myfunction);
    PrintData();

    cout << "nth elment" << endl;
    InitData();
    nth_element(g_vector.begin(), g_vector.begin(), g_vector.end(), myfunction);
    cout << g_vector[0].data << " " << g_vector[0].name << endl;
    InitData();
    nth_element(g_vector.begin(), g_vector.begin() + 2, g_vector.end(), myfunction);
    cout << g_vector[2].data << " " << g_vector[2].name << endl;
    PrintData();
}

int main() {
    InitData();
    UseSort();
    return 0;
}