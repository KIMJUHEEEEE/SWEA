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
		vector<int> camera;
		int n = 0;
		cin >> n;
		int c = 0;
		cin >> c;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			camera.push_back(a);
		}
		if (n < c) cout << '#' << tc << ' ' << 0 << endl;
		else {
			vector<int> len;
			int sum = 0;
			sort(camera.begin(), camera.end());
			for (int i = n - 1; i >= 1; i--)
			{
				int a = camera[i] - camera[i - 1];
				len.push_back(a);
				sum += a;
			}
			sort(len.begin(), len.end());
			for (int i = 0; i < c - 1; i++)
			{
				int a = len[len.size() - 1 - i];
				sum -= a;
			}
			cout << '#' << tc << ' ' << sum << endl;
		}
	}
}