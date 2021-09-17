//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 5e6 + 5;
int T, A, B;
bool possible[MAX];

int main()
{
	
	string problemName = "feast";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	fin >> T >> A >> B;

	possible[0] = true;
	for (int i = 0; i < T; i++) {
		if (possible[i]) {
			possible[i / 2] = true;
			if (i <= T - A) possible[i + A] = true;
			if (i <= T - B) possible[i + B] = true;
		}
	}
	for (int i = 0; i < T; i++) {
		if (possible[i]) {
			if (i <= T - A) possible[i + A] = true;
			if (i <= T - B) possible[i + B] = true;
		}
	}
	for (int i = T; i >= 0; i--) {
		if (possible[i]) {
			fout << i;
			break;
		}
	}
}