
#include <iostream>
#include <map>
#include <string>
#include <vector>

#pragma warning (disable: 4996)

using namespace std;

int main()
{
    int dist, locations, location1, location2;

    char buffer[1024];
    string line;

    line = gets_s(buffer, sizeof(buffer));
    sscanf(buffer, "%d", &dist);

    line = gets_s(buffer, sizeof(buffer));
    int index = line.find('(');
    sscanf(buffer + index + 1, "%d", &location1);
    index = line.find(',', index + 1);
    sscanf(buffer + index + 1, "%d", &location2);

    scanf("%d", &locations);
    string temp_var1;
    int temp_var2, temp_var3;
    for (int i = 0; i < locations; i++) {
        line = gets_s(buffer, sizeof(buffer));
        index = line.find("(");
        temp_var1 = line;
        temp_var1[index-1] = '\x0';
        sscanf(buffer + index + 1, "%d", &temp_var2);
        index = line.find(",", index + 1);
        sscanf(buffer + index + 1, "%d", &temp_var3);

        if ((location1 - temp_var2) * (location1 - temp_var2) + (location2 - temp_var3) * (location2 - temp_var3) == dist * dist) {
            cout << temp_var1;
            break;
        }
    }
}