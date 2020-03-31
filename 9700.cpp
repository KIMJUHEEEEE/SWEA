#include<iostream>
using namespace std;

int main()
{
	int t = 0; cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		float p, q;
		cin >> p >> q;
		float s1 = 1 - p;
		float s2 = p * (1-q);
		cout << '#' << tc << ' ';
		if (s1 < s2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}