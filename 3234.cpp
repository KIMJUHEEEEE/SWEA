#include<cstdio>
#include<string.h>
#include<math.h>
int visit[10];
int arr[10];
int n;
int ans;
int s;

int fact(int num) {
	int sum = 1;
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	return sum;
}

void solve(int cnt, int left, int right)
{
	if (right > left) return;
	else if (cnt == n)
	{
		ans++; return;
	}
	else if (left >= s - left)
	{
		int re = n - cnt;
		ans += fact(re) * (int)pow(2, re);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visit[i] == 1) continue;

		visit[i] = 1;
		solve(cnt + 1, left + arr[i], right);
		if (left - arr[i] - right >= 0)
			solve(cnt + 1, left, right + arr[i]);
		visit[i] = 0;

	}
}
int main()
{
	int t = 0;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++)
	{
		scanf("%d", &n);
		s = 0;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
			s += arr[i];
		}
		ans = 0;
		solve(0, 0, 0);
		printf("#%d %d\n", tc, ans);
	}
}