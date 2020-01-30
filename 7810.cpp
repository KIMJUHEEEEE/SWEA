#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void quick_sort(int* arr, int first, int last)
{
	int pivot, i, j, temp;
	pivot = first;
	i = first;
	j = last;
	if (first < last)
	{
		while (i < j)
		{
			while (arr[i] >= arr[pivot] && i < last) i++;
			while (arr[j] < arr[pivot]) j--;
			if (i < j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quick_sort(arr, first, j - 1);
		quick_sort(arr, j + 1, last);
	}
}
int main() {
	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n = 0;
		cin >> n;
		int id = 0;
		int* a = new int[n + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] >= n) id++;
		}
		if (id == n)
			cout << '#' << i << ' ' << n << '\n';
		else {
			quick_sort(a,0,n-1);
			while (n > 0)
			{
				if (id >= n)break;
				while (a[id] >= n)id++;
				if (id < n) n--;
			}
			cout << '#' << i << ' ' << n << '\n';
		}
		delete[] a;
	}
	return 0;
}