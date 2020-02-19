#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[101];
bool check[10001];


int main()
{
	int n=0; int mx=0;
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
			memset(check, 0, sizeof(check));
			memset(arr, 0, sizeof(arr));
		mx = 0;
		cin >> n;
		int max = 0;
		check[0] = 1;
		for (int j = 0; j < n; j++)
		{	
			cin >> arr[j];
			mx += arr[j];
			for (int z = mx; z >= 0; z--)
			{
				if (check[z] ==1)
				{
					check[z + arr[j]] = 1;
					if (z + arr[j] > max)
						max = z + arr[j];
				}
			}
			check[arr[j]] = 1;
		}
		int ans = 0;
		for (int i = 0; i <= max; i++)
		{
			if (check[i] == 1)
				ans++;
		}
		cout << '#' << i << ' '  <<ans<< endl;
	}
}