#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int n, k, m;
int arr[101][101];
int map[101][101];
int sum;
queue<pair<pair<pair<int, int>, int>, int>> q;
vector<pair<pair<pair<int, int>, int>, int>> v;
//1,2,3,4=╩С,го,аб,©Л
void sort()
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].first.second > v[j].first.second)
			{
				pair<pair<pair<int, int>, int>, int> tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
}
int check(int x, int y)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].first.first.first == x && v[i].first.first.second == y)
			return  i;
	}
	return -1;
}
void solve(int num)
{
	while (num > 0)
	{
		sort();
		for (int i = 0; i < v.size(); i++)
		{
			q.push(v[i]);
		}
		v.clear();
		int qs = q.size();
		while (qs--)
		{
			int x = q.front().first.first.first;
			int y = q.front().first.first.second;
			int nu = q.front().first.second;
			int d = q.front().second;
			q.pop();
			arr[x][y] = 0;
			if (d == 1)
			{
				x -= 1;
				if (x == 0)
				{
					nu /= 2;
					d = 2;
				}
				int c = check(x, y);
				if (c == -1)
					v.push_back({ {{x,y},nu},d });
				else
				{
					v[c].second = d;
					v[c].first.second += nu;
				}
				map[x][y] += nu;
			}
			else if (d == 2)
			{
				x += 1;
				if (x == n - 1)
				{
					nu /= 2;
					d = 1;
				}
				int c = check(x, y);
				if (c == -1)
					v.push_back({ {{x,y},nu},d });
				else
				{
					v[c].second = d;
					v[c].first.second += nu;
				}
				map[x][y] += nu;
			}
			else if (d == 3)
			{
				y -= 1;
				if (y == 0)
				{
					nu /= 2;
					d = 4;
				}
				int c = check(x, y);
				if (c == -1)
					v.push_back({ {{x,y},nu},d });
				else
				{
					v[c].second = d;
					v[c].first.second += nu;
				}
				map[x][y] += nu;
			}
			else if (d == 4)
			{
				y += 1;
				if (y == n - 1)
				{
					nu /= 2;
					d = 3;
				}
				int c = check(x, y);
				if (c == -1)
					v.push_back({ {{x,y},nu},d });
				else
				{
					v[c].second = d;
					v[c].first.second += nu;
				}
				map[x][y] += nu;
			}
		}
		num--;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = map[i][j];
			}
		}
		memset(map, 0, sizeof(map));
	}
	sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i].first.second;
	}
}

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		memset(arr, 0, sizeof(arr));
		v.clear();
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y, c, d;
			cin >> x >> y >> c >> d;
			arr[x][y] = c;
			v.push_back({ { {x,y},c},d });
		}
		solve(m);
		cout << '#' << tc << ' ' << sum << endl;
	}
}