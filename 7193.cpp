#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		string a;
		cin >> n >> a;
		unsigned long long int sum = 0;
		int ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			sum += a[i] - 48;
		}
		cout << '#' << i << ' ' << sum % (n - 1) << endl;
	}
}
