//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 300;
int n, m;
bool zero = false;
int drops[MAX];
int maxans = 0;
int partialsum;
pair<int, int> dp1[MAX][MAX];
pair<int, int> dp2[MAX][MAX];

int main()
{
	/*
	string problemName = "";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	*/

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> drops[i];
		if (drops[i] == 0) {
			i--;
			n--;
			zero = true;
		}
	}

	sort(drops, drops + n);
	int zeroindex = lower_bound(drops, drops + n, 0) - drops;

	partialsum = 0;
	for (int i = zeroindex; i < n; i++) {
		if (drops[i] > m) {
			break;
		}
		partialsum += (m - drops[i]);
	}

	maxans = partialsum;
	partialsum = 0;
	for (int i = zeroindex - 1; i > -1; i--) {
		if (drops[i] < -m) {
			break;
		}
		partialsum += (m + drops[i]);
	}
	maxans = max(maxans, partialsum);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (drops[i + j] < 0 || drops[j] > 0) {
				continue;
			}
			partialsum = 0;
			for (int k = j; k <= i + j; k++) {
				partialsum += abs(drops[k]);
			}
			if (2 * drops[i + j] - drops[j] <= m) {
				dp1[j][i + j] = { (i + 1) * m - partialsum - (zeroindex - j) * 2 * drops[i + j], 2 * drops[i + j] - drops[j] };
			}
			if (2 * abs(drops[j]) + drops[i + j] <= m) {
				dp2[j][i + j] = { (i + 1) * m - partialsum - (i + j - zeroindex + 1) * 2 * abs(drops[j]), 2 * abs(drops[j]) + drops[i + j] };
			}
			maxans = max(maxans, dp1[j][i + j].first);
			maxans = max(maxans, dp2[j][i + j].first);
			partialsum = 0;
			for (int k = j + 1; k <= zeroindex; k++) {
				partialsum += m + drops[k - 1] - drops[i + j];
				if (dp2[k][i + j].second + drops[i + j] - drops[j] <= m) {
					if (dp1[j][i + j].first < dp2[k][i + j].first - (k - j) * dp2[k][i + j].second + partialsum) {
						dp1[j][i + j] = { dp2[k][i + j].first - (k - j) * dp2[k][i + j].second + partialsum, dp2[k][i + j].second + drops[i + j] - drops[j] };
						maxans = max(maxans, dp2[k][i + j].first - (k - j) * dp2[k][i + j].second + partialsum);
					}
					else if (dp2[k][i + j].second + drops[i + j] - drops[j] < dp1[j][i + j].second && dp1[j][i + j].first == dp2[k][i + j].first - (k - j) * dp2[k][i + j].second + partialsum) {
						dp1[j][i + j] = { dp2[k][i + j].first - (k - j) * dp2[k][i + j].second + partialsum, dp2[k][i + j].second + drops[i + j] - drops[j] };
					}
				}
			}
			partialsum = 0;
			for (int k = zeroindex; k <= i + j; k++) {
				partialsum += m - (drops[k] - drops[j]);
			}
			for (int k = zeroindex; k <= i + j; k++) {
				partialsum -= m - (drops[k] - drops[j]);
				if (dp1[j][k].second + drops[i + j] - drops[j] <= m) {
					if (dp2[j][i + j].first < dp1[j][k].first - (i + j - k) * dp1[j][k].second + partialsum) {
						dp2[j][i + j] = { dp1[j][k].first - (i + j - k) * dp1[j][k].second + partialsum, dp1[j][k].second + drops[i + j] - drops[j] };
						maxans = max(maxans, dp1[j][k].first - (i + j - k) * dp1[j][k].second + partialsum);
					}
					else if (dp1[j][k].second + drops[i + j] - drops[j] < dp2[j][i + j].second && dp2[j][i + j].first == dp1[j][k].first - (i + j - k) * dp1[j][k].second + partialsum) {
						dp2[j][i + j] = { dp1[j][k].first - (i + j - k) * dp1[j][k].second + partialsum, dp1[j][k].second + drops[i + j] - drops[j] };
					}
				}
			}
		}
	}

	if (zero) {
		cout << maxans + m;
	}
	else {
		cout << maxans;
	}
}