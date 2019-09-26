#include<iostream>
#include<algorithm>
#include <vector>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		cin >> n;
		vector<string> v;
		vector<string>v1;
		for (int i = 0; i < n; i++)
		{
			string a;
			cin >> a;
			if ((n%2==0&&i<n/2)||n%2==1&&i<=n/2)
			{
				v.push_back(a);
			}
			else
				v1.push_back(a);
		}
		for (int i = 0; i < v1.size(); i++)
		{
				cout << v[i] << ' ' << v1[i]<<' ';
			if((v.size()>v1.size()&&i==v1.size()-1))
				cout << v[++i];
		}
		cout << endl;
	}
}