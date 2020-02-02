#include<iostream>
#include<algorithm>
using namespace std;

pair<long long, long long> v[1000001];
bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			long long a = 0, b = 0;
			cin >> a >> b;
			v[i] = make_pair(a, b);
		}
		sort(v, v + n, cmp);
		long long minday = 1000000001L, sum = 0L;
		for (int i = 0; i < n; i++)
		{
			sum += v[i].first;
			minday = min(minday, v[i].second - sum);
		}
		if (minday < 0)
			minday = 0;
		cout << '#' << i << ' ' << minday << endl;
	}
}
