#include<iostream>
#include<string>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int arr[21][21] = { {0}, };
		int n = 0;
		string str = "";
		cin >> n>>str;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		if (str == "up")
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == 0)
					{
						int a = i;int k = 1;
						while (a+k-1 < n-1)
						{
							while (arr[a + k][j] == 0&&a+k<n)
								k++;
							arr[a][j] = arr[a + k][j];
							arr[a + k][j] = 0;
							break;
						}
					}
				}
			}
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == arr[i + 1][j])
					{
						arr[i][j] = arr[i][j] * 2;
						int y = i + 1; int x = j;
						while (y<n)
						{
							arr[y][x] = arr[y + 1][x];
							y++;
							if (y == n - 1)
							{
								arr[y][x] = 0;
								break;
							}
						}
					}
				}
			}
		}
		else if (str == "down")
		{
			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					if (arr[i][j] == 0)
					{
						int a = i; int k = 1;
						while (a > 0)
						{
							while (arr[a - k][j] == 0 && a - k >= 0)
							{
								k++;
								
							}if (a - k < 0)
									break;
							arr[a][j] = arr[a - k][j];
							arr[a - k][j] = 0;
							break;
						}
					}
				}
			}

			for (int i = n - 1; i >= 1; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					if (arr[i][j] == arr[i - 1][j])
					{
						arr[i - 1][j] = arr[i - 1][j] * 2;
						int y = i; int x = j;
						while (y > 0)
						{
							arr[y][x] = arr[y - 1][x];
							y--;
							if (y == 0)
							{
								arr[y][x] = 0;
								break;
							}
						}
					}
				}
			}
		}
		else if (str == "left")
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == 0)
					{
						int a = j; int k = 1;
						while (a < n - 1)
						{
							while (arr[i][a + k] == 0 && a + k < n)
								k++;
							arr[i][a] = arr[i ][a+k];
							arr[i ][a+k] = 0;
							break;
						}
					}
				}
			}
			for (int i = 0; i < n ; i++)
			{
				for (int j = 0; j < n-1; j++)
				{
					if (arr[i][j] == arr[i][j+1])
					{
						arr[i][j] = arr[i][j] * 2;
						int y = i; int x = j+1;
						while (x < n)
						{
							arr[y][x] = arr[y ][x+1];
							x++;
							if (x == n - 1)
							{
								arr[y][x] = 0;
								break;
							}
						}
					}
				}
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					if (arr[i][j] == 0)
					{
						int a = j; int k = 1;
						while (a > 0)
						{
							while (arr[i][a - k] == 0 && a - k >= 0)
							{
								k++;
							}
							if (a - k < 0)
								break;
							arr[i][a] = arr[i][a - k];
							arr[i][a - k] = 0;
							break;;
						}
					}
				}
			}

			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = n - 1; j >= 1; j--)
				{
					if (arr[i][j] == arr[i][j - 1])
					{
						arr[i][j - 1] = arr[i][j - 1] * 2;
						int y = i; int x = j;
						while (x > 0)
						{
							arr[y][x] = arr[y][x - 1];
							x--;
							if (x == 0)
							{
								arr[y][x] = 0;
								break;
							}
						}
					}
				}
			}
		}
		cout << '#' << i <<endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
	}
}