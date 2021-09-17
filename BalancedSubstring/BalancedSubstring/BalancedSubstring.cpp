//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n;
char tmp;
bool a = false;
bool foundans = false;

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

		cin >> tmp;
		a = false;
		foundans = false;
		if (tmp == 'a') {
			a = true;
		}
		for (int j = 1; j < n; j++) {
			cin >> tmp;
			if (tmp == 'a') {
				if (!a && !foundans) {
					cout << j << " " << j + 1 << "\n";
					foundans = true;
				}
			}
			else {
				if (a && !foundans) {
					cout << j << " " << j + 1 << "\n";
					foundans = true;
				}
			}
		}
		if (!foundans) {
			cout << "-1 -1\n";
		}
	}
}