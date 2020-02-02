#include<iostream>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	long long int arr[101] = { 0, };
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	for (int i = 5; i <= 100; i++)
	{
		arr[i] = arr[i - 3] + arr[i - 2];
	}
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		cin >> n;
		cout << '#' << i << ' ' << arr[n] << '\n';
	}
}