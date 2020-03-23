#include<iostream>
#include<string>
#include<vector>
#include<memory.h>
#include<stack>
using namespace std;
vector<string> v;
vector<int> vi;
stack<int> s;
int n;	int m = 9999;
int a;
int arr[10];
void mk()
{
	int a = 0;
	for (int i = 0; i < vi.size(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[j] == 1)
			{
				if (vi[i] * 10 + j > n) return;
				vi.push_back(vi[i] * 10 + j);
				s.push(vi[i] * 10 + j);
			}
		}
	}

}

int main()
{
	int tc = 0; cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		memset(arr, 0, sizeof(arr));
		int cnt = 0;
		for (int j = 0; j <= 9; j++)
		{
			cin >> arr[j];
			if (arr[j] == 1)
			{
				//v.push_back(to_string(j));
				if (j != 0)
				{
					vi.push_back(j);
					s.push(j);
				}
				cnt++;
			}
		}
		cin >> n;
		if (cnt == 10)
		{
			cout << '#' << i << ' ' << to_string(n).size() + 1 << endl;
			vi.clear();
			//v.clear();
		}
		else if (n == 1 && arr[1] == 1)
			cout << '#' << i << ' ' << 2 << endl;
		else {
			mk();

			int min = 9999999;
			int ans = 0;
			while (s.size() > 0)
			{
				int tmp = n;			ans = 0;
				int k = s.size() - 1;
				int nows = s.top();
				s.pop();
				if (tmp % nows == 0)
				{
					for (int i = k; i >= 0; i--)
					{
						if (vi[i] <= 1) break;
						if (tmp % vi[i] == 0)
						{
							tmp /= vi[i];
							ans += to_string(vi[i]).size();
							ans++;
							i++;
						}
						if (tmp == 1)
							break;
					}
					if (ans < min && tmp == 1)
						min = ans;
				}

			}
			if (min == 9999999)
				min = -1;
			cout << '#' << i << ' ' << min << endl;
			vi.clear();
			//v.clear();
			a = 0;
		}
	}
}