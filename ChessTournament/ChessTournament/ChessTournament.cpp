//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>
#include <unordered_map>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, n;
char tmp;
unordered_map<int, int> ones, twos;

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
		ones.clear();
		twos.clear();
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == '1') {
				ones[j] = ones.size() + 1;
			}
			else {
				twos[j] = twos.size() + 1;
			}
		}

		if (twos.size() == 1 || twos.size() == 2) {
			cout << "NO" << "\n";
		}
		else if (twos.size() == 0) {
			cout << "YES" << "\n";
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (j == k) {
						cout << "X";
					}
					else {
						cout << "=";
					}
				}
				cout << "\n";
			}
		}
		else {
			cout << "YES" << "\n";
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (j == k) {
						cout << "X";
					}
					else if (ones[j] || ones[k]) {
						cout << "=";
					}
					else if ((twos[j]) % (twos.size()) + 1 == twos[k]) {
						cout << "-";
					}
					else if ((twos[k]) % (twos.size()) + 1 == twos[j]) {
						cout << "+";
					}
					else {
						cout << "=";
					}
				}
				cout << "\n";
			}
		}
	}
}