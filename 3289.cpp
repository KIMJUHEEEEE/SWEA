#include<iostream>
#include<vector>
using namespace std;
int arr[1000001];

int solve(int num)
{
	if (arr[num] == num)
		return num;
	arr[num] = solve(arr[num]);
	return arr[num];
}
int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0, m = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			arr[i] = i;
		}
		string ans = "";
		for (int j = 0; j < m; j++)
		{
			int a = 0, b = 0, c = 0;
			cin >> a >> b >> c;
			int ib = solve(b);
			int ic = solve(c);
			if (a == 0)
			{
				arr[ib] = ic;
			}
			else
			{
				if (ib == ic)
					ans += '1';
				else
					ans += '0';
			}
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}