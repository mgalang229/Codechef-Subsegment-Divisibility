#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> vec(501, 0);
	iota(vec.begin(), vec.end(), 1); // generate numbers from 1 to 500
	for (int i = 0; i < 499; i += 2) {
		swap(vec[i], vec[i + 1]); // swap the current element with the adjacent element
	}
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << vec[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
