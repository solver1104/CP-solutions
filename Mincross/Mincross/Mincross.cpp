// Mincross.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning( disable : 4996 )

#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long int> fenwick;

long long int lsb(long long int pos) {
    return pos & -pos;
}

void update(long long int pos, long long int val) {
    while (pos <= N) {
        fenwick[pos] += val;
        pos += lsb(pos);
    }
}

long long int query(long long int pos) {
    long long int sum = 0;
    while (pos > 0) {
        sum += fenwick[pos];
        pos -= lsb(pos);
    }
    return sum;
}


int main()
{
    ifstream fin("mincross.in");
    ofstream fout("mincross.out");

    int tmp;
    long long int ans = 0;
    long long int inversions = 0;
    fin >> N;
    vector<int> first, second;
    for (int i = 0; i < N; i++) {
        first.push_back(0); 
    }
    for (int i = 0; i < pow(2,ceil(log2(N + 1))); i++) {
        fenwick.push_back(0);
    }
    for (int i = 1; i < N + 1; i++) {
        fin >> tmp;
        first[tmp-1] = i;
    }

    for (int i = 0; i < N; i++) {
        fin >> tmp;
        second.push_back(first[tmp-1]);
    }

    for (int i = 0; i < N; i++) {
        inversions += (i - query(second[i]));
        update(second[i], 1);
    }

    ans = inversions;
    for (int i = N-1; i >= 0; i--) {
        inversions += (2 * second[i] - N - 1);
        ans = min(ans, inversions);
    }
    inversions = 0;
    fenwick.clear();
    for (int i = 0; i < pow(2, ceil(log2(N + 1))); i++) {
        fenwick.push_back(0);
    }
    for (int i = 0; i < N; i++) {
        first[second[i] - 1] = i + 1;
    }
    for (int i = 0; i < N; i++) {
        inversions += (i - query(first[i]));
        update(first[i], 1);
    }
    ans = min(ans,inversions);
    for (int i = N - 1; i >= 0; i--) {
        inversions += (2 * first[i] - N - 1);
        ans = min(ans, inversions);
    }
    fout << ans;
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
