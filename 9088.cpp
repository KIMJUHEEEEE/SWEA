#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		int* dia = new int[n];
		for (int i = 0; i < n; i++)
		{
			int num = 0;
			cin >> num;
			dia[i] = num;
		}
		sort(dia, dia+n);
		int max = 0;

		for (int i = 0; i < n-1; i++)
		{	
			int sum = 1;
			for (int j = i + 1; j < n; j++)
			{
				if (dia[j] - dia[i] <= k)
					sum++;
				else
					break;
			}
			if (max < sum)
				max = sum;
		}
		cout << '#' << i << ' ' << max;
	}
}