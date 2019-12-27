#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string str;
		cin >> str;
		int arr[3] = { 0, };
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == 'a')
				arr[0]++;
			else if (str[i] == 'b')
				arr[1]++;
			else
				arr[2]++;
		}
		cout << '#' << i << ' ';
		int a = arr[0], b = arr[1], c = arr[2];
		sort(arr, arr + 3);
		if (arr[2] - arr[0] <= 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}