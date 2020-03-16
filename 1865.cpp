#include<iostream>
#include<string.h>
using namespace std;
double arr[17][17];
int visit[17];
double ans;
int n;
void dfs(double x, int num)
{
	if (x * 100 <= ans)
		return;
	if (num == n)
	{
		if (x * 100 > ans)
			ans = x * 100;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 0)
		{
			visit[i] = 1;
			dfs(x * arr[num][i], num + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		memset(arr, 0, sizeof(arr));
		cin >> n;
		ans = 0.0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				arr[i][j] /= 100;
			}
		}
		dfs(1.0, 0);
		//		cout << '#' << i << ' ' << ans << endl;
		printf("#%d %.6lf\n", i, ans);
	}
}
