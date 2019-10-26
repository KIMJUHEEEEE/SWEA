#include<iostream>
#include<string>
using namespace std;

int main() {
	int t = 0;
	cin >> t; 
	for (int i = 1; i <= t; i++)
	{
		string ans = "";
		for (int i = 0; i < 3; i++)
		{
			string a;
			cin >> a;
			ans += toupper(a[0]);
		}
		cout << '#' << i << ' ' << ans << endl;
	}
	
}