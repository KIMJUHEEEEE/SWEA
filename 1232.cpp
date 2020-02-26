#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	int tc = 10;
	//cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0;
		cin >> n;
		stack<pair<int, pair<char, pair<int, int>>>> s;
		vector<float> nu;
		nu.resize(n+1);
		for (int i = 1; i <= n; i++)
		{
			int a = 0;
			cin >> a;
			string b;
			cin >> b;
			if (b[0] == '-' || b[0] == '+' || b[0] == '/' || b[0] == '*')
			{
				int c = 0, d = 0;
				cin >> c >> d;
				s.push({ i,{ b[0],{c,d}} });
			}
			else
			{
				int e = 0;
				for (int i = 0; i < b.size(); i++)
				{
					e += (b[i] - 48) * pow(10, b.size() - 1 - i);
				}
				nu[i] = e;
			}
		}
		while (s.size() != 0)
		{
			float a = nu[s.top().second.second.first];
			float b = nu[s.top().second.second.second];
			char o = s.top().second.first;
			int k = s.top().first;
			s.pop();
			if (o == '-')
			{
				a = a-b;
			}
			else if (o == '+')
			{
				a = a + b;
			}
			else if (o == '/')
			{
				a = a / b;
			}
			else if (o == '*')
			{
				a = a * b;
			}
			nu[k] = a;
		}
		cout << '#' << i << ' ' << (int)nu[1] << endl;
	}
}