#include<iostream>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		long long n = 0;
		cin >> n;
		int k = n;
		cout << '#' << i << ' ';
		while (n > 1)
		{
			if (n % 2 == 0)
				n = n / 2;
			else
				break;
		}
		if (n == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
