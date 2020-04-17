#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int t = 0;
	cin >> t;
	
	for (int tc = 1; tc <= t; tc++)
	{
		int d = 0;
		int y = 0;
		int m = 0;
		int arr[4] = { 0, };
		int month[13] = { 0, };
		int dp[13] = { 0, };

		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		for (int i = 1; i <= 12; i++)
		{
			d = 0;
			cin >> month[i];
			d += month[i] * arr[0];
			dp[i] += dp[i - 1];
			if (d < arr[1]) dp[i] += d;
			else
				dp[i] += arr[1];
			if (i >= 3)
			{
				if (dp[i] - dp[i - 3] > arr[2])
				{
					dp[i] = dp[i - 3] + arr[2];
				}
			}
		}

		if (arr[3] < dp[12]) dp[12] = arr[3];
		cout << '#' << tc << ' ' << dp[12] << endl;
	}
}