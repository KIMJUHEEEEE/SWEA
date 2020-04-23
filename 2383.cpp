#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
int map[11][11];
vector<pair<pair<int, int>, int>> stairs;
vector<pair<int, int>> person;
queue<int> s1;
queue<int> s2;
int st1[11];
int st2[11];
int cst1[11];
int cst2[11];
int n;
int ans = 999999999;
void solve(int cnt, int sn)
{

	if (cnt == person.size())
	{
		int a = 0, b = 0;
		sort(st1, st1 + 10);
		sort(st2, st2 + 10);
		for (int i = 0; i < 10; i++)
		{
			if (st1[i] > 0)
			{
				if (s1.size() < 3)
					s1.push(st1[i]);
				else
				{
					if (s1.front() + stairs[0].second < st1[i])
					{
						s1.push(st1[i]);
					}
					else
						s1.push(s1.front() + stairs[0].second);
					s1.pop();
				}
			}
		}
		for (int j = 0; j < 10; j++)
		{
			if (st2[j] > 0)
			{
				if (s2.size() < 3)
					s2.push(st2[j]);
				else
				{
					if (s2.front() + stairs[1].second < st2[j])
						s2.push(st2[j]);
					else
						s2.push(s2.front() + stairs[1].second);
					s2.pop();
				}
			}
		}
		while (s1.size() > 1)
		{
			s1.pop();
		}
		while (s2.size() > 1)
		{
			s2.pop();
		}
		if (s1.size() > 0)
		{
			a = s1.front() + stairs[0].second;
			s1.pop();
		}
		if (s2.size() > 0)
		{
			b = s2.front() + stairs[1].second;
			s2.pop();
		}
		if (a >= b)
		{
			if (ans > a)
				ans = a;
		}
		else
		{
			if (ans > b)
				ans = b;
		}
		return;
	}
	int d = 0;
	int x = person[cnt].first;
	int y = person[cnt].second;
	d += (abs(x - stairs[sn].first.first) + abs(y - stairs[sn].first.second));
	if (sn == 0)
	{
		st1[cnt] = d + 1;
		cst1[cnt] = d + 1;
	}
	else
	{
		st2[cnt] = d + 1;
		cst2[cnt] = d + 1;
	}
	solve(cnt + 1, 0);
	cst1[cnt + 1] = 0; cst2[cnt + 1] = 0;
	copy(cst1, cst1 + 10, st1);
	copy(cst2, cst2 + 10, st2);
	solve(cnt + 1, 1);
	cst1[cnt + 1] = 0; cst2[cnt + 1] = 0;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		cin >> n;
		ans = 9999999;
		person.clear();
		stairs.clear();
		memset(map, 0, sizeof(map));
		memset(st1, 0, sizeof(st1));
		memset(cst1, 0, sizeof(cst1));
		memset(st2, 0, sizeof(st2));
		memset(cst2, 0, sizeof(cst2));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1) person.push_back({ i,j });
				else if (map[i][j] >= 2) stairs.push_back({ {i,j},map[i][j] });
			}
		}
		solve(0, 0);
		memset(st1, 0, sizeof(st1));
		memset(cst1, 0, sizeof(cst1));
		memset(st2, 0, sizeof(st2));
		memset(cst2, 0, sizeof(cst2));
		solve(0, 1);
		cout << '#' << tc << ' ' << ans << endl;
	}
}
