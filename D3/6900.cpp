#include<iostream>
#include<algorithm>
#include <vector>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<string>v;
		vector<int> mon;		int ans=0;
		for (int i = 0; i < n; i++)
		{
			string a;
			int mo;
			cin >> a>>mo;
			v.push_back(a);
			mon.push_back(mo);
		}
		for (int i = 0; i < m; i++)
		{
			string a;
			cin >> a;
	
			for (int j = 0; j < n; j++)
			{int k = 0;
				if (a.size() == v[j].size())
				{
					
					while (k<a.size())
					{
						if (v[j].at(k) != '*')
						{
							if (a[k] != v[j].at(k))
								break;
							else
								k++;
						}
						else
							k++;
					}
				}
				if (a.size() == k)
				{
					ans += mon[j];
				}
			}
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}