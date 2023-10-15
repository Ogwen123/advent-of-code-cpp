// 1000 by 1000 grid
// loop through ids
// generate coords
// increment the number at each coord

// #123 @ 3,2: 5x4

#include "../includes.h"

int grid[1000][1000] = {{0}};

int part1() {
    ifstream input("input.txt");
    string id;
    vector<string> ids;
    while (getline(input, id)) {
        // extract the useful data
        string useful_data = id.substr(id.find('@') + 1, id.size() - (id.find('@') + 1));
        string offset_data = useful_data.substr(0, useful_data.find(':'));
        string size_data = useful_data.substr(useful_data.find(':') + 2,
                                              useful_data.size() - (useful_data.find(':')) + 1);

        // split the data up into separate ints
        int x_offset = stoi(offset_data.substr(0, offset_data.find(',')));
        int y_offset = stoi(
                offset_data.substr(offset_data.find(',') + 1, offset_data.size() - (offset_data.find(','))));

        int width = stoi(size_data.substr(0, size_data.find('x')));
        int height = stoi(size_data.substr(size_data.find('x') + 1, size_data.size() - (size_data.find('x'))));

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                grid[j + y_offset][i + x_offset] += 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (grid[i][j] > 1) {
                ans++;
            }
        }
    }
    return ans;
}

int part2() {
    memset(grid, 0, sizeof(grid[0][0]) * 1000 * 1000);
    vector<vector<int>> instructions = {};
    int ans;
    ifstream input("input.txt");
    string id;
    vector<string> ids;
    while (getline(input, id)) {
        // extract the useful data
        string useful_data = id.substr(id.find('@') + 1, id.size() - (id.find('@') + 1));
        string offset_data = useful_data.substr(0, useful_data.find(':'));
        string size_data = useful_data.substr(useful_data.find(':') + 2,
                                              useful_data.size() - (useful_data.find(':')) + 1);

        // split the data up into separate ints
        int x_offset = stoi(offset_data.substr(0, offset_data.find(',')));
        int y_offset = stoi(
                offset_data.substr(offset_data.find(',') + 1, offset_data.size() - (offset_data.find(','))));

        int width = stoi(size_data.substr(0, size_data.find('x')));
        int height = stoi(size_data.substr(size_data.find('x') + 1, size_data.size() - (size_data.find('x'))));

        int id_num = stoi(id.substr(1, (id.find('@')) - 1));
        instructions.push_back({id_num, x_offset, y_offset, width, height});
        bool clear = true;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (grid[j + y_offset][i + x_offset] != 0) {
                    grid[j + y_offset][i + x_offset] = -1;
                } else {
                    grid[j + y_offset][i + x_offset] = id_num;
                }

            }
        }
    }
    for (auto ins: instructions) {

        int id_num = ins[0];
        int x_offset = ins[1];
        int y_offset = ins[2];
        int width = ins[3];
        int height = ins[4];

        bool clear = true;
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                // if it is clear then set it
                // if I later encounter it when setting something else and clear is still set to it then I remove it from clear
                if (grid[j + y_offset][i + x_offset] != id_num) {
                    clear = false;
                }

            }
        }
        if (clear == true) {
            ans = id_num;
        }
    }
    return ans;

}

int main() {
    cout << "Part 1: " << part1() << endl;
    cout << "Part 2: " << part2() << endl;
}