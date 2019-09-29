#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string a;
		cin >> a;
		float ans = 0;
		int n = 0;
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (a[i] == 't')
			{
				i -= 3;
				if (ans != 90)
				{
					ans += 90 / pow(2, n);
				}
				else
					ans = 90;
				n++;
			}
			else
			{
				i -= 4;
				if (ans != 0)
				{
					ans -= 90 / pow(2, n);
				}
				n++;
			}
		}
		printf("#%d ", i);
		int b = 0;
		if (ans > 90)
			ans = 180 - ans;
		if (ans == (int)ans)
		{
			printf("%d\n", (int)ans);
		}
		else
		{
			int a = 1;
			while (1)
			{
				int k = pow(2, a);
				float as = ans * k;
				if (as == (int)as)
				{
					printf("%d/%d\n", (int)as, k);
					break;
				}
				else
					a++;
			}
		}
	}
}
