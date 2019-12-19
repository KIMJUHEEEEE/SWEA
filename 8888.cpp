#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int tc = 0;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		int n = 0, t = 0, p = 0;
		scanf("%d %d %d", &n, &t, &p);
		int* num = new int[n] {0, };
		char** a = new char* [n];
		int* score = new int[t] {0, };
		for (int i = 0; i < n; i++)
		{
			a[i] = new char [t] { {0 }, };
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t; j++)
			{
				char k = 0;
				cin.ignore();
				k = getchar();
				a[i][j] = k;
				if (a[i][j] == '1')
					num[i]++;
				if (a[i][j] == '0')
					score[j]++;
			}
		}
		int* f_score = new int[n] { 0, };
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < t; j++)
			{
				if (a[i][j] == '1')
				{
					f_score[i] += score[j];
				}
			}
		}
		int rank = 1;
		for (int i = 0; i < n; i++)
		{
			if (i == p - 1)
				continue;
			if (f_score[i] > f_score[p - 1])
			{
				rank++;
			}
			if (f_score[i] == f_score[p - 1])
			{
				if (num[i] > num[p - 1] || num[i] == num[p - 1] && i < p - 1)
					rank++;
			}
		}
		printf("#%d %d %d\n", i, f_score[p - 1], rank);
	}
}