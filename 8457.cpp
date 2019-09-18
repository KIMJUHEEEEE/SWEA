#include <iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, b, e;
		cin >> n>>b>>e;
		int min = b - e;
		int max = b + e;
		int arr[101] = { 0, };
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int answer = 0;
		for (int i = 0; i < n; i++)
		{int a = 1;
		while (max >= a *arr[i])
		{
			if (arr[i] * a >= min && arr[i] * a <= max)
			{
				answer++;
				break;
			}
			else
			{
				a++;
			}
		}

		}
		cout << '#' << t << ' ' << answer<<endl;
	}
}
