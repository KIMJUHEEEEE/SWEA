#include<iostream>
#include<string.h>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int connect[1001];

unsigned long long find(unsigned long long a)
{
	if (a == connect[a]) return a;
	return connect[a] = find(connect[a]);
}
void uni(unsigned long long a, unsigned long long b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	connect[b] = a;
}

unsigned long long dis(unsigned long long x1, unsigned long long x2, unsigned long long y1, unsigned long long y2)
{
	unsigned long long d = ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return d;
}
int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		memset(connect, 0, sizeof(connect));
		int n;
		scanf("%d", &n);
		int po[2][1000] = { 0, };
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%lld", &po[i][j]);
				connect[j] = j;
			}
		}
		double e;
		scanf("%lf", &e);
		vector<tuple<unsigned long long, unsigned long long, unsigned long long>> v;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				v.push_back(make_tuple(dis(po[0][i], po[0][j], po[1][i], po[1][j]),(unsigned long long)i,(unsigned long long)j));
			}
		}
		sort(v.begin(), v.end());
		unsigned long long ans = 0;
		for (int j = 0; j < v.size(); j++)
		{
			unsigned long long x = get<1>(v[j]);
			unsigned long long y = get<2>(v[j]);
			if (find(x) == find(y))
				continue;
			ans += get<0>(v[j]);
			uni(x, y);
		}
		e = ans * e;
		printf("#%d %0.f\n", i, e);
	}
	return 0;
}
