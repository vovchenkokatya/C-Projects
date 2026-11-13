//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Cannot open file" << endl;
        return 0;
    }

    string word, prev = "";
    bool first = true;

    while (fin >> word) {
        if (prev == "die" || prev == "der" || prev == "das") {
            word[0] = toupper((unsigned char)word[0]);
        }

        if (!first)
            fout << " ";

        fout << word;
        prev = word;
        first = false;
    }

    fin.close();
    fout.close();

    return 0;
}
