//#pragma warning( disable : 4996 )
#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

const int MAX = 5e4 + 5;
int N, tmp, ptr1;

bool has[2 * MAX];
int cards1[MAX], cards2[MAX];
int cards3[MAX];
int total = 0;

int main()
{
	
	string problemName = "cardgame";
	ifstream fin(problemName + ".in");
	ofstream fout(problemName + ".out");
	

	ios::sync_with_stdio(0);
	cin.tie(0);

	fin >> N;
	
	for (int i = 0; i < N / 2; i++) {
		fin >> tmp;
		cards1[i] = tmp - 1;
		has[tmp - 1] = true;
	}
	for (int i = 0; i < N / 2; i++) {
		fin >> tmp;
		cards2[i] = tmp - 1;
		has[tmp - 1] = true;
	}
	tmp = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (!has[i]) {
			cards3[tmp++] = i;
		}
	}

	sort(cards3, cards3 + N);
	sort(cards1, cards1 + N / 2);
	sort(cards2, cards2 + N / 2);
	reverse(cards1, cards1 + N / 2);
	ptr1 = N - 1;
	for (int i = 0; i < N / 2; i++) {
		if (cards3[ptr1] < cards1[i]) {
			continue;
		}
		else {
			total++;
			ptr1--;
		}
	}

	ptr1 = 0;
	for (int i = 0; i < N / 2; i++) {
		if (cards3[ptr1] > cards2[i]) {
			continue;
		}
		else {
			total++;
			ptr1++;
		}
	}

	fout << total;
}