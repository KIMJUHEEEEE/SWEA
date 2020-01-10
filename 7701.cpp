#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;

struct cmp {
	bool operator() (string s1, string s2) {
		if (s1.length() > s2.length()) return true;
		else if (s1.length() < s2.length()) return false;
		else {
			if (s1 > s2) return true;
			else return false;
		}
	}
};
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	priority_queue<string, vector<string>, cmp> pq;
	set<string> s;

	int tc = 0;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			string name;
			cin >> name;
			s.insert(name);
		}

		for (string str : s)
			pq.push(str);

		cout << "#" << i << "\n";
		while (!pq.empty()) {
			cout << pq.top() << "\n";
			pq.pop();
		}

		s.clear();
	}
}