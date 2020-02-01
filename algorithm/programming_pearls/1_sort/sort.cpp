#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <bitset>
#include <cstdlib>

using namespace std;

class mySort {
private:
    static constexpr int bitmapSize = 200;
    static constexpr int intNum = 20;
    vector<int> fullData;
public:
    // data i/o
    void readFullData();
    void readFullData(ifstream &in);
    void outputData();
    void outputData(ofstream &o);

    void generateDataByShuffle();
    // sort
    void sortDataUsingSysSort();
    void sortDataUsingSet();
    void sortDataUsingBitmap();
};

void mySort::readFullData() {
    fullData.clear();
    ifstream infile("../../1_sort/int.txt");
    string s;
    while (getline(infile, s)) {
        istringstream iss(s);
        int tmp;
        while (iss >> tmp) {
            fullData.push_back(tmp);
        }
    }
}

void mySort::readFullData(ifstream &infile) {
    fullData.clear();
    string s;
    while (getline(infile, s)) {
        istringstream iss(s);
        int tmp;
        while (iss >> tmp) {
            fullData.push_back(tmp);
        }
    }
}

void mySort::outputData() {
    for (int i : fullData) {
        cout << i << " ";
    }
    cout << endl;
}

void mySort::outputData(ofstream &o) {
    for (auto i: fullData) {
        o << i << " ";
    }
    o << endl;
}

void mySort::sortDataUsingSysSort() {
    sort(fullData.begin(), fullData.end());
}

void mySort::sortDataUsingSet() {
    set<int> s;
    for (int i: fullData) {
        s.insert(i);
    }

    fullData.clear();
    for (auto i: s) {
        fullData.push_back(i);
    }
}

void mySort::sortDataUsingBitmap() {
    bitset<bitmapSize> bitmap;
    bitmap.reset();
    for (auto i: fullData) {
        bitmap.set(i);
    }

    fullData.clear();
    for (int j = 0; j < bitmap.size(); ++j) {
        if (bitmap.test(j)) {
            fullData.push_back(j);
        }
    }
}

void mySort::generateDataByShuffle() {
    vector<int> v;
    v.reserve(bitmapSize);
    for (int i = 0; i < bitmapSize; ++i) {
        v.push_back(i);
    }

    for (int j = bitmapSize - 1; j > 0; --j) {
        int r = rand() % j;
        int tmp = v[r];
        v[r] = v[j];
        v[j] = tmp;
    }

    fullData.clear();
    for (int k = 0; k < bitmapSize; ++k) {
        fullData.push_back(v[k]);
    }
}

int main() {
    mySort sortInst;

    // 使用sort进行排序
    sortInst.readFullData();
    sortInst.outputData();
    sortInst.sortDataUsingSysSort();
    sortInst.outputData();

    // 使用set进行排序
    sortInst.readFullData();
    sortInst.sortDataUsingSet();
    sortInst.outputData();

    // 使用bitmap排序
    sortInst.readFullData();
    sortInst.sortDataUsingBitmap();
    sortInst.outputData();

    // 使用shuffle生成随机数
    if (0) {
        sortInst.generateDataByShuffle();
        ofstream o("../rand.txt");
        sortInst.outputData(o);
        sortInst.sortDataUsingBitmap();
        ofstream o1("../randok.txt");
        sortInst.outputData(o1);
    }
}