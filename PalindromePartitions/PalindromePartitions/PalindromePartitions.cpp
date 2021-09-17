// PalindromePartitions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int A = 9973;
int B = 1e9 + 7;

int main()
{
    int n;
    ll hashfirst;
    ll hashsecond;
    string a;
    vector <char> aa;
    vector <ll> h;
    vector <ll> p;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int currentstart = 0;
        int total = 0;
        aa.clear();
        h.clear();
        p.clear();
        cin >> a;
        for (char x : a) {
            aa.push_back(x);
        }
        h.push_back(aa[0]);
        p.push_back(1);
        for (int i = 1; i < aa.size(); i++) {
            p.push_back((p.back() * A) % B);
            h.push_back((h.back() * A + aa[i]) % B);
        }

        for (int index = 0; index < aa.size()/2; index++) {
            if (currentstart == 0) {
                hashfirst = h[index];
            }
            else {
                hashfirst = (h[index] - h[currentstart - 1] * p[index - currentstart + 1])%B;
            }
            hashsecond = (h[a.size() - currentstart - 1] - h[a.size() - index - 2] * p[index - currentstart + 1])%B;
            if (hashfirst < 0) {
                hashfirst += B;
            }
            if (hashsecond < 0) {
                hashsecond += B;
            }
            if (hashfirst == hashsecond) {
                currentstart = index+1;
                total+=2;
            }
        }
        if (a.size() % 2 == 1) {
            total++;
        }
        else {
            if (currentstart != a.size() / 2) {
                total++;
            }
        }
        cout << total << "\n";
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
