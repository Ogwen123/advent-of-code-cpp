#include "../includes.h"

int part1() {
    int ans = 0;

    vector<map<int, int>> svec;

    for (int i = 0; i < 60; i++) {
        map<int, int> temp;
        svec.push_back(temp);
    }

    ifstream input("input.txt");
    string id;
    vector<string> ids;

    while (getline(input, id)) {
        int minute = stoi(id.substr(id.find(':'), 2));

    }

    return ans;
}

int part2() {
    int ans = 0;

    return ans;
}

int main() {
    cout << "Part 1: " << part1() << endl;
    cout << "Part 2: " << part2() << endl;
}
