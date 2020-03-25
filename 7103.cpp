#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n = 0;
		cin >> n;
		int cnt = 0;
		for (int i =0; i*i<=n; i++)
		{
			
			for (int j = i; j*j+ i * i <= n; j++)
			{
				for (int z = j; z*z+ j * j + i * i <= n; z++)
				{
					int w = sqrt(n - (z * z + j * j + i * i));
					if (w < z) break;
					if (w * w + i * i + j * j + z * z == n)
						cnt++;
				}
			}
		}
		cout << '#' << tc << ' ' << cnt << endl;
	}
}