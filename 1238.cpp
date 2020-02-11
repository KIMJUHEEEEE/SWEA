#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
queue <int> q;
int maxn;
int arr[101][101];
vector<int> v;
void bfs()
{
	while (q.size() != 0)
	{
		int qs = q.size();
		int ncnt = 0;
		v.clear();
		while (qs--)
		{
			int a = q.front();
			int cnt = 0;
			for (int j = 1; j <= maxn; j++)
			{
				if (arr[a][j] == 1)
				{
					q.push(j);
					for (int i = 1; i <= maxn; i++)
						arr[i][j] = 0;
					cnt++;
				}
			}
			if (cnt > 0)
			{
				q.pop();
				v.clear();
			}
			if (cnt == 0)
			{

				v.push_back(a);
				q.pop();
			}
		}

	}
}

int main()
{
	int tc = 10;
	//cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		memset(arr, 0, sizeof(arr));
		int n = 0;
		int m = 0;
		cin >> n >> m;

		for (int i = 0; i < n / 2; i++)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			arr[a][b] = 1;
			if (a > maxn)
				maxn = a;
			if (b > maxn)
				maxn = b;
		}
		q.push(m);
		for (int i = 1; i <= maxn; i++)
			arr[i][m] = 0;
		bfs();
		cout << '#' << i << ' ';
		sort(v.begin(), v.end());
		cout << v[v.size() - 1] << endl;
	}
}