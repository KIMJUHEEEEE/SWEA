#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int N, M, C, R, L;
int map[51][51];
int visit[51][51];
queue<pair<pair<int, int>,int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void solve()
{
	while (q.size() != 0)
	{
		int qs = q.size();
		if (L == 0) return;
		L--;
		while (qs--)
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int dir = q.front().second;
			int num = map[x][y];
			q.pop();
			if (visit[x][y] == 0)
			{
				visit[x][y] = 1;

				if (num == 0) continue;
				else if (num == 1)
				{
					for (int i = 0; i < 4; i++)
					{
						if (map[x + dx[i]][y + dy[i]] != 0)
						{
							if (i == 0 || i == 1)
							{
								if (map[x + dx[i]][y + dy[i]] != 2)
								{
									if(i==0&& map[x + dx[i]][y + dy[i]] != 4&&map[x + dx[i]][y + dy[i]] != 5)
										q.push({ { x + dx[i],y + dy[i]},i });
									else if(i==1&&map[x+dx[i]][y+dy[i]]!=6&& map[x + dx[i]][y + dy[i]] != 7)
										q.push({ { x + dx[i],y + dy[i]},i });
								}
							}
							else if (i == 2 || i == 3)
							{
								if (map[x + dx[i]][y + dy[i]] != 3)
								{
									if(i==2&&map[x+dx[i]][y+dy[i]]!=5&& map[x + dx[i]][y + dy[i]] != 6)
										q.push({ { x + dx[i],y + dy[i]},i });
									else if (i == 3 && map[x + dx[i]][y + dy[i]] != 4 && map[x + dx[i]][y + dy[i]] != 7)
										q.push({ { x + dx[i],y + dy[i]},i });
								}
							}
						}
					}
				}
				else if (num == 2)
				{
					for (int i = 2; i < 4; i++)
					{
						if (map[x + dx[i]][y + dy[i]] != 0 && map[x + dx[i]][y + dy[i]] != 3 && visit[x + dx[i]][y + dy[i]] == 0)
						{
							if (i == 2)
							{
								if (map[x + 1][y] != 5 && map[x + 1][y] != 6)
									q.push({ { x + dx[i],y + dy[i] },i });
							}
							else
								if (map[x - 1][y] != 4 && map[x - 1][y] != 7)
									q.push({ { x + dx[i],y + dy[i]},i });
						}
					}
				}
				else if (num == 3)
				{
					for (int i = 0; i < 2; i++)
					{
						if (map[x + dx[i]][y + dy[i]] != 0 && map[x + dx[i]][y + dy[i]] != 2 && visit[x + dx[i]][y + dy[i]] == 0)
						{
							if (i == 0)
							{
								if (map[x][y + 1] != 4 && map[x][y+1] != 5)
									q.push({ {x + dx[i],y + dy[i] },i });
							}
							else
								if (map[x][y - 1] != 6 && map[x][y-1] != 7)
									q.push({ { x + dx[i],y + dy[i] },i });
						}
					}
				}
				else if (num == 4)
				{
						if (dir == 2)
						{
							if(map[x][y+1]!=5 && visit[x][y + 1] == 0&& map[x][y + 1] != 0 && map[x][y+1] != 4 && map[x][y + 1] != 2)
								q.push({ { x ,y + 1 }, 0});
						}
						if (dir == 1)
						{
							if (map[x - 1][y] != 7 && visit[x - 1][y] == 0&&map[x-1][y]!=0&&map[x-1][y]!=4&&map[x - 1][y] != 3)
							{
								q.push({ {x - 1,y},3 });
							}
						}
				}
				else if (num == 5)
				{
					if (dir == 1)
					{
						if (map[x+1][y ] != 6 && visit[x+1][y ] == 0 && map[x+1][y] != 0&&map[x + 1][y] != 5&& map[x + 1][y] != 3)
							q.push({ { x+1 ,y  }, 2 });
					}
					if (dir == 3)
					{
						if (map[x][y+1] != 4 && visit[x ][y+1] == 0 && map[x][y+1] != 0&&map[x ][y+1] != 5 && map[x][y + 1] != 2)
						{
							q.push({ {x,y+1},0 });
						}
					}
				}
				else if (num == 6)
				{
					if (dir == 0)
					{
						if (map[x+1][y ] != 5 && visit[x+1][y] == 0 && map[x+1][y] != 0&& map[x + 1][y] != 6 && map[x + 1][y] != 3)
							q.push({ { x+1 ,y }, 2 });
					}
					if (dir == 3)
					{
						if (map[x][y-1] != 6 && visit[x][y-1] == 0 && map[x][y-1] != 0&& map[x ][y-1] != 7 && map[x][y - 1] != 2)
						{
							q.push({ {x,y-1},1 });
						}
					}
				}
				else if (num == 7)
				{
					if (dir == 0)
					{
						if (map[x-1][y ] !=4 && visit[x-1][y] == 0 && map[x-1][y ] != 0&& map[x - 1][y] != 7 && map[x - 1][y] != 3)
							q.push({ { x-1 ,y  }, 3 });
					}
					if (dir == 2)
					{
						if (map[x][y-1] != 6 && visit[x ][y-1] == 0 && map[x ][y-1] != 0&& map[x][y - 1] != 7 && map[x][y - 1] != 2)
						{
							q.push({ {x ,y-1},1 });
						}
					}
				}
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
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		cin >> N >> M >> R >> C >> L;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
			}
		}
		q.push({ { R,C } ,0});
		solve();
		while(q.size()!=0)
			q.pop();
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j] == 1)
					ans++;
			}
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
}