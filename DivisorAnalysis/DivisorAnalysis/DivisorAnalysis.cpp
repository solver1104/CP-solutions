// DivisorAnalysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    long long int num, N, tmp1, tmp2, numfactors, ans2, evenexp, numfactors2, ans3;
    cin >> N;
    vector<long long int> primes;
    vector<long long int> exponents;

    numfactors = 1;
    num = 1; 
    ans2 = 1;
    evenexp = 0;
    numfactors2 = 1;
    ans3 = 1;

    for (int i = 0; i < N; i++) {
        cin >> tmp1 >> tmp2;
        primes.push_back(tmp1);
        exponents.push_back(tmp2);
        numfactors *= (tmp2 + 1);
        numfactors = numfactors % 1000000007;
        ans2 *= exponentiate(tmp1 - 1, 1000000005, 1000000007);
        ans2 = ans2 % 1000000007;
        ans2 *= (exponentiate(tmp1, tmp2+1, 1000000007) - 1);
        ans2 = ans2 % 1000000007;
        if (tmp2 % 2 == 1) {
            evenexp++;
        }
        numfactors2 *= (tmp2 + 1);
        numfactors2 = numfactors2 % 1000000006;
    }

    if (evenexp == 0) {
        for (int i = 0; i < N; i++) {
            num *= exponentiate(primes[i], exponents[i] / 2, 1000000007);
            num = num % 1000000007;
        }

        cout << numfactors << " " << ans2 << " " << exponentiate(num, numfactors2, 1000000007);
    }
    else {
        for (int i = 0; i < N; i++) {
            num *= exponentiate(primes[i], exponents[i], 1000000007);
            num = num % 1000000007;
        }
        if (evenexp == 1) {
            if (numfactors2 % 4 == 0) {
                numfactors2 += 1000000006;
            }
            cout << numfactors << " " << ans2 << " " << exponentiate(num, numfactors2 / 2, 1000000007);
        }
        else {
            if (numfactors2 % 4 == 2) {
                numfactors2 += 1000000006;
            }
            cout << numfactors << " " << ans2 << " " << exponentiate(num, numfactors2 / 2, 1000000007);
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
