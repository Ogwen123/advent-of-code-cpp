#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int part1()
{
    ifstream input("input.txt");
    string id;
    vector<string> alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    int threes = 0;
    int twos = 0;
    while (getline(input, id))
    {
        int tracker[26];
        memset(tracker, 0, sizeof(tracker));
        for (char &c : id)
        {
            auto index = find(alphabet.begin(), alphabet.end(), string(1, c));
            if (index != alphabet.end())
            {
                tracker[index - alphabet.begin()]++;
            }
        }
        for (int count : tracker)
        {
            if (count == 2)
            {
                twos++;
                break;
            }
        }
        for (int count : tracker)
        {
            if (count == 3)
            {
                threes++;
                break;
            }
        }
    }
    printf("twos: %d, threes: %d\n", twos, threes);
    return twos * threes;
}

string part2()
{
    ifstream input("input.txt");
    string id;
    vector<string> ids;
    while (getline(input, id))
    {
        ids.push_back(id);
    }
    for (string id1 : ids)
    {
        for (string id2 : ids)
        {
            int diff = 0;
            for (int i = 0; i < id1.size(); i++)
            {
                if (id1[i] != id2[i])
                {
                    diff++;
                }
            }
            if (diff == 1)
            {
                string answer;
                for (int i = 0; i < id1.size(); i++)
                {
                    if (id1[i] == id2[i])
                    {
                        answer += id1[i];
                    }
                }
                return answer;
            }
        }
    }
    return "no";
}

int main()
{
    cout << part1() << endl;
    cout << part2() << endl;
}