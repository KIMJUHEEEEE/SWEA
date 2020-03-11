#include<iostream>
#include<string.h>
using namespace std;
bool check[10000000];
int map[4][4];

void dfs(int x, int y, int num, int d)
{
	if (d == 7)
	{
		check[num] = 1;
		return;
	}
	num *= 10;
	num += map[x][y];
	if (y - 1 >= 0)
		dfs(x, y - 1, num, d + 1);
	if (y + 1 < 4)
		dfs(x, y + 1, num, d + 1);
	if (x - 1 >= 0)
		dfs(x - 1, y, num, d + 1);
	if (x + 1 < 4)
		dfs(x + 1, y, num, d + 1);
}

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				cin >> map[x][y];
			}
		}
		memset(check, 0, sizeof(check));
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				dfs(x, y, 0, 0);
			}
		}
		int ans = 0;
		for (int j = 0; j < 10000000; j++)
		{
			if (check[j] == 1)
				ans++;
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}
