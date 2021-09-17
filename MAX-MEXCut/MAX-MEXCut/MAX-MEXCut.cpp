//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 1e5;

int t, n, tmpsum;
char tmp;
int v1[MAX], v2[MAX];


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
		tmpsum = 0;
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == '1') {
				v1[j] = 1;
			}
			else {
				v1[j] = 0;
			}
		}
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == '1') {
				v2[j] = 1;
			}
			else {
				v2[j] = 0;
			}
		}
		
		for (int j = 0; j < n; j++) {
			if (v1[j] != v2[j]) {
				tmpsum += 2;
			}
			else if (j != n - 1) {
				if (!v1[j] && !v2[j]) {
					if (v1[j + 1] && v2[j + 1]) {
						tmpsum += 2;
						j++;
					}
					else {
						tmpsum++;
					}
				}
				else {
					if (!v1[j + 1] && !v2[j + 1]) {
						tmpsum += 2;
						j++;
					}
				}
			}
			else {
				if (!v1[j] && !v2[j]) {
					tmpsum++;
				}
			}
		}

		cout << tmpsum << "\n";
	}
}