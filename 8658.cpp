#include<iostream>
using namespace std;
int main(void)
{
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int max = 0; int min = 999999;
		for (int i = 0; i < 10; i++)
		{
			int a;
			cin >> a;
			int sum = 0;
			while (1)
			{
				sum += a % 10;
				if (a / 10 == 0)
					break;
				a = a / 10;
			}
			if (sum > max)
				max = sum;
			if (sum < min)
				min = sum;
		}
		cout << '#' << i << ' ' << max << ' ' << min << endl;
	}
}
