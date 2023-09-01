// 1000 by 1000 grid
// loop through ids
// generate coords
// increment the number at each coord

// #123 @ 3,2: 5x4

#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int grid[1000][1000] = {{0}};

int part1()
{
    ifstream input("input.txt");
    string id;
    vector<string> ids;
    while (getline(input, id))
    {
        string useful_data = id.substr(id.find("@") + 1, id.size() - (id.find("@") + 1));
        string offset_data = useful_data.substr(0, useful_data.find(":"));
        int x_offset = stoi(offset_data.substr(0, offset_data.find(",")));
        printf("%d\n", x_offset);
    }
    return 0;
}

int main()
{
    part1();
}