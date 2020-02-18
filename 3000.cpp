#include<iostream>
#include<set>
using namespace std;

int main() {
	int tc = 0; cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n, m;
		cin >> n >> m;
		multiset<long> ms;
		ms.insert(m);
		multiset<long>::iterator it = ms.begin();
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			long a, b;
			cin >> a >> b;
			int mid = *it;
			ms.insert(a);
			ms.insert(b);
			if (a >= mid && b >= mid)it++;
			else if (a <= mid && b <= mid)it--;
			ans += *it;
			ans %= 20171109;
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}