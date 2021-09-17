//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t;
string tmp;
int zero;
bool zerorun = false;

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
		zero = 0;
		zerorun = false;
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			if (tmp.substr(j, 1) == "0" && zerorun == false) {
				zero++;
				zerorun = true;
			}
			if (tmp.substr(j, 1) == "1" && zerorun) {
				zerorun = false;
			}
		}

		if (zero > 2) {
			cout << 2 << "\n";
		}
		else {
			cout << zero << "\n";
		}
	}
}