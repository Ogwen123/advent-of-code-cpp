#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int part1()
{
    ifstream input("input.txt");
    string change;
    int frequency = 0;

    while (getline(input, change))
    {
        frequency += stoi(change);
    }
    return frequency;
}

int part2()
{
    ifstream input("input.txt");
    string change;

    int first_twice;

    vector<int> frequencies;
    vector<int> changes;
    while (getline(input, change))
    {
        changes.push_back(stoi(change));
    }
    int i = 1;
    int j = 1;
    frequencies.push_back(changes[0]);
    // printf("0: %d \n", frequencies.size());
    while (true)
    {
        frequencies.push_back(frequencies[j - 1] + changes[i]);
        if (count(frequencies.begin(), frequencies.end() - 1, frequencies[j]) >= 1)
        {
            first_twice = frequencies[j];
            break;
        }
        if (i == changes.size() - 1)
            i = 0;
        else
            i++;
        j++;
    }
    return first_twice;
}

int main()
{
    printf("Part 1: %d \n", part1());
    printf("Part 2: %d \n", part2());
}