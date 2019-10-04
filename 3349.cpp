#include <stdio.h>
#include <memory.h>
int arr[1005][1005];
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 0)
				{//콩이 심어져있으면, 오른쪽, 아래를 탐색해서 거리가 2인곳의 콩을 없앤다.
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
		printf("#%d %d\n", test_case, cnt);
	}
}
