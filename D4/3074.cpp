#include <stdio.h>

int main(void) {
	int T;
	setbuf(stdout, NULL);
	scanf("%d\n", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		int time[100001];
		long long max = 0;
		
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &time[i]);
			if (time[i] > max)
				max = time[i];
		}

		long long time1 = 0;
		long long time2 = max * m;
		long long mid;
		long long min = max * m;

		while (time1 <= time2)
		{
			mid = (time1 + time2) / 2;
			long long answer = 0;

			for (int i = 0; i < n; i++)
			{
				answer = answer + (mid / time[i]);
			}

			if (answer < m)
			{
				time1 = mid + 1;
			}
			else
			{
				if (min > mid)
					min = mid;
				time2 = mid - 1;
			}
		}
		printf("#%d %lld\n", test_case, min);
	}
	return 0;
}