#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int map[102][102];
int d[102][102];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int n;

bool check(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n);
}

int solve() {
	memset(d, -1, sizeof(d));
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0,{0,0} });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		if (d[x][y] == -1) d[x][y] = cost;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!check(nx, ny)) continue;
			int ncost = -cost - map[nx][ny];
			if (d[nx][ny] == -1) pq.push({ ncost,{nx,ny} });
		}
	}
	return d[n - 1][n - 1];
}

int main() {
	int tc; scanf(" %d", &tc); int a = 1;
	while (tc--) {
		scanf(" %d", &n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %1d", &map[i][j]);
			}
		}
		printf("#%d %d\n", a++, solve());
	}
}