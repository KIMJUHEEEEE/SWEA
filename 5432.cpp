#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	int a = 0;
	stack<char> s;
	for (int i = 0; i < arrangement.size() - 1; i++)
	{
		if (arrangement[i] == '(' && arrangement[i + 1] == '(')
		{
			s.push(arrangement[i]);
		}
		else if (arrangement[i] == ')' && arrangement[i + 1] == ')')
		{
			s.pop();
			answer++;
		}
		else if (arrangement[i] == '(' && arrangement[i + 1] == ')')
		{
			answer += s.size();
		}
	}
	return answer;
}
int main()
{
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << '#' << i << ' ';
		string arrangement;
		cin >> arrangement;
		cout << solution(arrangement) << endl;
	}
}