// USACOG2018P3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

long long int exponentiate(long long int a, long long int b, long long int c) {
    if (b == 0) {
        return 1;
    }
    if (a == 0 || a == 1 || b == 1) {
        return a;
    }
    
    long long int ans = 1;
    long long int curr = a;

    while (b > 0) {
        if (b % 2 == 1) {
            ans *= curr;
            ans = ans % c;
            b = (b - 1) / 2;
        }
        else {
            b = b / 2;
        }
        curr = curr * curr;
        curr = curr % c;
    }

    return ans; 
}

int main()
{
    long long int N, a, b, c, tmp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        cout << exponentiate(a,exponentiate(b, c, 1000000006), 1000000007) << "\n";
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
