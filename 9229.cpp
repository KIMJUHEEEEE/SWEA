#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<cmath>
#include <stdio.h>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		int arr[1002] = { 0 , };
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);	
		cout << '#' << i << ' ' ;
		int max = 0;

		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (max < arr[i] + arr[j] && arr[i] + arr[j] <= m)
					max = arr[i] + arr[j];
				if (max == m)
					break;
			}
		}
		if (max == 0)
			cout << -1 << endl;
		else
			cout << max << endl;
	}
}