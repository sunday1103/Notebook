
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void coin_problem(int N)
{
	cout << "N is " << N << endl;
	int coin[3] = { 1,3,5 };
	vector<int> Min;
	map<int, vector<int> > what;
	for (int i = 0; i <= N; i++)
	{
		Min.push_back(10000);
	}
	Min[0] = 0;
	what[0];
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (coin[j] <= i)
			{
				if (Min[i - coin[j]] + 1 < Min[i])
				{
					Min[i] = Min[i - coin[j]] + 1;
					what[i].clear();
					what[i].push_back(coin[j]);
					for (int k = 0; k < what[i - coin[j]].size(); k++)
					{
						what[i].push_back(what[i - coin[j]][k]);
					}
				}
			}
		}
	}
	cout << N  << " -- " << Min[N ] << endl;
	for (int i = 0; i <= N; i++)
	{
		cout << Min[i] << "    |  "<< i << " = ";
		for (int k =0; k < what[i].size(); k++)
		{
			cout << what[i][k] << " + ";
		}
		cout << endl;
	}

}


int main(int argc, char const *argv[])
{
	coin_problem(19);
}
