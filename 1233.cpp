#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


int main() {
	for (int i = 1; i <= 10; i++)
	{
		int n = 0;
		cin >> n;
		bool ans = 1;
		int node[204] = { 0, };
		int q = 1;
		for (int i = 1; i <= n; i++)
		{
			char op;
			scanf("%*d %c", &op);
			if ((n % 2 == 0 && (i < n / 2)) || (n % 2 == 1 && i <= (n - 1) / 2))
				scanf(" %*d %*d");
			else if (n % 2 == 0 && i == n / 2)
				scanf(" %*d");
			node[i] = op;
		}
		cout << '#' << i << ' ';
		for (int i = 1; i < n; i++)
		{
			if (i < n / 2)
			{
				if (node[i] != '+' && node[i] != '-' && node[i] != '/' && node[i] != '*')
				{
					ans = 0;
					cout << ans << endl;
					break;
				}
			}
			else {
				if (node[i] == '+' && node[i] == '-' && node[i] == '/' && node[i] == '*')
				{
					ans = 0;
					cout << ans << endl;
					break;
				}
			}
		} 
        if(ans==1)
                	cout<<ans<<endl;
	}
	return 0;
}
