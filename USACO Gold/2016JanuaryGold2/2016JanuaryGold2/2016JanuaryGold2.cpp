//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int INTMAX = 1e9;
const int MAX = 1005;
int N, M, tmp1, tmp2;
char tmp;
int dp[MAX][MAX];
pair<int, int> farmerlocs[MAX];
pair<int, int> bessielocs[MAX];

int distpair(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main()
{
	
	string problemName = "radio";
	ifstream cin(problemName + ".in");
	ofstream cout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cin >> tmp1 >> tmp2;
	farmerlocs[0] = { tmp1, tmp2 };
	cin >> tmp1 >> tmp2;
	bessielocs[0] = { tmp1, tmp2 };

	for (int i = 0; i < MAX; i++) {
		fill(dp[i], dp[i] + MAX, INTMAX);
	}

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 'N') farmerlocs[i + 1] = { farmerlocs[i].first, farmerlocs[i].second + 1 };
		if (tmp == 'S') farmerlocs[i + 1] = { farmerlocs[i].first, farmerlocs[i].second - 1 };
		if (tmp == 'W') farmerlocs[i + 1] = { farmerlocs[i].first - 1, farmerlocs[i].second };
		if (tmp == 'E') farmerlocs[i + 1] = { farmerlocs[i].first + 1, farmerlocs[i].second };
	}

	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (tmp == 'N') bessielocs[i + 1] = { bessielocs[i].first, bessielocs[i].second + 1 };
		if (tmp == 'S') bessielocs[i + 1] = { bessielocs[i].first, bessielocs[i].second - 1 };
		if (tmp == 'W') bessielocs[i + 1] = { bessielocs[i].first - 1, bessielocs[i].second };
		if (tmp == 'E') bessielocs[i + 1] = { bessielocs[i].first + 1, bessielocs[i].second };
	}

	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + distpair(farmerlocs[i + 1], bessielocs[j]));
			dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + distpair(farmerlocs[i], bessielocs[j + 1]));
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + distpair(farmerlocs[i + 1], bessielocs[j + 1]));
		}
	}

	cout << dp[N][M];
}