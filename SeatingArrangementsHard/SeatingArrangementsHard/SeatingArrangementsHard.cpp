//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n, m, inversions, tmp;
int arr[90005], copyarrr[90005];
pair<int, int> copyarr[90005];
unordered_map<int, int> freq[300];
int bit[300][300];


void upd(int i, int v, int x) {
	for (; i <= 300; i += i & (-i)) bit[x][i] += v;
}

int qry(int i, int x) {
	int sum = 0;
	for (; i > 0; i -= i & (-i)) sum += bit[x][i];
	return sum;
}

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
		
		for (int j = 0; j < 300; j++) {
			freq[j].clear();
			fill(bit[j], bit[j] + 300, 0);
		}
		cin >> n >> m;
		inversions = 0;
		for (int j = 0; j < n * m; j++) {
			cin >> tmp;
			copyarr[j] = { tmp, j };
			copyarrr[j] = tmp;
		}

		sort(copyarr, copyarr + n *m);
		for (int j = 0; j < n * m; j++) {
			arr[copyarr[j].second] = j + 1;
		}

		for (int j = 0; j < n * m; j++) {
			inversions += qry(arr[j] - 1, (arr[j] - 1) / m);
			upd(arr[j], 1, (arr[j] - 1) / m);
			inversions -= (freq[(arr[j] - 1) / m][copyarrr[j]]);
			freq[(arr[j] - 1) / m][copyarrr[j]] ++;
		}

		cout << inversions << "\n";
	}
}