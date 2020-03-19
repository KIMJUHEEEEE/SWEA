#include<iostream>
using namespace std;

int  main()
{
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		int a, b;
		long long ans = 1;
		cin >> a >> b;
		if (a >= b)
		{
			ans = b;
		}
		else {
			for (int i = a; i > 1; i--)
			{
				if (b % i == 0)
				{
					b /= i;
					ans *= i;
				}
			}
		}
		cout << '#' << t << ' ' << ans << endl;
	}
}