//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 501;
const int MOD = 1e9 + 7;
string str;
int curlen = 0;
int num[MAX];
long long int factorials[MAX];
long long int dp[MAX][MAX];
long long int inverse[MAX];
long long int inverses[MAX];

long long int exponentiate(long long int a, long long int b, long long int c) {
	if (b == 0) {
		return 1;
	}
	if (a == 0 || a == 1 || b == 1) {
		return a;
	}

	long long int ans = 1;
	long long int curr = a;

	while (b > 0) {
		if (b % 2 == 1) {
			ans *= curr;
			ans = ans % c;
			b = (b - 1) / 2;
		}
		else {
			b = b / 2;
		}
		curr = curr * curr;
		curr = curr % c;
	}

	return ans;
}

long long int choose(long long int a, long long int b) {
	if (a % 2 == 1 || b % 2 == 1) return 0;
	else {
		int x = inverses[b / 2];
		int y = inverses[(a - b) / 2];
		return (((factorials[a / 2] * x) % MOD) * y) % MOD;
	}
}

int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	factorials[0] = 1;
	inverses[0] = 1;

	for (int i = 1; i < 251; i++) {
		inverse[i] = exponentiate(i, MOD - 2, MOD);
	}
	for (int i = 1; i < 251; i++) {
		factorials[i] = (factorials[i - 1] * i) % MOD;
		inverses[i] = (inverses[i - 1] * inverse[i]) % MOD;
	}

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (char x : str) {
		num[curlen] = x - 'a';
		curlen++;
	}

	for (int i = 1; i < curlen; i += 2) {
		for (int j = 0; j < curlen - i; j++) {
			if (i == 1) {
				if (num[j] == num[j + 1]) {
					dp[j][i + j] = 1;
				}
				continue;
			}
			if (num[i + j] == num[j]) {
				dp[j][i + j] = dp[j + 1][i + j - 1];
			}
			if (num[j] == num[j + 1]) {
				dp[j][i + j] += ((dp[j + 2][i + j] * (i + 1) / 2) % MOD);
				dp[j][i + j] %= MOD;
			}
			for (int k = j + 3; k < i + j; k += 2) {
				if (num[j] == num[k]) {
					dp[j][i + j] += (((dp[j + 1][k - 1] * dp[k + 1][i + j]) % MOD) * choose((i + 1), (k - j + 1))) % MOD;
					dp[j][i + j] %= MOD;
				}
			}
		}
	}
	cout << dp[0][curlen - 1];
}