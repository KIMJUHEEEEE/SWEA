#include<iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		cin >> n;
		int arr[5001] = { 0, };
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			if (arr[i] > 0)
			{
				int a = arr[i] - 1;
				ans++;
				for (int j = i + 1; j < n; j++)
				{
					if ((arr[j] - 1) % a == 0)
						arr[j] = 0;
				}
			}

		}
		cout << '#' << i << ' ' << ans << endl;
	}
}
