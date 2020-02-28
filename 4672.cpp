#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int arr[26];
int m;
int x;
int solve(int n)
{	int k = 0;
	string str;
	str.resize(n);
	int s = 0;
	int e = n - 1;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == 1)
		{
			str[s] = 'a' + i;
			s++;
		}
		else if (arr[i] % 2 == 1&&arr[i]!=m)
		{
			str[s] = 'a' + i;
			s++;
			k += arr[i] / 2;
		}
		else if (arr[i] % 2 == 0 && arr[i] != m && arr[i] > 0)
		{

			k += arr[i] / 2;
		}
		else if (arr[i] == m && i != x)
		{
			k += arr[i] / 2;
		}
	}


	while (m--)
	{
		str[s] = 'a' + x;
		s++;
		k += m;
	}


	return k;
}

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		memset(arr, 0, sizeof(arr));
		string a =" ";
		cin >> a;
		int ans = a.size();
		bool check = 0;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < 26; j++)
			{
				if (a[i] == 'a' + j)
				{
					arr[j]++;
					if (arr[j] > m)
					{
						m = arr[j];
						x = j;
					}
					if (arr[j] > 1)
						check = 1;
					break;
				}
			}
		}
		if (check == 0)
		{
			cout << '#' << i << ' ' << ans << endl;
		}
		else
		{
			cout<<'#'<<i<<' '<<ans+solve(a.size())<<endl;
		}
	}
}