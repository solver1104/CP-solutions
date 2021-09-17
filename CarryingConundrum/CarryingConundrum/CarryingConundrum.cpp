//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n, originaln;
int digits[9];
long long int ans;
long long int tmp;

int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++) {
		ans = 1;
		cin >> n;
		originaln = n;

		if (n == 1e9) {
			cout << 9999 << "\n";
			continue;
		}

		for (int j = 0; j < 9; j++) {
			digits[j] = n % 10;
			ans *= ((n % 10) + 1);
			n -= n % 10;
			n /= 10;
		}

		ans -= 2;

		for (int j = 1; j < pow(2, floor(log10(originaln)) - 1); j++) {
			tmp = 1;
			for (int k = 0; k <= floor(log10(originaln)); k ++) {
				if (k >= 2 && j & (1 << (k - 2))) {
					if (j & 1 << k) {
						tmp *= (10 - digits[k]);
					}
					else {
						tmp *= (digits[k]);
					}
				}
				else {
					if (j & 1 << k) {
						tmp *= (9 - digits[k]);
					}
					else {
						tmp *= (digits[k] + 1);
					}
				}
			}
			ans += tmp;
		}
		cout << ans << "\n";
	}
}