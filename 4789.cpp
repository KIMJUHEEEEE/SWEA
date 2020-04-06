#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		string a;
		cin >> a;
		int l = a.size();
		int m = 0;
		int ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == '0') continue;
			else if (m >= i) m += (a[i] - '0');
			else
			{
				ans += (i - m);
				m += (i - m);
				m += (a[i] - '0');
			}
		}
		cout << '#' << tc << ' ' << ans << endl;
	}
}