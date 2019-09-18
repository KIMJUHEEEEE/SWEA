#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		cin >> n;
		int ans = n;
		int arr[10001] = { 0, };
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++)
		{
			ans += arr[i];
		}
		ans += arr[n-1];
		cout << '#' << i << ' ' << ans<<endl;
	}
}