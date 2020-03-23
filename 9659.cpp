#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int te = 0;
	cin >> te;
	for (int tc = 1; tc <= te; tc++)
	{
		int n = 0;
		cin >> n;
		vector<pair<int, pair<int, int>>> v;
		for (int i = 0; i < n - 1; i++)
		{
			int t, a, b;
			cin >> t >> a >> b;
			v.push_back({ t,{a,b} });
		}
		int m = 0;
		cin >> m;
		cout << '#' << tc << ' ';
		for (int i = 0; i < m; i++)
		{
			int x = 0;
			vector<long long> f;
			cin >> x;
			f.push_back(1);
			f.push_back(x);
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i].first == 1)
				{
					f.push_back((f[v[i].second.first] + f[v[i].second.second]) % 998244353);
				}
				else if (v[i].first == 2)
				{
					f.push_back((v[i].second.first * f[v[i].second.second]) % 998244353);
				}
				else if (v[i].first == 3)
				{
					f.push_back((f[v[i].second.first] * f[v[i].second.second]) % 998244353);
				}
			}
			cout << f[n] << ' ';
		}
		cout << endl;
	}
}