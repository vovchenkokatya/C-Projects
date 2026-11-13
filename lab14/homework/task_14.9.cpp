//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void itogi(string filename) {
    ifstream fin(filename);

    string line;

    while (getline(fin, line)) {
        stringstream ss(line);
        string name, example;
        int a, b, answer;
        int correct = 0, total = 0;
        char x, eq;

        ss >> name;

        while (ss >> example) {
            stringstream s(example);
            s >> a >> x >> b >> eq >> answer;

            if (answer == a * b)
                correct++;

            total++;
        }

        if (total > 0) {
            double percent = 100.0 * correct / total;
            cout << name << ": " << percent << "%" << endl;
        }
    }

    fin.close();
}

int main() {
    srand(time(0));

    int m, n;
    cout << "Number of players: ";
    cin >> m;

    cout << "Number of questions: ";
    cin >> n;

    if (m <= 0 || n <= 0)
        return 0;

    ofstream fout("results.txt");

    if (!fout) {
        cout << "Cannot open file" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        string name;
        cout << "Name: ";
        cin >> name;

        fout << name;

        for (int j = 0; j < n; j++) {
            int a = rand() % 20 + 1;
            int b = rand() % 20 + 1;
            int answer;

            cout << a << " x " << b << " = ";
            cin >> answer;

            fout << " " << a << "x" << b << "=" << answer;
        }

        fout << endl;
    }

    fout.close();

    cout << "Results:" << endl;
    itogi("results.txt");

    return 0;
}
