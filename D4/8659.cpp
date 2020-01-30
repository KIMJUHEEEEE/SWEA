#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
#include<cmath>
#include <stdio.h>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	unsigned long long int arr[93][2] = { { 0}, };
	arr[0][0] = 1, arr[0][1] = 1;
	arr[1][0] = 2, arr[1][1] = 1;
	for (int i = 2; i <= 90; i++)
	{
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];

	}
	for (int i = 1; i <= tc; i++)
	{
		int k = 0;
		cin >> k;
		cout << '#' << i << ' ' << arr[k][0] << ' ' << arr[k][1] << endl;
	}
}