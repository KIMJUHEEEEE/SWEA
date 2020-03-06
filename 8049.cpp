#include<iostream>
#include<string>
using namespace std;

void strcheck(string str)
{
		int x = 0;
	
	if (str[0] != 'F'|| str[str.size() - 1] == 'C')
	{
		cout << "NOTHING!" << endl;
		return;
	}
	else {
		for (int i = 2; i < str.size(); i++)
		{
			if (str[x + 1] == 'F')
			{
				string u = "";
				while (str[i] == 'F')
				{
					i++;
				}
				for (int j = 0; j < 3; j++)
				{
					u += str[i + j];
				}
				if (u != "MCM")
				{
					cout << "NOTHING!" << endl;
					return;
				}
				else
				{
					i += 3;
					while (str[i] == 'M')
					{
						i++;
					}
				}
				x = i;
				if (str[x] != 'F'&&x<str.size())
				{
					cout << "NOTHING!" << endl;
					return;
				}
			}
			else if (str[x + 1] == 'C')
			{
				string d = "";
				while (str[i] == 'C')
				{
					i++;
				}
				d += str[i] ;
				d += str[i + 1];
				if (d != "MF")
				{
					cout << "NOTHING!" << endl;
					return;
				}
				i+=2;
				x = i;
				if (str[x] != 'F'&&x<str.size())
				{
					cout << "NOTHING!" << endl;
					return;
				}
			}

		}
	}
	cout << "DETECTED!" << endl;
	return;
}

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		string str;
		cin >> str;
		cout << '#' << i << ' ';
		strcheck(str);
	}
}