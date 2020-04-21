#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int map[25][25];
int cal[22];
int visit[25][25];
int M, N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int maxh;
void solve(int i, int j)
{
	queue<pair<int, int>> q;
	memset(visit, 0, sizeof(visit));
	int ch = 0;
	q.push({ i,j });
	int num = 1;
	if (map[i][j] == 1)
	{
		ch++;

	}
	visit[i][j] = 1;
	while (q.size() != 0)
	{
		int qs = q.size();
		if (ch * N >= cal[num])
		{
			if (maxh < ch)
				maxh = ch;
		}
		if (num == M + 1) return;
		while (qs--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int a = 0; a < 4; a++)
			{
				if (x + dx[a] >= 0 && y + dy[a] >= 0 && x + dx[a] < M && y + dy[a] < M && visit[x + dx[a]][y + dy[a]] == 0)
				{
					q.push({ x + dx[a],y + dy[a] }); visit[x + dx[a]][y + dy[a]] = 1;
					if (map[x + dx[a]][y + dy[a]] == 1)
						ch++;
				}


			}
		}
		num++;
	}

}
int main()
{
	for (int i = 1; i <= 21; i++)
	{
		cal[i] = i * i + (i - 1) * (i - 1);
	}
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		memset(map, 0, sizeof(map));
		maxh = 0;
		cin >> M >> N;
		int hn = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
					hn++;
			}
		}
		int ans = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < M; j++)
			{
				solve(i, j);
			}
		}
		cout << '#' << tc << ' ' << maxh << endl;
	}
}