#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int tc = 0; cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		queue<char> q;
		int a[50003] = { 0, };
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			if (a[i] > a[i + 1])
				q.push('>');
			else
				q.push('<');
		}
		int qs = q.size(); int ans = 0;
		while (q.size()>0)
		{
			bool check = 0;
			char c = '<';
			int u = 0, l = 0;
			while (q.front() == c)
			{
				u++; q.pop();
				check = 1;
				if (q.size() == 0)
					break;
			}
			if (q.size() == 0)
			{
				break;
			}
			while (q.front() =='>')
			{
					if (check == 1)
					{
						l++;
					}
					q.pop();
					
					if (q.size() == 0)
						break;
			}
			check = 0;
			ans += (u * l);
			u = 0, l = 0;
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}
