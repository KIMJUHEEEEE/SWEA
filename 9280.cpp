#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		int r[102] = { 0, };
		int p[102] = { 0, };
		int w[2002] = { 0, };
		for (int i = 1; i <= n; i++)
		{
			cin >> r[i];
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> w[i];
		}
		long long sum = 0;
		queue<int> q;
		for (int i = 1; i <= m * 2; i++)
		{
			int k = 0;
			cin >> k;
			if (k > 0)
			{
				q.push(k);
				for (int i = 1; i <= n; i++)
				{
					if (p[i] == 0)
					{
						p[i] = k;
						sum += r[i] * w[k];
						q.pop();
						break;
					}
				}
			}
			if (k < 0)
			{
				for (int i = 1; i <= n; i++)
				{
					if ((k * (-1)) == p[i])
					{
						if (q.size() != 0)
						{
							sum += r[i] * w[q.front()];
							p[i] = q.front();
							q.pop();
						}
						else
							p[i] = 0;
					}
				}
			}
		}
		cout << '#' << i << ' ' << sum << endl;
	}
}