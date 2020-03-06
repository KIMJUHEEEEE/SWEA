#include<iostream>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		char map[51][51];
		int n = 0, m = 0;
		cin >> n >> m;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		int min = 9999;
		for (int i = 1; i <= n - 2; i++)
		{
			for (int j = 1; j <= n - i - 1; j++)
			{
				int k = n - j - i;
				int sum = 0;
				for (int l = 1; l <= n; l++)
				{
					for (int z = 0; z < m; z++)
					{
						if (l <= i)
						{
							if (map[l][z] != 'W')
								sum++;
						}
						if (l > i&& l <= (i + j))
						{
							if (map[l][z] != 'B')
								sum++;
						}
						if (l > (i + j) && l <= (i + j + k))
						{
							if (map[l][z] != 'R')
								sum++;
						}
					}
				}
				if (min > sum)
					min = sum;
			}
		}
		cout << '#' << i << ' ' << min << endl;
	}
}