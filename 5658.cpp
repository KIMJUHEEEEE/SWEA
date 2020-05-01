#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		string str;
		string str1;
		string str2;
		vector<string> v;
		vector<string>pass;
		vector<string> ans;
		int n, k;
		long long sum = 0;
		cin >> n >> k; char one; char two;
		for (int i = 0; i < n; i++)
		{
			char s;
			cin >> s;
			str += s;
			
		}v.push_back(str);
		string qq = ""; 
		for (int nu = 1; nu < n / 4; nu++)
		{
			string qs = "";
			qq = str[str.size() - nu] + qq;qs += qq;
			for (int nn = 0; nn < str.size() - nu ; nn++)
			{
				
				qs+= str[nn];
			}
			v.push_back(qs);
		}
		for (int i = 0; i < n / 4; i++)
		{
			for (int j = 0; j < n; j += n / 4)
			{
				string st = "";
				for (int a = 0; a < n / 4; a++)
				{
					st += v[i][j + a];
				}
				pass.push_back(st);

			}
		}
		sort(pass.begin(), pass.end());
		for (int i = 0; i < pass.size(); i++)
		{
			if (ans.size() > 1)
			{
				if (ans[ans.size() - 1] != pass[i])
					ans.push_back(pass[i]);
			}
			else
				ans.push_back(pass[i]);

		}
		string find = ans[ans.size() - k];
		for (int i = n/4-1; i >= 0; i--)
		{
			if (find[i] - '0' >= 0 && find[i] - '0' <= 9)
				sum += (find[i] - '0') * pow(16, n/4-1 - i);
			else
			{
				if (find[i] == 'A')
					sum += 10 * pow(16, n / 4 - 1 - i);
				else if (find[i] == 'B')
					sum += 11 * pow(16, n / 4 - 1 - i);
				else if (find[i] == 'C')
					sum += 12 * pow(16, n / 4 - 1 - i);
				else if (find[i] == 'D')
					sum += 13 * pow(16, n / 4 - 1 - i);
				else if (find[i] == 'E')
					sum += 14 * pow(16, n / 4 - 1 - i);
				else if (find[i] == 'F')
					sum += 15 * pow(16, n / 4 - 1 - i);
			}
		}
		cout << '#' << tc << ' ' << sum << endl;
	}
}
