//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("input.txt");

    if (!fin) {
        cout << "Cannot open file" << endl;
        return 0;
    }

    string text = "", line;

    while (getline(fin, line))
        text += line + "\n";

    int count = 0;
    bool correct = true;

    for (int i = 0; i < (int)text.size(); i++) {
        if (text.substr(i, 4) == "<td>") {
            count++;
            i += 3;
        }
        else if (text.substr(i, 5) == "</td>") {
            count--;
            i += 4;

            if (count < 0) {
                correct = false;
                break;
            }
        }
    }

    if (count == 0 && correct)
        cout << "Tags are correct" << endl;
    else
        cout << "Tags are incorrect" << endl;

    fin.close();
    return 0;
}
