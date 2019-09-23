#include <iostream>
#include <string>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int n = 0;
		cin >> n;
		string a;
		getline(cin, a);
		for (int i = 0; i < a.size(); i++)
		{
			int num = 0;
			int ans = 0;
			if (a[i]>='A'&&a[i]<='Z')
				{
				if (i == 0 || a[i - 1] == ' ')
				{
					num++;
					while (a[i] != ' ' && a[i] != '!' && a[i] != '.' && a[i] != '?')
					{
						i++;
						if (a[i] >= 'a' && a[i] <= z)
						{
							num++;
						}
						else
						{
							ans = 0;
							break;
						}
					}
					if (num == a.size())
				}		ans++;
				}
			}
		cout << ans << ' ';
		ans = 0;
		}
	cout << endl;
	}
}
