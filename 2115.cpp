#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;
int map[10][10];
int arr[10][10];
int n, m, c, d;
int ans;
int sum;
vector<pair<int, pair<int, int>>> v;//Á¦°öÇÕ, Ã¹ ¹úÅë ÁÂÇ¥
void put(int a, int i, int j, int cnt, int d)
{

	a += map[i][j + cnt];
	d += (map[i][j + cnt] * map[i][j + cnt]);
	if (cnt == m) return;
	if (j >= n) return;
	if (a <= c)
		v.push_back({ d,{i,j} });
	put(a, i, j, cnt + 1, d);
	put(a - map[i][j + cnt], i, j, cnt + 1, d - (map[i][j + cnt] * map[i][j + cnt]));
}
void chek(int a)
{
	ans = 0;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j <= n - m; j++)
		{
			int cnt = 0;
			int sum = 0;
			int d = 0;
			put(sum, i, j, cnt, d);
		}
	}
}
void solve(int a)
{
	chek(a);
	sort(v.begin(), v.end());
	ans = 0; int ccnt = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		int ct = 0;
		int x = v[i].second.first;
		int y = v[i].second.second;
		bool check = 0;
		while (ct < a)
		{
			if (arr[x][y + ct] == 1)
			{
				int s = 0;
				while (s < ct)
				{
					arr[x][y + s] = 0;
					s++;
				}
				check = 0;
				break;
			}
			else {
				arr[x][y + ct] = 1;
				ct++;
				check = 1;
			}
		}
		if (check == 1) {
			ans += v[i].first;
			ccnt++;
			if (ccnt == 2) return;
		}
	}

}

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		v.clear();
		memset(map, 0, sizeof(map));
		memset(arr, 0, sizeof(arr));
		cin >> n >> m >> c;
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
			{
				cin >> map[x][y];
			}
		}
		solve(m);
		cout << '#' << tc << ' ' << ans << endl;
	}
}