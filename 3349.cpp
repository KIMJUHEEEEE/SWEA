#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main() {
	int t = 0;
	cin>>t;		
	for (int i = 1; i <= t; i++)
	{
		int w, h, n;
		cin >> w >> h >> n;
		vector<pair<int, int>> arr;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			arr.push_back(pair<int, int>(x, y));
		}
		int ans = 0;
		for (int i = 1; i < n; i++)
		{
			int n1, m1;
			n1 = arr[i].first - arr[i - 1].first;
			m1 = arr[i].second - arr[i - 1].second;
			if (m1*n1 < 0)
			{
				ans += abs(m1) + abs(n1);
				continue;
			}
			else
			{
				n1 = abs(n1); m1 = abs(m1);
				if (n1 <= m1)
				{
					ans += n1;
					m1 -= n1; n1 = 0;
					ans += m1;
				}
				else
				{
					ans += m1;
					n1 -= m1; m1 = 0;
					ans += n1;
				}
			}
		}
		cout << '#'<<i<<' '<<ans<<endl;
	}
}
