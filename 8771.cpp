#include<iostream>
using namespace std;

int main() {
	int tc = 0;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		unsigned long long int ans = 0, n = 0, a = 0, b = 0;

		scanf("%lld %lld %lld", &n, &a, &b);
		if (a > b)
		{
			cout << '#' << i << ' ' << 0 << '\n';
		}
		else if (a == b)
		{
			printf("#%d 1\n", i);
		}
		else
		{
			if (n == 1)
				printf("#%d 0\n", i);
			else if (n == 2)
				printf("#%d 1\n", i);
			else
			{
				ans = (b - a) * (n - 2) + 1;
				cout << '#' << i << ' ' << ans << '\n';
			}
		}
	}

}