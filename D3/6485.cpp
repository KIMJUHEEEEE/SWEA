#include<iostream>>
#include <vector>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n = 0, p = 0, c = 0, a = 0, b = 0;
		cin >> n;
		int arr[5001] = { 0, };
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			for (int i = a; i <= b; i++)
			{
				arr[i]++;
			}

		}
		cin >> p;
		cout << '#' << i << ' ';
		for (int i = 0; i < p; i++)
		{
			cin >> c;
			cout << arr[c]<<' ';

		}
		cout << endl;
	}
}
