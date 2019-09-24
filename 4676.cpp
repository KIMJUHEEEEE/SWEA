#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string a;
		cin >> a;
		int h = 0;
		cin >> h;
		int arr[101] = { 0, };
		int k = 0;
		for (int i = 0; i < h; i++)
		{
			cin >> k;
			arr[k]++;
		}
		string ans = "";
		for (int i = 0; i <= a.size(); i++)
		{

			if (arr[i] != 0)
			{
				while (1)
				{
					ans += '-';
					arr[i]--;
					if (arr[i] == 0)
						break;
				}
			}
			if(i<a.size())
				ans += a[i];
		}
		
		cout << "#" << i << ' ' << ans << endl;
	}
}
