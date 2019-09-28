#include<iostream>
#include<algorithm>
#include <vector>
#include<string>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] == b[0]&&i<=a.size()-b.size())
			{
				string v="";
				int n = 0;
				while (1)
				{
					v += a[i + n];
					if (n == b.size()-1)
						break;
					n++;
				}
				if (v == b)
				{
					ans++;
					i += b.size();
					i--;
				}
				else
					ans++;
			}
			else
				ans++;
		}
		cout <<'#'<<i<<' '<< ans<<endl;
	}
}