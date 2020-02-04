#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
char map[16][16];
queue <pair<int, int>> q;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int search(int sx, int sy) {
	bool jud = 0;
	while (q.size() != 0)
	{
		int qs = q.size();
		while (qs--)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int mx = x, my = y;
				if (map[mx + dx[i]][my + dy[i]] == '0')
				{
					while (map[mx + dx[i]][my + dy[i]] == '0')
					{
						int n = 0;
						for (int j = 0; j < 4; j++)
						{
							if (map[mx + dx[j]][my + dy[j]] == '0')
								n++;
						}
						if (n > 1)
							q.push({ mx,my });
						map[mx + dx[i]][my + dy[i]] = '1';
						mx += dx[i], my += dy[i];
					}
					if (map[mx + dx[i]][my + dy[i]] == '3')
					{
						jud = 1;
						break;
					}
					q.push({ mx,my });
				}
			}
		}
	}
	return jud;
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		char n = 0;
		cin >> n;
		int sx = 0, sy = 0;
		for (int a = 0; a < 16; a++)
		{
			for (int b = 0; b < 16; b++)
			{
				cin >> map[a][b];
				if (map[a][b] == '2')
				{
					q.push({ a,b });
					sx = a, sy = b;
				}
			}
		}
		cout << '#' << i << ' ' << search(sx, sy) << endl;
	}
}
