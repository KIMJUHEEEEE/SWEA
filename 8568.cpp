#include<iostream>
using namespace std;
int main(void)
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int n = 0;
		int arr[1001] = { 0, };
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			int a = 0;
			cin >> a;
			arr[i] = a % 3;
		}
		long long int ans = 0;
		int p = 0;
		for (int i = 0; i < n; i++)
		{
			++p %= 3;
			if (p == arr[i]) continue;
			int sig = 0;
			int before = 0;

			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] == p && (j + 1) % 3 == arr[i])
				{
					ans++;
					int tmp = arr[j];
					arr[j] = arr[i];
					arr[i] = tmp;
					sig = 1;
					break;
				}
				if (arr[j] == p && arr[j] != (j + 1) % 3)
					before = j;

			}
			if (sig != 1)
			{
				ans++;
				int tmp = arr[before];
				arr[before] = arr[i];
				arr[i] = tmp;
			}
		}
		printf("#%d %lld\n", i, ans);
	}
}