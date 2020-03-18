#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int visit[101];
vector<int> v[101];
int ans;

void dfs(int x)
{
	visit[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
	{
		int a = v[x][i];
		if (visit[a] == 0)
		{
			dfs(a);
		}
	}
}
int main()
{
	int t = 0; cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		ans = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < 101; i++)
			v[i].clear();
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		if (m == 0)
		{
			ans = n;
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				if (visit[i] == 1) continue;
				dfs(i);
				ans++;

			}
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
}