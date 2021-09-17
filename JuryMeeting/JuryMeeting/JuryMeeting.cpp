//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 2e5 + 5;
const int MOD = 998244353;
int t, n, tmp;
long long int tmp1;
int nums[MAX];
vector<long long int> factorials;

int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	factorials.push_back(1);
	for (long long int i = 1; i < MAX; i++) {
		factorials.push_back((factorials.back() * i) % MOD);
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> nums[j];
		}

		sort(nums, nums + n);
		if (nums[n - 1] - 1 > nums[n - 2]) {
			cout << 0 << "\n";
			continue;
		}
		else {
			if (nums[n - 1] == nums[n - 2]) {
				cout << factorials[n] << "\n";
			}
			else {
				tmp = lower_bound(nums, nums + n, nums[n - 2]) - nums;
				tmp1 = 1;
				for (int j = 2; j <= n; j++) {
					if (j != n - tmp) {
						tmp1 *= j;
						tmp1 %= MOD;
					}
				}
				tmp1 *= (n - tmp - 1);
				tmp1 %= MOD;
				cout << tmp1 << "\n";
			}
		}
	}
}