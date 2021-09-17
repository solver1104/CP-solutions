// SalaryQueries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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
    ios::sync_with_stdio(0);
    int q, tmp1, tmp2;
    char tmp;
    cin >> N >> q;
    vector<int> a;
    vector <int> original;
    vector<vector<int>> queries;
    for (int i = 0; i < N; i++) {
        cin >> tmp1;
        a.push_back(tmp1);
        original.push_back(tmp1);
    }
    for (int i = 0; i < q; i++) {
        cin >> tmp >> tmp1 >> tmp2;
        if (tmp != 63) {
            a.push_back(tmp2);
            N++;
        }
        queries.push_back({ tmp, tmp1, tmp2 });
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < N; i++) {
        if (a[i] == a[i - 1]) {
            a.erase(a.begin() + i);
            i--;
            N--;
        }
    }

    for (int i = 0; i < pow(2, ceil(log2(N))) + 1; i++) {
        fenwick.push_back(0);
    }
    for (int i : original) {
        update(lower_bound(a.begin(), a.end(), i) - a.begin() + 1,1);
    }

    for (vector<int> query1 : queries) {
        if (query1[0] != 63) {
            update(lower_bound(a.begin(), a.end(), query1[2]) - a.begin() + 1, 1);
            update(lower_bound(a.begin(), a.end(), original[query1[1] - 1]) - a.begin() + 1, -1);
            original[query1[1] - 1] = query1[2];
        }
        else {
            cout << query(upper_bound(a.begin(), a.end(), query1[2]) - a.begin()) - query(lower_bound(a.begin(), a.end(), query1[1]) - a.begin())  << '\n';
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
