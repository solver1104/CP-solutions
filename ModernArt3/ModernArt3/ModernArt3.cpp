//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 300;
int N, tmp, tmp1, curr;
int num[MAX];
int dp[MAX][MAX];

int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	curr = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp != tmp1) {
			num[curr] = tmp;
			curr++;
		}
		tmp1 = tmp;
	}
	
	for (int i = 0; i < curr; i++) {
		for (int j = 0; j < curr - i; j++) {
			dp[j][i + j] = 1 + dp[j + 1][i + j];
			for (int k = j + 1; k <= i + j; k++) {
				if (num[k] == num[j]) {
					dp[j][i + j] = min(dp[j + 1][k - 1] + dp[k][i + j], dp[j][i + j]);
				}
			}
		}
	}
	cout << dp[0][curr - 1];
}