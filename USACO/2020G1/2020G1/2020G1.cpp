
#include <iostream>
#include <vector>
#include <cstdio>
#include <unordered_set>
#pragma warning( disable : 4996)


using namespace std;

int main()
{
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	int N, M, C, tmp1, tmp2;
	cin >> N >> M >> C;
	vector<int> dp;
	vector<int> tmpdp;
	vector<int> earned;
	vector<int> empty;
	vector<vector<int>> edges;
	for (int x = 0; x < N; x++) {
		dp.push_back(-2147483647);
		edges.push_back(empty);
		cin >> tmp1;
		earned.push_back(tmp1);
	}
	dp[0] = 0;

	for (int i = 0; i < M; i++) {
		cin >> tmp1 >> tmp2;
		edges[tmp1 - 1].push_back(tmp2-1);
	}
	unordered_set<int> currentp;
	currentp.insert(0);
	unordered_set<int> nextp;
	int days = 0;

	while (currentp.size() > 0) {
		days += 1;
		tmpdp = dp;
		for (int p : currentp) {
			for (int q : edges[p]) {
				if (tmpdp[q] < dp[p] + earned[q] - C*(2 * days - 1)) {
					nextp.insert(q);
					tmpdp[q] = dp[p] + earned[q] - C*(2 * days - 1);
				}
			}
		}
		currentp = nextp;
		nextp.clear();
		dp = tmpdp;
	}

	cout << dp[0];
}

