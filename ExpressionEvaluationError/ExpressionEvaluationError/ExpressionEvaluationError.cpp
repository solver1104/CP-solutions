//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, s, n;

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
		cin >> s >> n;
		for (int j = 0; j < n - 1; j++) {
			cout << 1 << " ";
		}
		cout << s - n + 1 << "\n";
	}
}