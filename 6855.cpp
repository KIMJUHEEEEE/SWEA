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
		int n, k;
		cin >> n >> k;
		vector<int> lights;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			lights.push_back(a);
		}
		if (n <= k) cout << '#' << tc << ' ' << 0 << endl;
		else {
			sort(lights.begin(), lights.end());
			vector<int> diff;
			int sum = 0;
			for (int i = 0; i < lights.size() - 1; i++)
			{
				int a = lights[i + 1] - lights[i];
				diff.push_back(a);
				sum += a;
			}
			sort(diff.begin(), diff.end());
			for (int i = 0; i < k - 1; i++)
			{
				sum -= diff[diff.size() - 1 - i];
			}
			cout << '#' << tc << ' ' << sum << endl;
		}
	}
}