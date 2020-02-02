#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		unsigned long long ny;
		unsigned long long nm;
		long long y = 0, m = 0;
		cin >> y >> m;
		unsigned long long n = ((y - 2016) * 12LL + m);
		ny = ((n - 1) / 13LL) + 2016;
		nm = ((n - 1) % 13LL) + 1;
		printf("#%d %lld %lld\n", i, ny, nm);
	}
}