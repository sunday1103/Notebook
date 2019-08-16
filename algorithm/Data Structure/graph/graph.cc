#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

ostream &operator<<(ostream &o, std::vector<int> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        o << v[i] << "\t";
    }
    return o;
}

ostream &operator<<(ostream &o, std::vector<char> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        o << v[i] << "\t";
    }
    return o;
}

void do_something(int v) { cout << v << " "; }

class Graph
{
  private:
    vector<list<int> > adj;
    int V;
    int E;

  public:
    Graph(); // empty graph
    Graph(istream &is);
    void print(int type = 0);
    int degree(int v);
    int maxDegree();
    int get_V() { return V; }
    int get_E() { return E; }

    //-----------------dfs
  public:
    void dfs(int v, void (*f)(int));

  private:
    std::vector<char> mark;
    //----------------------
  public:
    void bfs(int v, void (*f)(int));

  private:
    std::vector<int> edge_to;

  public:
    vector<int> path_to(int s, int v);
};

Graph::Graph()
{
    V = 0;
    E = 0;
}

Graph::Graph(istream &is)
{
    cout << "Input Vertices number:\n";
    is >> V;
    adj.resize(V);
    cout << "Input Edges number:\n";
    is >> E;
    cout << "Edge ?: Vertice ? --> Vertice ?\n";
    for (int i = 0; i < E; ++i)
    {
        int a, b;
        is >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "Graph has been build.\n";

    mark.resize(V, 0);
    edge_to.resize(V, 0);
}

void Graph::print(int type)
{
    if (type == 0)
    {
        for (int i = 0; i < V; ++i)
        {
            cout << i << ":\t";
            for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++)
            {
                cout << *it << "->";
            }
            cout << "end" << endl;
        }
    }
}

void Graph::dfs(int v, void (*f)(int))
{
    f(v);
    mark[v] = 1;
    for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++)
    {
        if (!mark[*it])
        {
            edge_to[*it] = v;
            dfs(*it, f);
        }
    }
}

vector<int> Graph::path_to(int s, int v)
{
    std::vector<int> myv;
    int n = v;
    while (n != s)
    {
        myv.push_back(n);
        n = edge_to[n];
    }
    myv.push_back(s);

    reverse(myv.begin(), myv.end());
    return myv;
}

void Graph::bfs(int v, void (*f)(int))
{
    queue<int> q;
    q.push(v);

    std::vector<char> mark1;
    mark1.resize(V, 0);
    mark1[v] = 1;

    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        f(a);
        for (list<int>::iterator it = adj[a].begin(); it != adj[a].end(); it++)
        {
            if (!mark1[*it])
            {
                edge_to[*it] = a;
                mark1[*it] = 1;
                q.push(*it);
            }
        }
    }
}

int main()
{
    Graph G(cin);
    G.print();
    G.bfs(0, do_something);
    cout << endl;
    for (int i = 0; i < G.get_V(); ++i)
    {
        cout << "0 -> " << i << ": " << G.path_to(0, i) << endl;
    }
    G.bfs(0, do_something);
    cout << endl;
}
