#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		vector<string> v;
		vector<int> vn;
		vector<pair<string, int>> vp;
		int n = 0;
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string str =" ";

			getline(cin,str);
			v.push_back(str);
		}
		cout << '#' << i << ' ';
		int max = 0;
		for (int i = 0; i < n; i++)
		{		int al[26] = { 0, };		int num = 0;
			for (int j = 0; j < v[i].size(); j++)
			{
				for (int z = 0;z < 26; z++)
				{
					if (v[i][j] == 'A' + z)
					{
						if(al[z]!=0)
							break;
						else
						{
							al[z]++;
							num++;
							break;
						}
					}
					
				}
			}
			if (max < num)
				max = num;
			vn.push_back(num);
		}
		for (int i = 0; i < n; i++)
		{
			vp.push_back({ v[i],vn[i] });
		}
		sort(vp.begin(), vp.end());
		for (int i = 0; i < n; i++)
		{
			if (vp[i].second == max)
			{
				cout << vp[i].first << endl;
				break;
			}
		}
	}
}