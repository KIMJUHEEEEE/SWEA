#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
#define MOD 1000000007
unsigned long long int arr[1000002];

long long p(long long x, long long y) {
	long long r = 1;
	while (y) {
		if (y & 1) {
			if (r * x > MOD) r = (r * x) % MOD;
			else r *= x;
		}
		if (x * x > MOD) x = (x * x) % MOD;
		else x *= x;
		y >>= 1;
	}

	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	arr[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		arr[i] = (p(i, i) + arr[i - 1]) % MOD;
	}
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0;
		cin >> n;
		cout << '#' << i << ' ' << arr[n] << '\n';
	}
}