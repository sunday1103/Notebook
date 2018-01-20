#include <iostream>
#include <map>
#include <set>

using namespace std;
class data
{
  public:
    data(int a)
    {
        x = a;
    }
    data(){};
    int x;
};

class dataD : public data
{
    int x;
};

int main()
{

    std::map<int, data> m;
    m[1] = data(1);

    int N;
    cin >> N;
    set<int> s;
    int aa;
    for (int i = 0; i < N; ++i)
    {
        cin >> aa;
        s.insert(aa);
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}