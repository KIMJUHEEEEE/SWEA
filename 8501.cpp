#include<iostream>
#include<vector>

using namespace std;
vector<long long int> v;

void an() {
	v.push_back(0);
	long long int m = 1;
	for (int i = 1; i <= 1000; i++)
	{
		unsigned long long int a = (i * v[i - 1]%1000000007 + i / 2 * m);
		v.push_back(a%1000000007);
		m *= i;
		m %= 1000000007;
	}
}
int main() {
	int tc = 0;
	cin >> tc;
	an();
	for (int i = 1; i <= tc; i++)
	{
		int l = 0;
		cin >> l;
		cout << '#' << i << ' ' << v[l] << endl;
	}

}