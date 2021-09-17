//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n, m, inversions, tmp;
int arr[300];
int copyarr[300];

vector<int> bit;


void upd(int i, int v) {
	for (; i <= m; i += i & (-i)) bit[i] += v;
}

int qry(int i) {
	int sum = 0;
	for (; i > 0; i -= i & (-i)) sum += bit[i];
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
		cin >> n >> m;
		inversions = 0;
		bit.clear();
		for (int j = 0; j < n * m; j++) {
			bit.push_back(0);
			cin >> tmp;
			arr[j] = tmp;
			copyarr[j] = tmp;
		}
		bit.push_back(0);

		sort(copyarr, copyarr + m);
		for (int j = 0; j < n * m; j++) {
			tmp = arr[j];
			arr[j] = upper_bound(copyarr, copyarr + m, tmp) - copyarr;
		}

		for (int j = 0; j < n * m; j++) {
			inversions += qry(arr[j] - 1);
			upd(arr[j], 1);
		}

		cout << inversions << "\n";
	}
}