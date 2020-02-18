#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string str;
		cin >> str;
		int sum = 0;
		stack<int>st;
		for (int j = 0; j < str.size(); j++)
		{
			st.push(str[j] - '0');
		}
		int turn = 0; 
		cout << '#' << i << ' ';
		while (st.size() > 1)
		{
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			if (a + b > 9)
			{
				st.push((a + b) / 10);
				st.push((a + b) % 10);
			}
			else
			{
				st.push(a + b);
			}
			if (turn == 0)
				turn = 1;
			else
				turn = 0;
		}
		if (turn == 0)
			cout << 'B' << endl;
		else
			cout << 'A' << endl;
	}
}