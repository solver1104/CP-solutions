//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

int t, a, b;

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
		cin >> a >> b;

		if ((a - 1) % 2 == 0) {
			if ((a - 1) % 4 == 0) {
				if (a - 1 == b) {
					cout << a;
				}
				else if (((a - 1) ^ b) == a) {
					cout << a + 2;
				}
				else {
					cout << a + 1;
				}	
			}
			else {
				if ((1 ^ (a - 1)) == b) {
					cout << a;
				}
				else if ((1 ^ (a - 1) ^ b) == a) {
					cout << a + 2;
				}
				else {
					cout << a + 1;
				}
			}
		}
		else {
			if ((a - 1) % 4 == 1) {
				if (b == 1) {
					cout << a;
				}
				else if ((1 ^ b) == a) {
					cout << a + 2;
				}
				else {
					cout << a + 1;
				}
			}
			else {
				if (b == 0) {
					cout << a;
				}
				else if (b == a) {
					cout << a + 2;
				}
				else {
					cout << a + 1;
				}
			}
		}
		cout << "\n";
	}
}