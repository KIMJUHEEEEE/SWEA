#include<iostream>
#include<string.h>
using namespace std;
int num;
int arr[21][2];
int visit[21];
long long mini;

void dfs(int now, int d)
{
	if (d == num / 2)
	{
		long long x = 0, y = 0;
		for (int i = 0; i < num; i++)
		{
			if (visit[i] == 0)
			{
				x += arr[i][0];
				y += arr[i][1];
			}
			else
			{
				x -= arr[i][0];
				y -= arr[i][1];
			}
		}
		if (x * x + y * y < mini)
			mini = x * x + y * y;
		return;
	}
	for (int i = now; i < num; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			dfs(i + 1, d + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	int tc = 0;
	cin >> tc;
	setbuf(stdout, NULL);
	for (int i = 1; i <= tc; i++)
	{
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> arr[j][0] >> arr[j][1];
		}
		mini = 1e18;
		dfs(0, 0);
		cout << '#' << i << ' ' << mini << '\n';
	}
	return 0;
}