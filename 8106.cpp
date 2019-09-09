#include<iostream>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		long long N = 0;
		cin >> N;
		long long ans = 2 * N * N - 1;
		cout <<'#'<<i<<' '<< ans-(4*(N-1))<<' '<<ans<<endl;
	}
}