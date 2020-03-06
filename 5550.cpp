#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int croak[5] = { 0, };
		string str;
		cin >> str;
		bool c = 0;
		cout << '#' << i << ' ';
		int ans = 0;
		croak[0]++;
		ans++;
		for (int j = 1; j < str.size(); j++)
		{

			if (str[j] == 'c')
			{
				croak[0]++;

			}
			else if (str[j] == 'r')
			{
				croak[1]++;
				croak[0]--;
				if (croak[0] == -1)
				{
					c = 1;
					break;
				}
			}
			else if (str[j] == 'o')
			{
				croak[2]++;
				croak[1]--;
				if (croak[1] == -1)
				{
					c = 1;
					break;
				}
			}
			else if (str[j] == 'a')
			{
				croak[3]++;
				croak[2]--;
				if (croak[2] == -1)
				{
					c = 1;
					break;
				}
			}
			else if (str[j] == 'k')
			{
				croak[3]--;
				if (croak[3] == -1)
				{
					c = 1;
					break;
				}
			}
			ans = max(ans, croak[0] + croak[1] + croak[2] + croak[3]);
		}

		if (croak[0] != 0 || croak[1] != 0 || croak[2] != 0 || croak[3] != 0)
			c = 1;
		if (c == 1)
			ans = -1;
		cout << ans << endl;
	}
}