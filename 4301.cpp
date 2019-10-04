#include<iostream>
using namespace std;
int arr[1005][1005];
int main(void)
{
	int T;
	cin>>T;
	for (int i = 1; i <= T; i++)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0)
				{
					arr[i + 2][j] = 1;
					arr[i][j + 2] = 1;
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0)
					cnt++;
			}
		}
		printf("#%d %d\n", i, cnt);
	}
}
