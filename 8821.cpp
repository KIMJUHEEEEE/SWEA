#include<iostream>
#include<string>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;

	for (int i = 1; i <= tc; i++)
	{	int arr[10] = { 0, };
		string a;
		cin >> a;
		for (int i = 0; i < a.size(); i++)
		{
			if (arr[a[i] - 48] == 0)
			{
				arr[a[i] - 48] = 1;
			}
			else
				arr[a[i] - 48] = 0;
		}
		int ans = 0;
		for (int i = 0; i < 10; i++)
		{
			if (arr[i] != 0)
				ans++;
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}