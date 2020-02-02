#include<iostream>
#include<string>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string ans = "";
		string write = "";
		int n = 0;
		cin >> n;
		cin >> ans;
		cin >> write;
		int num = 0;
		for (int i = 0; i < ans.size(); i++)
		{
			if (ans[i] == write[i])
				num++;
		}
		cout << '#' << i << ' ' << num << endl;
	}
}

