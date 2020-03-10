#include<iostream>
#include<string.h>
using namespace std;
int node[205];

void dfs(int index)
{
	if (node[index] == 0)
		return;
	dfs(index * 2);
	printf("%c", node[index]);
	dfs(index * 2 + 1);
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		int n;
		cin >> n;
		memset(node, 0, sizeof(node));
		for (int j = 1; j <= n; j++)
		{
			char o;
			scanf("%*d %c", &o);
			if ((n % 2 == 0 && (j < n / 2)) || (n % 2 == 1 && j <= (n - 1) / 2))
				scanf(" %*d %*d\n");
			else if (n % 2 == 0 && j == n / 2)
				scanf(" %*d\n");
			node[j] = o;
		}
		printf("#%d ", i);
		dfs(1);
		printf("\n");
	}
}