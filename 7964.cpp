#include<iostream>
#include <vector>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, d;
		vector<int> v;
		cin >> n >> d;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}
		int num = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] == 0)
			{
				num++;
			}
			else
				num = 0;
			if (num == d)
			{
				ans++;
				num = 0;
			}
		}
		cout << '#' << i << ' ' << ans<<endl;
	}
}
