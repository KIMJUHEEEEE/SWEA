#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;
int n, w, h;
int map[16][13];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int ans;

void down()
{
	for (int i = 0; i < w; i++)
	{
		stack<int> s;
		for (int j = 0; j < h; j++)
		{
			if (map[j][i] != 0)
			{
				s.push(map[j][i]);
				map[j][i] = 0;
			}

		}
		int ssize = s.size();
		for (int j = 0; j < ssize; j++)
		{
			map[h - j - 1][i] = s.top();
			s.pop();
		}
	}
}
void makecopy(int a[][13],int b[][13])
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}
int count()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (map[i][j] != 0)
				cnt++;
		}
	}
	return cnt;
}
void dfs(int cnt,int index,int check)
{
	int copymap[16][13];
	memset(copymap, 0, sizeof(copymap));
	if (w == index) return;
	if(ans==0) return;
	if (cnt == n+1) {
		int num = count();
		if (ans > num)
			ans = num;
		return;
	}
	if (check == 1)
	{
		int i = 0;
		while (map[i][index] == 0)
		{
			i++;
			if (i == h)
			{
				i = h;
				break;
			}
		}
		if (i < h)
		{
			int a = map[i][index] - 1; queue<pair<pair<int, int>, int>> q;
			q.push({ {i,index},a + 1 });				map[i][index] = 0;
			while (q.size() > 0)
			{
				int k = q.front().second;
				int x = q.front().first.first;
				int y = q.front().first.second;
				q.pop();
				while (k --)
				{
					for (int j = 0; j < 4; j++)
					{
						if (map[x + k * dx[j]][y + k * dy[j]] != 0 && x + k * dx[j] >= 0 && y + k * dy[j] >= 0 && x + k * dx[j] < h && y + k * dy[j] < w && k < 10 && k>0)
						{
							int m = map[x + k * dx[j]][y + k * dy[j]];
							if (m > 1)
							{
								q.push({ {x + k * dx[j],y + k * dy[j]},m });

							}
							map[x + k * dx[j]][y + k * dy[j]] = 0;
						}
					}
				}
			}
			down();
		}
	}
	if (count() == 0) {
		ans = 0;
		return;
	}
	makecopy(map, copymap);
	for (int i = 0; i < w; i++)
	{
		dfs(cnt + 1, i, 1);
		makecopy(copymap, map);
	}
}
int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		ans = 9999999;
		memset(map, 0, sizeof(map));
		int cmap[16][13];
		memset(cmap, 0, sizeof(cmap));
		cin >> n >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				cmap[i][j] = map[i][j];
			}
		}
		dfs(0, 0,0);
		cout << '#' << tc << ' ' << ans << endl;
	}
}