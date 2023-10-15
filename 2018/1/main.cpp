#include "../includes.h"

int part1() {
    ifstream input("input.txt");
    string change;
    int ans = 0;

    while (getline(input, change)) {
        ans += stoi(change);
    }
    return ans;
}

int part2() {
    ifstream input("input.txt");
    string change;

    int ans;

    vector<int> frequencies;
    vector<int> changes;
    while (getline(input, change)) {
        changes.push_back(stoi(change));
    }
    int i = 1;
    int j = 1;
    frequencies.push_back(changes[0]);
    // printf("0: %d \n", frequencies.size());
    while (true) {
        frequencies.push_back(frequencies[j - 1] + changes[i]);
        if (count(frequencies.begin(), frequencies.end() - 1, frequencies[j]) >= 1) {
            ans = frequencies[j];
            break;
        }
        if (i == changes.size() - 1)
            i = 0;
        else
            i++;
        j++;
    }
    return ans;
}

int main() {
    cout << "Part 1: " << part1() << endl;
    cout << "Part 2: " << part2() << endl;
}