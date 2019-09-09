#include<iostream>
using namespace std;

int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int arr[21] = { 0, };
		int N, K = 0;
		cin >> N >> K;
		for (int k = 1; k <= N; k++)
		{
			if (k % 2 == 1)
			{
				for (int i = 1; i <= K; i++)
				{
					arr[i] += (k-1)*K + i;
				}
			}
			else
			{
				for (int i = 1; i <= K; i++)
				{
					arr[i] += k * K + 1 - i;
				}
			}
		}
		cout << '#' << i << ' ';
		for (int i = 1; i <= K; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	
}
