#include<iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		float d, a, b, f;
		cin >> d >> a >> b >> f;
		cout<<fixed;
		cout.precision(7);
		float ans = d / (a + b) * f;
		cout << '#' << i << ' ' << ans<<endl;
	}
}
