#include<iostream>
#include<queue>
using namespace std;
int a[101][101] = { 0 };
queue<pair<int, int>> q;

int ladder(int x, int y)
{
	int num = 0;
	while (y <= 99) {
		y++;
		num++;
		if (a[y][x - 1] == 1) {
			do {
				x--;
				num++;
			} while (a[y][x - 1] == 1);
		}
		else if (a[y][x + 1] == 1) {
			do {
				x++;
				num++;
			} while (a[y][x + 1] == 1);
		}
	}
	return num;
}

int main() {

	for (int i = 1; i <= 10; i++)
	{
		int n = 0;	cin >> n;
		int s = 0;
		int l = 0;
		for (int j = 0; j < 100; j++)
		{
			for (int z = 0; z < 100; z++)
			{
				cin >> a[j][z];
				if (j == 0 && a[j][z] == 1)
				{
					q.push({ z,j });
				}
			}
		}
		int min = 99999;
		int ansx = 0;
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			int ans = ladder(x, y);
			if (ans <= min)
			{
				min = ans;
				ansx = x;
			}
		}
		cout << '#' << i << ' ' << ansx << endl;
	}
}