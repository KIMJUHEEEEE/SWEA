#include<iostream>
#include<stack>
#include<string.h>
#include<algorithm>
using namespace std;
char map[20][20];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1, 1, 0, 0 };
int r = 0, c = 0;
int cnt;
int mmx;		bool copycheck[20][20]; bool copyalp[28];
int ans;	char ch = ' ';
int rx, ry;
stack<pair<pair<int, int>, int>> s;
stack<pair<pair<int, int>, char>> back;
void dfs(int x, int y, int cnt)
{	mmx = max(mmx, cnt);
		for (int i = 0; i < 4; i++)
		{
			int mx = x+dx[i];
			int my = y+dy[i];
			if (copyalp[map[mx][my ] - 'A'] == 0
				&& mx>= 0 && mx< r && my  >= 0 && my  < c)
			{
				copyalp[map[mx ][my ] - 'A'] = 1;
				dfs(mx,my,cnt+1);
				copyalp[map[mx ][my] - 'A'] = 0;

			}
		}
}

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		memset(copyalp, 0, sizeof(copyalp));
		mmx = 0;
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> map[i][j];
			}
		}
		copyalp[map[0][0] - 'A'] = 1;
		dfs(0,0,1);
		cout << '#' << i << ' ' << mmx << '\n';
	}
}