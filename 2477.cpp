#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n, m, k, a, b;
		cin >> n >> m >> k >> a >> b;
		vector<int> v;
		vector<int> ai;
		vector<int>bi;
		vector<pair<int, int>> checka;
		vector<int> checkb;
		ai.resize(n);
		bi.resize(m);
		checka.resize(n);
		checkb.resize(m);
		v.resize(k);
		for (int i = 0; i < n; i++)
		{
			cin >> ai[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> bi[i];
		}
		queue<pair<int, int>> q;
		for (int i = 0; i < k; i++)
		{
			cin >> v[i];
			q.push({ v[i],i + 1 });
		}

		queue<pair<int, int>> qb; int at = -1;
		vector<int> same1;
		int cnt = 0;
		while (1)
		{
			at++;
			for (int i = 0; i < n; i++)
			{
				if (at % (checka[i].first + ai[i]) == 0 && checka[i].second != 0)
				{
					checka[i].first = 0;
					qb.push({ checka[i].second,at });
					checka[i].second = 0;
					cnt++;
				}
				if (checka[i].first == 0 && checka[i].second == 0 && q.size() > 0 && at >= q.front().first)
				{
					int t = q.front().first;
					int tb = q.front().second;
					q.pop();
					if (at == t) checka[i].first = t;
					else if (at > t) checka[i].first = at;
					checka[i].second = tb;
					if (i + 1 == a) same1.push_back(tb);
				}

			}
			if (cnt == k) break;
		}
		at = qb.front().second - 1;
		int ans = 0;
		int x = 0;

		while (qb.size() != 0)
		{
			at++;
			for (int i = 0; i < m; i++)
			{
				if ((at - checkb[i]) % (bi[i]) == 0 && at != checkb[i] && checkb[i] != 0 && bi[i] != 0)
				{
					checkb[i] = 0;
				}
				if (checkb[i] == 0 && qb.front().second <= at&&qb.size()>0)
				{
					int t = qb.front().second;//√ 
					if (t < at) t = at;
					int tn = qb.front().first;//π¯»£
					qb.pop();
					checkb[i] = t;
					if (i + 1 == b)
					{
						for (int s = 0; s < same1.size(); s++)
						{
							if (tn == same1[s])
							{
								ans += tn;
								same1[s] = 0;
								break;
							}
						}
					}
				}
			}
		}
		if (ans == 0) ans = -1;
		cout << '#' << tc << ' ' << ans << endl;
	}
}