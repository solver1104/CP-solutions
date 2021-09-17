// Osmosmjerka.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int A = 9973;
int B = 1e9 + 7;

int gcd(long long int a, long long int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

int main()
{
    int M, N, K;
    cin >> M >> N >> K;
    long long int tmphash = 0;
    long long int numerator = 0;
    long long int denominator = 64 * M * M * N * N;
    int period = max(M, N) / gcd(M, N);

    string tmp;
    vector<vector<char>> input;
    unordered_map<long long int, int> hashes;

    for (int i = 0; i < M; i++) {
        cin >> tmp;
        input.push_back({});
        for (char c : tmp) {
            input[i].push_back(c);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                tmphash += input[(i+x)%M][j];
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                if ((i - x) % M >= 0) {
                    tmphash += input[(i - x) % M][j];
                }
                else {
                    tmphash += input[(i - x) % M + M][j];
                }
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                tmphash += input[i][(j+x) % N];
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                if ((j - x) % N >= 0) {
                    tmphash += input[i][(j-x) % N];
                }
                else {
                    tmphash += input[i][(j-x) % N + N];
                }
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                tmphash += input[(i + x) % M][(j+x)%N];
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                if ((j - x) % N >= 0) {
                    tmphash += input[(i + x) % M][(j - x) % N];
                }
                else {
                    tmphash += input[(i + x) % M][(j - x) % N + N];
                }
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                if ((i - x) % M >= 0) {
                    tmphash += input[(i - x) % M][(j + x) % N];
                }
                else {
                    tmphash += input[(i - x) % M + M][(j + x) % N];
                }
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
            tmphash = 0;
            for (int x = 0; x < period; x++) {
                tmphash *= A;
                tmphash %= B;
                if ((i - x) % M >= 0) {
                    if ((j - x) % N >= 0) {
                        tmphash += input[(i - x) % M][(j - x) % N];
                    }
                    else {
                        tmphash += input[(i - x) % M][(j - x) % N + N];
                    }
                }
                else {
                    if ((j - x) % N >= 0) {
                        tmphash += input[(i - x) % M + M][(j - x) % N];
                    }
                    else {
                        tmphash += input[(i - x) % M + M][(j - x) % N + N];
                    }
                }
                tmphash %= B;
            }
            if (tmphash < 0) {
                tmphash += B;
            }
            if (hashes[tmphash]) {
                hashes[tmphash] ++;
            }
            else {
                hashes[tmphash] = 1;
            }
        }
    }

    for (auto i : hashes) {
        numerator += i.second * i.second;
    }

    cout << numerator / gcd(numerator, denominator) << "/" << denominator / gcd(numerator, denominator);
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
