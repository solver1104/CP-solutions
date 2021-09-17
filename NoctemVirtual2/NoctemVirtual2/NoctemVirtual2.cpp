// NoctemVirtual2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#pragma warning( disable : 4996 )

typedef long long ll;
const ll M = 1e9 + 9, P = 9973; // Change M and P if you want to

ll pw[1000001]; // Stores the powers of P modulo M

int n;
string s;
ll hsh[1000001];

void calc_hashes() {
	hsh[0] = 1;
	for (int i = 0; i < n; i++)
		hsh[i + 1] = ((hsh[i] * P) % M + s[i]) % M;
}

ll get_hash(int a, int b) { // Endpoints of the substring
	return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % M + M) % M;
}

int main()
{
	pw[0] = 1;
	ios::sync_with_stdio(0);
	ifstream fin("wordgame.in");
	ofstream fout("wordgame.out");
	int tc;
	fin >> tc;

	for (int i = 0; i < 1e6; i++)
		pw[i + 1] = (pw[i] * P) % M;

	string a, b;
	for (int ij = 0; ij < tc; ij++) {
		fin >> a >> b;
		n = a.length();
		if (b.length() % 2 == 1) {
			if (a.find(b) != string::npos) {
				fout << 1 << "\n";
			}
			else {
				fout << 0 << "\n";
			}
		}
		else {
			s = a;
			calc_hashes();

			bool found = false;
			ll bhash = 0;
			for (int i = 0; i < b.length(); i++) {
				bhash *= P;
				bhash = bhash % M;
				bhash += b[i];
				bhash = bhash % M;
			}



			for (int x = b.length() / 2; x < a.length() - b.length() / 2; x++) {
				if (get_hash(x - b.length() / 2, x + b.length()/2 - 1) != bhash && get_hash(x - b.length() / 2 + 1, x + b.length() / 2) != bhash) {
					found = true;
				}
			}

			if (found == true) {
				fout << 0 << "\n";
			}
			else {
				fout << 2 << "\n";
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


