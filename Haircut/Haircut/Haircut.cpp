// Haircut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma warning( disable : 4996 )


#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, tmp;

vector<long long int> fenwick;
vector <long long int> inversions;

long long int lsb(long long int pos) {
    return pos & -pos;
}

void update(long long int pos, long long int val) {
    while (pos <= N+1) {
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
    long long int ans = 0;
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < pow(2, ceil(log2(N + 2))); i++) {
        fenwick.push_back(0);
        inversions.push_back(0);
    }

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        update(tmp+1, 1);
        inversions[tmp] += query(N + 1);
        inversions[tmp] -= query(tmp + 1);
    }

    for (int i = 0; i < N; i++) {
        cout << ans << "\n";
        ans += inversions[i];
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
