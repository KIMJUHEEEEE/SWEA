#include<iostream>
#include<vector>
using namespace std;

int main() {
	int t = 0;
	cin >> t; 
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		cin >> n;
		int k = pow(2, n);
		int a = 0;
		vector<int> v;
		for (int i = 0; i < k; i++)
		{
			cin >> a;
			v.push_back(a);
		}
		int ans = 0;
		while (k > 0) {
			int s = 0;
			for (int i = 0; i < k - 1; i += 2)
			{
				if (v[i] > v[i + 1])
				{
					ans += v[i] - v[i + 1];
					v[s] = v[i];
				}
				else
				{
					ans += v[i + 1] - v[i];
					v[s] = v[i + 1];
				} s++;
			}
			k /= 2;
		}
		cout << '#' << i << ' ' <<ans<< endl;
	}
}
