#include<iostream>
#include<string.h>
using namespace std;
int n;
int map[22][22];
int ans;
int dx[4] = { 1,-1,-1,1 };
int dy[4] = { 1,1,-1,-1 };
int visit[22][22];
int desert[101];

void dfs(int y, int x, int m, int d, int my, int mx)
{
	for (int i = d; i < 4; i++)
	{
		int yy = y + dy[i];
		int xx = x + dx[i];

		if (yy == my && xx == mx && m >= 4)
		{
			if (ans < m)
				ans = m;
			return;
		}
		if (map[yy][xx] == 0 || visit[yy][xx] == 1 || desert[map[yy][xx]] == 1 || (i - d < 0 ? -1 * (i - d) : i - d) > 1)
			continue;
		visit[yy][xx] = desert[map[yy][xx]] = 1;
		dfs(yy, xx, m + 1, i, my, mx);
		visit[yy][xx] = desert[map[yy][xx]] = 0;
	}
	return;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		ans = 0;
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		memset(desert, 0, sizeof(desert));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				cin >> map[i][j];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				visit[i][j] = desert[map[i][j]] = 1;
				dfs(i, j, 1, 0, i, j);
				visit[i][j] = desert[map[i][j]] = 0;
			}
		}
		if (ans == 0)
			ans = -1;
		cout << '#' << tc << ' ' << ans << endl;
	}
}