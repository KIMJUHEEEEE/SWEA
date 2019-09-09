#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a = 0;
		scanf("%d", &a);
		int ar[10] = { 0, };
		for (int j = 0; j < a; j++)
		{
			scanf("%d", &ar[j]);
		}
		for (int j = 0; j < a - 1; j++)
		{
			int sum = ar[j] + ar[j + 1];
			int mul = ar[j] * ar[j + 1];
			if (sum > mul)
				ar[j + 1] = sum;
			else
				ar[j + 1] = mul;
		}
		printf("#%d %d\n", i + 1, ar[a - 1]);
	}
}
