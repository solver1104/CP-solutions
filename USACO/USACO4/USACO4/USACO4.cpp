// USACO4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>

#pragma warning(disable : 4996)
#pragma warning(disable : 6001)
#pragma warning(disable : 4477)

using namespace std;

int main()
{
	int param1, param2, param3, param4, ans;
	FILE* finput = fopen("teleport.in", "rt");
	fscanf(finput, "%d %d %d %d", &param1, &param2, &param3, &param4);
	fclose(finput);
	ans = min(min(abs(param1 - param2), abs(param1 - param3) + abs(param2 - param4)),abs(param1-param4) + abs(param2 - param3));
	FILE* foutput = fopen("teleport.out", "wt");
	fprintf(foutput, "%d", ans);
	fclose(foutput);
	return 0;
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
