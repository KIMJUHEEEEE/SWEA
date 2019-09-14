#include <iostream>
#include <string>
using namespace std;

int sol(char a)
{
	if (a == 'A' || a == 'D' || a == 'O' || a == 'P' || a == 'Q' || a == 'R')
		return 1;
	else if (a == 'B')
		return 2;
	else
		return 0;
}
int main() {
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		string a, b;
		cin >> a >> b;
		printf("#%d ", i);
		if (a.size() != b.size())
		{
			printf("DIFF\n");
			continue;
		}
		else
		{
			int ss = 0;
			for (int j = 0; j < a.size(); j++)
			{
				if (sol(a[j]) != sol(b[j]))
				{
					printf("DIFF\n");
					break;
				}
				else
					ss++;
			}
			if (ss == a.size())
				printf("SAME\n");
		}
	}
}
