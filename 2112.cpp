#include <iostream>
#include<memory.h>
#define INF 987654321
#define W_MAX 20
#define M_MAX 13

using namespace std;

int film[M_MAX][W_MAX];
int D, W, K;
int ans;

void copyfloor(int a[W_MAX], int b[W_MAX]) {
	for (int i = 0; i < W; i++) {
		a[i] = b[i];
	}
}

//성능 시험을 통과하는지 확인
//만약 통과를 한다면 그때의 뿌린 횟수를 저장
void checkFilm(int cnt) {
	for (int i = 0; i < W; i++) {
		int hap = 1;
		for (int j = 0; j < D - 1; j++) {
			if (hap >= K) {
				break;
			}
			if (film[j][i] == film[j + 1][i]) {
				hap += 1;
			}
			else {
				hap = 1;
			}
		}
		if (hap < K) {
			return;
		}
	}
	if (ans > cnt) {
		ans = cnt;
	}
}

void dfs(int d, int cnt) {
	if (cnt > ans) {
		return;
	}
	if (d >= D) {
		checkFilm(cnt);
		return;
	}

	//각 층에서 약품을 뿌리거나, 안뿌리거나 둘중 하나
	//뿌릴 경우에는 A를 뿌리느냐, B를 뿌리느냐!

	//(1) 안뿌릴 경우
	dfs(d + 1, cnt);

	//약품을 뿌릴 경우에는 전 상황을 저장하여 모든 경우의 수를 확인
	//(2) A를 뿌릴 경우
	int temp[25];
	copyfloor(temp, film[d]);
	for (int i = 0; i < W; i++) {
		film[d][i] = 0;
	}
	dfs(d + 1, cnt + 1);
	copyfloor(film[d], temp);

	//(3) B를 뿌릴 경우
	copyfloor(temp, film[d]);
	for (int i = 0; i < W; i++) {
		film[d][i] = 1;
	}
	dfs(d + 1, cnt + 1);
	copyfloor(film[d], temp);
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(film, 0, sizeof(film));
		cin >> D >> W >> K;
		//film 받기
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}
		ans = INF;
		dfs(0, 0);
		cout << "#" << t << " " << ans << endl;
	}
	return 0;
}