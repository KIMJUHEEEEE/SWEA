#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int dx = abs(x1 - x2);
		int dy = abs(y1 - y2);
		int ans = 0;
		if (dx == dy) { 
			ans += 2 * dx; 
		}
		else
		{
			if (dx > dy) ans += 2 * dy;
			else ans += 2 * dx;

			int dis = abs(dx - dy);
			if (dis % 2 == 0) ans += 2 * dis;
			else ans += 2 * dis - 1;
		}
		cout << '#' << i << ' ' << ans << "\n";
	}
}