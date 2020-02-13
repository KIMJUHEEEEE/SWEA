#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string str2;
		string str3;
		cin >> str2 >> str3;
		vector<int> v2;

		for (int j = 0; j < str2.size(); j++)
		{
			int ans = 0;
			string str = str2;
			if (str[j] == '0')
				str[j] = '1';
			else
				str[j] = '0';
			for (int z = 0; z < str2.size(); z++)
			{
				ans += pow(2, z) * (str[str2.size() - z - 1] - 48);
			}
			v2.push_back(ans);
		}
		vector<int> v3;
		for (int j = 0; j < str3.size(); j++)
		{
			int ans = 0;
			string str = str3;
			if (str[j] == '0')
			{
				str[j] = '1';
				for (int z = 0; z < str3.size(); z++)
				{
					ans += pow(3, z) * (str[str3.size() - z - 1] - 48);
				}
				v3.push_back(ans);
				ans = 0;
				str[j] = '2';
				for (int z = 0; z < str3.size(); z++)
				{
					ans += pow(3, z) * (str[str3.size() - z - 1] - 48);
				}
				v3.push_back(ans);
			}
			else if (str[j] == '1')
			{
				str[j] = '0';
				for (int z = 0; z < str3.size(); z++)
				{
					ans += pow(3, z) * (str[str3.size() - z - 1] - 48);
				}
				v3.push_back(ans);
				ans = 0;
				str[j] = '2';
				for (int z = 0; z < str3.size(); z++)
				{
					ans += pow(3, z) * (str[str3.size() - z - 1] - 48);
				}
				v3.push_back(ans);
			}
			else
			{
				str[j] = '1';
				for (int z = 0; z < str3.size(); z++)
				{
					ans += pow(3, z) * (str[str3.size() - z - 1] - 48);
				}
				v3.push_back(ans);
				ans = 0;
				str[j] = '0';
				for (int z = 0; z < str3.size(); z++)
				{
					ans += pow(3, z) * (str[str3.size() - z - 1] - 48);
				}
				v3.push_back(ans);
			}
		}
		bool check = 0;
		for (int k = 0; k < v2.size(); k++)
		{
			for (int j = 0; j < v3.size(); j++)
			{
				if (v2[k] == v3[j])
				{
					cout << '#' << i << ' ' << v2[k] << '\n';
					check = 1;
					break;
				}
			}
			if (check == 1)
				break;
		}
	}
}