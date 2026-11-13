//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin || !fout) {
        cout << "Cannot open file" << endl;
        return 0;
    }

    string word = "";
    char c;

    while (fin.get(c)) {
        if (c == ' ' || c == '\n' || c == '\t' ||
            c == ',' || c == '.' || c == '!' || c == '?') {

            for (int i = (int)word.size() - 1; i >= 0; i--)
                fout << word[i];

            word = "";
            fout << c;
            }
        else {
            word += c;
        }
    }

    for (int i = (int)word.size() - 1; i >= 0; i--)
        fout << word[i];

    fin.close();
    fout.close();

    return 0;
}
