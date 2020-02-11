#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int tc = 0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(NULL);
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int a = 0;
		cin >> a;
		long long ans = a / 2;
		cout << '#' << i << ' ' << ans * ans << '\n';
	}

}