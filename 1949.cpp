#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n, k;
int map[8][8];
int copymap[8][8];
int visit[8][8];
queue<pair<pair<int, int>, int>> top;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans;
int ch;
void dfs(int x, int y, int num,int kn)
{

	if (x < 0 || y < 0 || x == n || y == n)
	{
		num -= 1;
		if (num > ans)
			ans = num;
		return;
	}
	if (copymap[x][y] == 0)
	{
		if (num > ans)
			ans = num;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (visit[x + dx[i]][y + dy[i]] == 0)
		{
			if (copymap[x + dx[i]][y + dy[i]] < copymap[x][y])
			{
				visit[x + dx[i]][y + dy[i]] = 1;
				dfs(x + dx[i], y + dy[i], num + 1, kn);
				visit[x + dx[i]][y + dy[i]] = 0;
			}
			else if (copymap[x + dx[i]][y + dy[i]] >= copymap[x][y]&&ch==0)
			{
				int a = 1;
				while (a <= kn)
				{
					if (copymap[x + dx[i]][y + dy[i]] - a < copymap[x][y])
					{
						copymap[x + dx[i]][y + dy[i]] -= a;
						visit[x + dx[i]][y + dy[i]] = 1;
						ch = 1;
						dfs(x + dx[i], y + dy[i], num + 1, kn - a);
						visit[x + dx[i]][y + dy[i]] = 0;
						copymap[x + dx[i]][y + dy[i]] += a;
						ch = 0;
					}
					a++;
				}
			}
		}
	}
	if (num > ans)
		ans = num;
	return;
}
int main()
{
	int t = 0;
	cin >> t;
	
	for (int tc = 1; tc <= t; tc++)
	{
		memset(map, 0, sizeof(map));
		memset(copymap, 0, sizeof(copymap));
		memset(visit, 0, sizeof(visit));
		cin >> n >> k;int mnum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				copymap[i][j] = map[i][j];
				if (map[i][j] > mnum) mnum = map[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == mnum)
				{
					top.push({ {i,j},mnum });
				}
			}
		}ans = 0;
		while (top.size() != 0)
		{
			int x = top.front().first.first;
			int y = top.front().first.second;
			int high = top.front().second;
			int kn = k;
			top.pop();
			 ch = 0;
			visit[x][y] = 1;
			dfs(x, y, 1,kn);
			visit[x][y] = 0;
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
}