#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int arr[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n = 0;
vector<pair<pair<int, int>, int>> v;
queue<pair<int, int>> q;

void sorting()
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[i].second > v[j].second)
			{
				pair<pair<int, int>, int> p = v[i];
				v[i] = v[j];
				v[j] = p;
			}
			else if (v[i].second == v[j].second)
			{
				if (v[i].first.first > v[j].first.first)
				{
					pair<pair<int, int>, int> p = v[i];
					v[i] = v[j];
					v[j] = p;
				}
			}
		}
	}
}

void bfs()
{
	int ans = 0;
	int check[101][101] = { {0}, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				check[i][j] = 1;
			}

		}
	}
	int minx = 0, miny = 0;
	int maxx = 0, maxy = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0 && check[i][j] == 0)
			{
				q.push({ i,j });
				check[i][j] = 1;
				while (q.size() != 0)
				{
					minx = i, miny = j;
					maxx = i, maxy = j;
					int qs = q.size();
					while (qs--) {
						int qx = q.front().first;
						int qy = q.front().second;
						if (qx >= maxx || qy >= maxy)
							maxx = qx, maxy = qy;
						q.pop();
						for (int z = 0; z < 4; z++)
						{
							int x = qx, y = qy;
							while (check[x + dx[z]][y + dy[z]] != 1 && x + dx[z] >= 0 && y + dy[z] >= 0
								&& x + dx[z] < n && y + dy[z] < n)
							{
								x += dx[z], y += dy[z];
								check[x][y] = 1;
								q.push({ x,y });
							}

						}
					}
				}
				v.push_back({ { maxx - minx + 1,maxy - miny + 1 }, (maxx - minx + 1) * (maxy - miny + 1) });
			}

		}
	}
}

int main()
{
	int tc = 0; cin >> tc;
	for (int q = 1; q <= tc; q++)
	{
		v.clear();
		cin >> n;
		int min = 999;
		int max = 0;
		int pm = 0;
		int x = 0; int y = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		bfs();
		sorting();
		cout << '#' << q << ' ' << v.size() << ' ';
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].first.first << ' ' << v[i].first.second << ' ';
		}
		cout << endl;
	}
}