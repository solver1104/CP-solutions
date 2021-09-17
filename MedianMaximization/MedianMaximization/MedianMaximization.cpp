//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t;
int n, s;

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
		cin >> n >> s;
		if (n == 1) {
			cout << s << "\n";
			continue;
		}
		if (n % 2 == 0) {
			cout << s / (n / 2 + 1) << "\n";
		}
		else {
			cout << s / (n - ((n + 1) / 2) + 1) << "\n";
		}
	}
}