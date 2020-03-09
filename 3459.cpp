#include<stdio.h>
int main()
{
	int tc = 0;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		unsigned long long n;
		scanf("%lld", &n);
		int check = 0;
		unsigned long long turn = 1;
		unsigned long long mul = 1;
		while (turn < n)
		{
			if (!check)
				mul *= 4;
			turn += mul;
			check = !check;
		}
		printf("#%d %s\n", i, check ? "Alice" : "Bob");

	}
}