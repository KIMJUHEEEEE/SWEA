#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		int arr[101] = { 0, };
		int p[101] = { 0, };
		for (int i = 0; i < n; i++)
		{
			int a = 0;
			cin >> a;
			p[i] = a;
		}
		sort(p, p + n);
		for (int i = m; i < p[n - 1] + 1; i++)
		{
			if (i % m == 0)
				arr[i] = k+arr[i-1];
			else
				arr[i] =arr[i-1];
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[p[i]] == 0)
			{
				ans = 1;
				break;
			}
			else
			{
				for (int i = m; i < p[n - 1] + 1; i++)
				{
					arr[i]--;
				}
			}
		}
		cout << '#' << i << ' ';
		if (ans == 1)
			cout << "Impossible" << endl;
		else
			cout << "Possible" << endl;
	}
}
