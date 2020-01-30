#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for(int i=1;i<=tc;i++)
	{
		int k = 0;
		stack <int> s;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			int n = 0;
			cin >> n;
			if (n != 0)
				s.push(n);
			else if (n == 0)
				s.pop();
		}
		int ans = 0;
		for (int i = 0; i <= s.size(); i++)
		{
			ans += s.top();
			s.pop();
		}
		cout << '#' << i << ' ' << ans << endl;
	}
}