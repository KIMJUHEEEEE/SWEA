#include<iostream>
using namespace std;
int main(void)
{
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int n = 0; int arr[1000] = { 0, };
		cin >> n;
		int a = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a;
			arr[i] = a % 3;
		}
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			if (i % 3 != arr[i])
			{
				ans++;
				for (int j = i + 1; j <= n; j++)
				{
					if (arr[j] == i % 3 && j % 3 != i)
					{
						int tmp = arr[j];
						arr[j] = arr[i];
						arr[i] = tmp;
					}
				}
			}
		}
		cout << '#' << i << ' ' << ans;
	}
}
