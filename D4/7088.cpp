#include <cstdio>
#include <cstdlib>
#include<cstring>
using namespace std;
int arr[100003][3];

int main() {
	int tc = 0;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		memset(arr, 0, sizeof(arr));
		int n = 0, q = 0;
		scanf("%d %d", &n, &q);
		for (int i = 1; i <= n; i++)
		{
			int k = 0;
			scanf("%d", &k);
			arr[i][k - 1]++;
			arr[i][0] += arr[i - 1][0];
			arr[i][1] += arr[i - 1][1];
			arr[i][2] += arr[i - 1][2];

		}
		printf("#%d\n", i);
		for (int i = 0; i < q; i++)
		{
			int a = 0, b = 0;
			scanf("%d %d", &a, &b);
			printf("%d %d %d\n", arr[b][0] - arr[a - 1][0], arr[b][1] - arr[a - 1][1], arr[b][2] - arr[a - 1][2]);
		}

	}
}