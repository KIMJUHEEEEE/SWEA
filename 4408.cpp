#include<iostream>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int cor[202] = { 0, };
		int n = 0; cin >> n;
		int max = 0;
		for (int j = 0; j < n; j++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			if (a > b) {
				int tmp = a;
				a = b;
				b = tmp;
			}
			if (a % 2 == 1)
			{
				a += 1;

			}                
			a /= 2;
			
			if (b % 2 == 1)
			{
				b += 1;

			}              
			b /= 2;
			
			for (int k = a; k <= b; k++)
			{
				cor[k]++;
				if (cor[k] > max)
				{
					max = cor[k];
				}
			}
		}
		cout << '#' << i << ' ' << max << endl;
	}
}