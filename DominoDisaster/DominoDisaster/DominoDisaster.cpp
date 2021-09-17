//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n;
char tmp;

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
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 'L') {
				cout << "L";
			}
			if (tmp == 'R') {
				cout << "R";
			}
			if (tmp == 'U') {
				cout << "D";
			}
			if (tmp == 'D') {
				cout << "U";
			}
		}
		cout << "\n";
	}
}