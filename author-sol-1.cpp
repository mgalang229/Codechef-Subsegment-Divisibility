#include <bits/stdc++.h>

using namespace std;

int ans[501];

bool IsPossible(int i, int can) {
	int len = 1;
	// calculate the sum from index i to 0 (a[i] + a[i - 1] + a[i - 2] + ... + a[0])
	int sum = can;
	for (int j = i - 1; j >= 0; j--) {
		sum += ans[j];
		len++;
		if ((sum % len) == 0) {
			 // if one of the sum of the subarrays is divisible by its length, then return to the calling function
			return false;
		}
	}
	return true; // otherwise return true
}

void Preprocess() {
	ans[0] = 1;
	for (int i = 1; i <= 500; i++) {
		int can = ans[i - 1]; // get the previous number
		while (!IsPossible(i, can)) {
			 // increment the value of 'can' until it is possible to be inserted into the sequence
			can++;
		}
		ans[i] = can; // store the current value of 'can' (valid) in this index
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Preprocess();	
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
