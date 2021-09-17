// RangeUpdateQueries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int N, q, tmp1, tmp3;
int tmp2 = 0;

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
    cin >> N >> q;

    for (int i = 0; i < pow(2,ceil(log2(N))) + 1; i++) {
        fenwick.push_back(0);
    }
    for (int i = 1; i < N + 1; i++) {
        cin >> tmp1;
        update(i, tmp1 - tmp2);
        tmp2 = tmp1;
    }

    for (int i = 0; i < q; i++) {
        cin >> tmp1;
        if (tmp1 == 1) {
            cin >> tmp1 >> tmp2 >> tmp3;
            update(tmp1, tmp3);
            update(tmp2 + 1, -tmp3);
        }
        else {
            cin >> tmp2;
            cout << query(tmp2) << "\n";
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
