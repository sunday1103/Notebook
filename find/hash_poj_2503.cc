/*using C++11 below

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    int flag = 1;
    unordered_map<string, string> um;
    while (getline(cin, s))
    {
        string s1, s2;
        istringstream is(s);
        if (!(is >> s1))
        {
            if (flag)
            {
                flag = 0;
                continue;
            }
            else
            {
                break;
            }
        }

        if (flag)
        {
            is >> s2;
            um[s2] = s1;
        }
        else
        {
            if (um.find(s1) != um.end())
                cout << um[s1] << endl;
            else
                cout << "eh" << endl;
        }
    }
}

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    string key;
    string value;
    node *pre;
    node *next;
    node(string s1, string s2) : key(s1), value(s2), pre(NULL), next(NULL) {}
};

// string hash
class hash
{
  private:
    int n;
    vector<list<node> *> v;

  public:
    hash(int n_) : n(n_) { v.resize(n, NULL); }
    int hash_v(const string &s);
    void put(const string &s1, const string &s2);
    string get(const string &s);
    void my_delete(const string &s);
};

int hash::hash_v(const string &s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        sum += s[i] - '\0';
    }
    return sum % n;
}

void hash::put(const string &s1, const string &s2)
{
    int a = hash_v(s1);
    if (v[a] == NULL)
    {
        v[a] = new list<node>;
    }

    v[a]->push_back(node(s1, s2));
    //cout << "in put method " << v[a]->size() << endl;
}

string hash::get(const string &s)
{
    int a = hash_v(s);
    string s_value;
    if (v[a] == NULL)
    {
        return s_value;
    }
    else
    {
        for (list<node>::iterator it = v[a]->begin(); it != v[a]->end(); it++)
        {
            if ((*it).key == s)
                return (*it).value;
        }
        return s_value;
    }
}

int main()
{
    string s;
    int flag = 1;
    hash hs(997);
    while (getline(cin, s))
    {
        string s1, s2;
        istringstream is(s);
        if (!(is >> s1))
        {
            if (flag)
            {
                flag = 0;
                continue;
            }
            else
            {
                break;
            }
        }

        if (flag)
        {
            is >> s2;
            hs.put(s2, s1);
            // um[s2] = s1;
        }
        else
        {
            if (hs.get(s1).length() != 0)
                cout << hs.get(s1) << endl;
            else
                cout << "eh" << endl;
        }
    }
}

#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
const int MAX_WORD_LEN = 10;
int main()
{
    char line[MAX_WORD_LEN * 2 + 1];
    char s1[MAX_WORD_LEN + 1], s2[MAX_WORD_LEN + 1];
    map<string, string> dict;
    while (gets(line) && line[0] != 0)
    {
        sscanf(line, "%s %s", s1, s2);
        dict[s2] = s1;
    }
    while (gets(line))
    {
        if (dict[line].length() == 0)
            puts("eh");
        else
            printf("%s\n", dict[line].c_str());
    }
    return 0;
}