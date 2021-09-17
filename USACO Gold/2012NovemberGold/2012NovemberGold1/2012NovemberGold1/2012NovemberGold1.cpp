//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 1e3 + 2;
string tmp;
int indext = 0;
int ways = 0;
int brackets[MAX], prefixsums[MAX];
int dp[MAX][MAX];

int main()
{
	
	string problemName = "bbreeds";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tmp;
	prefixsums[0] = 1;
	
	for (char x : tmp) {
		if (x == '(') brackets[indext] = 1;
		else brackets[indext] = -1;
		if (indext) {
			if (brackets[indext] == 1) prefixsums[indext] = prefixsums[indext - 1] + 1;
			else prefixsums[indext] = prefixsums[indext - 1] - 1;
		}
		indext++;
	}
	
	dp[0][0] = 1;
	dp[0][1] = 1;
	for (int i = 1; i < indext; i++) {
		for (int j = 0; j <= prefixsums[i]; j++) {
			if (brackets[i] == 1) {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j];
			}
			else {
				dp[i][j] += dp[i - 1][j + 1];
				dp[i][j] += dp[i - 1][j];
			}
			dp[i][j] %= 2012;
		}
	}

	cout << dp[indext - 1][0];
}