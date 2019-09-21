#include<iostream>
#include<algorithm>
#include <vector>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, q;
		cin >> n >> q;
		int arr[1001] = { 0, };
		for (int i = 1; i <= q; i++)
		{
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++)
			{
				arr[j] = i;
			}
		}
		cout << '#' << i << ' ';
		for (int i = 1; i <= n; i++)
		{
			cout << arr[i];
		}
	}
}