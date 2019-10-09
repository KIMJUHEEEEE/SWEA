#include<iostream>
#include<string.h>
using namespace std;
int arr[105][105];
int ar[105][105];
int x[4] = { -1,0,0,1 };
int y[4] = { 0,1,-1,0 };

void cal(int i, int j, int sum)
{
	for (int a = 0; a < 4; a++)
	{
		if (arr[i + x[a]][j + y[a]] != 0 && ar[i + x[a]][j + y[a]] == 0)
		{
			ar[i + x[a]][j + y[a]] = sum;
			cal(i + x[a], j + y[a], sum);
		}
	}
}
int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;

		cin >> n;
		int arm = 0; int arn = 999;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> arr[i][j];
				if (arm < arr[i][j])
					arm = arr[i][j];
			}
		}
		int sum;
		int max = 0;
		for (int z = 0; z < arm; z++)
		{
			memset(ar, 0, sizeof(ar));
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (arr[i][j] == z)
						arr[i][j] = 0;
				}
			}
			sum = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (arr[i][j] != 0)
					{
						if (ar[i][j] == 0)
						{
							sum++;
							ar[i][j] = sum;
							cal(i, j, sum);
						}
					}
				}
			}
			if (max < sum)
				max = sum;
		}
		cout << '#' << i << ' ' << max << endl;
	}
}