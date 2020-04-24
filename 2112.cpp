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

//���� ������ ����ϴ��� Ȯ��
//���� ����� �Ѵٸ� �׶��� �Ѹ� Ƚ���� ����
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

	//�� ������ ��ǰ�� �Ѹ��ų�, �ȻѸ��ų� ���� �ϳ�
	//�Ѹ� ��쿡�� A�� �Ѹ�����, B�� �Ѹ�����!

	//(1) �ȻѸ� ���
	dfs(d + 1, cnt);

	//��ǰ�� �Ѹ� ��쿡�� �� ��Ȳ�� �����Ͽ� ��� ����� ���� Ȯ��
	//(2) A�� �Ѹ� ���
	int temp[25];
	copyfloor(temp, film[d]);
	for (int i = 0; i < W; i++) {
		film[d][i] = 0;
	}
	dfs(d + 1, cnt + 1);
	copyfloor(film[d], temp);

	//(3) B�� �Ѹ� ���
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
		//film �ޱ�
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