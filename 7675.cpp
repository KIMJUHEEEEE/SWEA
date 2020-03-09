#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int tc = 0; cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		vector<string> v;
		vector<int> vn;
		int n = 0; cin >> n;
		for (int j = 0; j < n; j++)
		{
			string a;
			int num = 0;
			while (v.size() < n)
			{
				string str;
				bool check=0;
				cin >> str;
				str += ' ';
				a += str;
				if (str[0] >= 'A' && str[0] <= 'Z')
				{
					check = 1;
					for (int z = 1; z < str.size()-1; z++)
					{
						if (str[z] >= 'a' && str[z] <= 'z')
						{
							check = 1;
						}
						else if (str[z] == '?' || str[z] == '!' || str[z] == '.')
						{
							check = 1;
							break;
						}
						else {
							check = 0;
							break;
						}
					}
				}
				if (check == 1)num++;
				if (str[str.size() - 2] == '.' || str[str.size() - 2] == '?' || str[str.size() - 2] == '!')
				{
					v.push_back(a); a = "";
					vn.push_back(num); num = 0;
				}
			}
		}
		cout << '#' << i << ' ';
		for (int z = 0; z < v.size(); z++)
		{
			cout << vn[z] << ' ';
		}
		cout << endl;
	}
}