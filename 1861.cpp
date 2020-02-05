#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
int nt;
int cnt;
using namespace std;
int map[1002][1002];
int m = 0, n = 0, cab = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int>> v;

void bfs()
{
	cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 1; i < v.size()-1; i++)
	{int l = 1; int nu = 1;
	q.push(v[i]);
		while (q.size() > 0)
		{
			int mx = q.front().first;
			int my = q.front().second;
			q.pop();
			for (int z = 0; z < 4; z++)
			{
				int mmx = mx, mmy = my;
				if (map[mmx + dx[z]][mmy + dy[z]] == i + 1)
				{
					mmx += dx[z]; mmy += dy[z];
					nu++;
					q.push({ mmx,mmy });
					i++;
					break;
				}
			}
			
		}
		if (cnt < nu)
			{
				cnt = nu;
				nt = i-cnt+1;
			}
	}
}
int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		int n = 0; cin >> n;
		v.resize(n * n+1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				v[map[i][j]] = { i,j };
			}
		}
		bfs();
		cout << '#' << i+1 << ' ' << nt << ' ' << cnt << endl;
	}
	return 0;
}