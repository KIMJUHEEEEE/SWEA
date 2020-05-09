#include<iostream>
#include<string.h>
using namespace std;
int n;
int map[22][22];
bool dessert[101];
int visit[22][22];
int ans;
int dir[4];
void dfs(int x, int y,int cnt,int s)
{
	if (dir[1] < dir[3] || dir[0] < dir[2]) return;
	if (x == 0 || y == 0 || x > n || y > n||map[x][y]==0) return;
	if (visit[x + 1][y + 1] == 0 && dessert[map[x + 1][y + 1]] == 0&&dir[1]==0)
	{
		visit[x + 1][y + 1] = 1;
		dessert[map[x + 1][y + 1]] = 1;
		dir[0]++;
		dfs(x + 1, y + 1, cnt + 1, s);
		visit[x + 1][y + 1] = 0;
		dessert[map[x + 1][y + 1]] = 0;
		dir[0]--;
	}
	if (visit[x + 1][y - 1] == 0 && dessert[map[x + 1][y - 1]] == 0&&dir[2]==0&&dir[0]>0)
	{
		visit[x + 1][y - 1] = 1;
		dessert[map[x + 1][y - 1]] = 1;
		dir[1]++;
		dfs(x + 1, y - 1, cnt + 1, s);
		dir[1]--;
		visit[x + 1][y - 1] = 0;
		dessert[map[x + 1][y - 1]] = 0;

	}
	if (visit[x - 1][y - 1] == 0 && dessert[map[x - 1][y - 1]] == 0&&dir[3]==0&&dir[1]>0)
	{
		visit[x - 1][y - 1] = 1;
		dessert[map[x - 1][y - 1]] = 1;
		dir[2]++;
		dfs(x- 1, y - 1, cnt + 1, s);
		dir[2]--;
		visit[x - 1][y - 1] = 0;
		dessert[map[x - 1][y - 1]] = 0;
	}
	if (dir[2]>0)
	{
		if (visit[x - 1][y + 1] == 0&&dessert[map[x-1][y+1]]==0)
		{
			visit[x - 1][y + 1] = 1;
			dessert[map[x - 1][y + 1]] = 1;
			dir[3]++;
			dfs(x - 1, y + 1, cnt + 1, s);
			dir[3]--;
			visit[x - 1][y + 1] = 0;
			dessert[map[x - 1][y + 1]] = 0;
		}
		else
		{
			if (map[x-1][y+1] == s && cnt > 1&&dir[0]==dir[2]&&dir[1]==dir[3]+1)
			{
				if (cnt > ans) ans=cnt+1;
				return;
			}
		}
	}

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
		memset(dessert, 0, sizeof(dessert));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				visit[i][j] = 2;
				dessert[map[i][j]] = 1;
				dfs(i, j,0,map[i][j]);
				visit[i][j] = 0;
				dessert[map[i][j]] = 0;
			}
		}
		if (ans == 0) ans = -1;
		cout << '#' << tc << ' ' << ans << endl;
	}

}