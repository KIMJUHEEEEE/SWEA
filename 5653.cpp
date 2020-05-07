#include<iostream>
#include<queue>

using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int map[1000][1000][2];
int dist[1000][1000];
void init()
{
	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 1000; j++)
		{
			map[i][j][0] = 0;
			map[i][j][1] = 0;
			dist[i][j] = 0;
		}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		init();
		int N, M, K;
		cin >> N >> M >> K;

		queue<pair<int, int>> q[11];

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int tmp;
				cin >> tmp;
				map[500 + i][500 + j][0] = tmp;        //life
				map[500 + i][500 + j][1] = tmp * 2;    //left

				if (tmp != 0) {
					q[tmp].push({ 500 + i,500 + j });
				}
			}
		}

		while (K--)
		{
			for (int i = 10; i >= 1; i--)
			{
				int size = q[i].size();

				for (int j = 0; j < size; j++)
				{
					int x = q[i].front().first;
					int y = q[i].front().second;
					q[i].pop();

					map[x][y][1]--;

					// 줄기세포가 활성화 될때 퍼져나가기
					if (map[x][y][0] > map[x][y][1])
					{
						for (int d = 0; d < 4; d++)
						{
							int nx = x + dx[d];
							int ny = y + dy[d];

							if (map[nx][ny][0] == 0)
							{
								map[nx][ny][0] = map[x][y][0];
								map[nx][ny][1] = map[x][y][0] * 2;
								q[i].push({ nx,ny });
							}

						}
					}
					// 줄기세포가 활성화 된 상태이면 다시 큐에 넣어줌.
					if (map[x][y][1] > 0)
					{
						q[i].push({ x,y });
					}

				}
			}
		}
		int cnt = 0;
		for (int i = 1; i <= 10; i++)
			cnt += q[i].size();
		cout << "#" << t << " " << cnt << endl;
	}
	return 0;
}
