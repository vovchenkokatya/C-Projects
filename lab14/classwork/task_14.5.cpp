//
// Created by Katya on 13.11.2026.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void createFile(int n) {
    ofstream fout("students.txt");

    for (int i = 0; i < n; i++) {
        string surname, group;
        int course, m, mark;

        cout << "Surname, course, group, number of marks: ";
        cin >> surname >> course >> group >> m;

        fout << surname << " " << course << " " << group << " ";

        for (int j = 0; j < m; j++) {
            cin >> mark;
            fout << mark;

            if (j < m - 1)
                fout << ",";
        }

        fout << endl;
    }

    fout.close();
}

string minStudent() {
    ifstream fin("students.txt");

    string line, worst = "";
    double min_avg = 0;
    bool first = true;

    while (getline(fin, line)) {
        string surname, group;
        int course, mark;

        stringstream ss(line);
        ss >> surname >> course >> group;

        int sum = 0, count = 0;

        while (ss >> mark) {
            sum += mark;
            count++;

            ss >> ws;
            if (ss.peek() == ',')
                ss.get();
        }

        if (count > 0) {
            double avg = (double)sum / count;

            if (first || avg < min_avg) {
                min_avg = avg;
                worst = surname;
                first = false;
            }
        }
    }

    fin.close();
    return worst;
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    if (n <= 0)
        return 0;

    createFile(n);

    cout << "Worst student: " << minStudent() << endl;

    return 0;
}
