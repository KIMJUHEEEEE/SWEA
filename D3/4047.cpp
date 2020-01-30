#include<iostream>
#include <vector>
#include<string>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		string a;
		cin >> a;
		int sn=13, dn=13, hn=13, cn = 13;
		vector<string> s;
		vector<string> d;
		vector<string> h;
		vector<string> c;
		int e = 0;
		for (int i = 0; i < a.size(); i += 3)
		{
			string b = "";
			b += a[i]; b += a[i + 1]; b += a[i + 2];
			if (a[i] == 'S')
			{
				if (s.size() != 0)
				{
					for (int i = 0; i < s.size(); i++)
					{
						if (s[i] == b)
						{
							e = 1;
							break;
						}
					}
				}
					sn--;
					s.push_back(b);
			}
			if (a[i] == 'D')
			{
				if (d.size() != 0)
				{
					for (int i = 0; i < d.size(); i++)
					{
						if (d[i] == b)
						{
							e = 1;
							break;
						}
					}
				}
					dn--;
					d.push_back(b);
			}
			if (a[i] == 'H')
			{
				if (h.size() != 0)
				{
					for (int i = 0; i < h.size(); i++)
					{
						if (h[i] == b)
						{
							e = 1;
							break;
						}
					}
				}
					hn--;
					h.push_back(b);
			}
			if (a[i] == 'C')
			{
				if (c.size() != 0)
				{
					for (int i = 0; i < c.size(); i++)
					{
						if (c[i] == b)
						{
							e = 1;
							break;
						}
					}
				}

					cn--;
					d.push_back(b);
			}
		}
		if (e == 1)
			cout << "ERROR";
		else
		{
			cout << sn<<' ' << dn <<' '<< hn <<' '<< cn << endl;
		}
	}
}
