#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
vector<long long> cow;
vector<long long> horse;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		long long c1 = 0, c2 = 0;
		cin >> c1 >> c2;
		long long c = abs(c2 - c1); long long a = 0; long long b = 0;
		cow.clear();
		horse.clear();
		cow.resize(n);
		horse.resize(m);
		for (int i = 0; i < n; i++)
		{
			cin >> cow[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> horse[i];
		}
		long long min = 99999999; int num = 1;
		sort(cow.begin(), cow.end());
		sort(horse.begin(), horse.end());
		int cow_pt = 0, horse_pt = 0;
		while (true) {
			if (cow_pt >= cow.size() || horse_pt >= horse.size())
				break;
			int ret = abs(cow[cow_pt] - horse[horse_pt]);
			if (ret < min) {
				min = ret;
				num = 1;
			}
			else if (ret == min) {
				num++;
			}

			if (cow[cow_pt] < horse[horse_pt]) {
				cow_pt++;
			}
			else {
				horse_pt++;
			}
		}
		cout << '#' << i << ' ' << min + c << ' ' << num << '\n';
	}
}