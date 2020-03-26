#include<iostream>
#include<string>
#include<math.h>
using namespace std;

long long solve(string a)
{
	long long ans = 0;
	for (int i = a.size()-1; i >= 0; i--)
	{
		ans += (pow(9, a.size() - i-1)*(a[i]-48));
	}
	return ans;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int tc = 1; tc <=t; tc++)
	{
		string a, b;
		cin >> a >> b;
		int ma = 0, mb = 0;
		if (a[0] == '-')
		{
			ma = 1;
			for (int i = 0; i < a.size() - 1; i++)
			{
				a[i] = a[i + 1];
			}
			a.resize(a.size() - 1);
		}
		if (b[0] == '-')
		{
			mb = 1;
			for (int i = 0; i < b.size() - 1; i++)
			{
				b[i] = b[i + 1];
			}
			b.resize(b.size() - 1);
		}
		
		for (int i = 0; i < a.size(); i++)
		{
			
			if (a[i] > '4')
				a[i]--;
			
		}
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] > '4')
				b[i]--;
		}
		long long ca = solve(a);
		long long cb = solve(b);
		cout << '#' << tc<< ' ';
		if (ma == mb)
		{
			if (ma == 0)
				cout << cb - ca << endl;
			else
				cout << ca - cb << endl;
		}
		else
			cout << cb + ca - 1 << endl;
	}
}
