#include <iostream>
#include<string>
#include <vector>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int alphabet[26] = { 0, };
		vector<string>v;
		int n = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string a;
			cin >> a;
			v.push_back(a);
			int s = 0;
			while (a[0] != 'A' + s)
			{
				s++;
			}
			alphabet[s]++;
		}
		int ans = 0;
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] != 0)
				ans++;
			else
				break;
		}
		cout <<'#'<<i<<' '<< ans << endl;
	}
}