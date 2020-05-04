#include<iostream>
#include<vector>
#include<string.h>
#include<cmath>
using namespace std;
int n;
int map[17][17];
int visit[17];
int mini;
int count()
{
	int a=0;
	vector<int> v; vector<int> m;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == 1)
		{
			v.push_back(i);
		}
		else
			m.push_back(i);
	}
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			a += map[v[i]][v[j]] + map[v[j]][v[i]];
		}
	}
	int b = 0;
	for (int i = 0; i < m.size() - 1; i++)
	{
		for (int j = i + 1; j < m.size(); j++)
		{
			b += map[m[i]][m[j]] + map[m[j]][m[i]];
		}
	}
	return abs(a-b);
}
void dfs(int cnt,int index)
{
	if (cnt == n / 2)
	{
		int cnt = count();
		if (mini > cnt)
			mini = cnt;
		return;
	}
	if (index > n) return;
	visit[index] = 1;
	dfs(cnt + 1, index + 1);
	visit[index] = 0;
	dfs(cnt, index + 1);

}
int main()
{
	int t = 0; cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		mini = 99999;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
			}
		}
		dfs(0,1);
		cout << '#' << tc << ' ' << mini<<endl;
	}
}
