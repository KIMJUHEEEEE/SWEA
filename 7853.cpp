#include<iostream>
#include<string>
using namespace std;
int main()
{
	int tc = 0; cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string str;
		cin >> str;
		long long ans = 1;
		for (int i = 0; i < str.size(); i++)
		{
			ans %= 1000000007;
			if (i == 0)
			{
				if (str[i] != str[i + 1])
				{
					ans *= 2; ans %= 1000000007;
				}
			}
			else if (i == str.size() - 1)
			{
				if (str[i - 1] != str[i])
				{
					ans *= 2; ans %= 1000000007;
				}
			}
			else
			{
				if (str[i - 1] == str[i] && str[i] != str[i + 1] || str[i - 1] != str[i] && str[i] == str[i + 1]
					|| str[i - 1] == str[i + 1] && str[i] != str[i - 1])
				{
					ans *= 2; ans %= 1000000007;
				}
				else if (str[i - 1] != str[i] && str[i] != str[i + 1])
				{
					ans *= 3; ans %= 1000000007;
				}
			}
		}
		cout << '#' << i << ' ' << ans % 1000000007 << endl;
	}
}