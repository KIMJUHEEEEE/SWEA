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
		vector<int> v;
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
v.push_back(a);
		}
		sort(v.begin(), v.end());
		int bi = 0, ans = 0;
		int box = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			box = v[i]; ans++;
			for (; bi < i; bi++)
			{
				if (box >= 50) break;
				box += v[i];
			}
			if (box < 50) ans--;
			if (bi == i) break;
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
}