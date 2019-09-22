#include<iostream>
#include<algorithm>
#include <vector>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >>y1 >> x2 >> y2;
		int n;
		cin >> n;
		int x, y;
		int in = 0, out = 0, sq = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			if (x<x2 && x>x1 && y<y2 && y>y1)
				in++;
			else if((x==x1&&y>=y1&&y<=y2)||(x==x2&&y>=y1&&y<=y2)||(y==y1&&x>=x1&&x<=x2)||(y==y2&&x>=x1&&x<=x2))
				sq++;
			else
				out++;
		}
		cout << '#' << i << ' ' << in << ' ' << sq << ' ' << out << endl;
	}
}