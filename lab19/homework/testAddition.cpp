#include "Addition.h"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int failures = 0;

void check(bool condition, const char* name) {
    if (!condition) {
        cerr << "Failed: " << name << endl;
        failures++;
    }
}

vector<UCHAR> digits(const string& text) {
    vector<UCHAR> result;
    for (char c : text)
        result.push_back(static_cast<UCHAR>(c <= '9' ? c - '0' : c - 'A' + 10));
    return result;
}

string sumText(const string& a, int baseA, const string& b, int baseB, int base) {
    vector<int> result = addition(digits(a), baseA, digits(b), baseB, base);
    ostringstream out;
    writeNumber(out, result, base);
    return out.str();
}

int main() {
    check(sumText("123", 10, "456", 10, 10) == "579", "decimal addition");
    check(sumText("1011", 2, "111", 2, 2) == "10010", "binary carry");
    check(sumText("FF", 16, "1", 10, 16) == "100", "hexadecimal carry");
    check(sumText("FD", 16, "253", 10, 2) == "111111010", "different input bases");
    check(sumText("777", 8, "1", 10, 16) == "200", "octal to hexadecimal");
    check(sumText("Z", 36, "1", 10, 36) == "10", "base 36");
    check(sumText("0", 2, "0", 36, 10) == "0", "zero");
    check(sumText("000", 10, "0001", 2, 10) == "1", "leading zeroes");
    check(sumText(string(100, '9'), 10, "1", 10, 10) == "1" + string(100, '0'),
          "number larger than machine integer");
    check(sumText(string(128, '1'), 2, "1", 2, 2) == "1" + string(128, '0'),
          "long binary carry");
    check(addition({255}, 256, {1}, 2, 256) == vector<int>({1, 0}), "unsigned char digit");
    check(addition({255}, 256, {255}, 256, numeric_limits<int>::max()) == vector<int>({510}),
          "large result base");
    check(addition({1, 0}, numeric_limits<int>::max(), {1}, 2, 10)
          == vector<int>({2, 1, 4, 7, 4, 8, 3, 6, 4, 8}), "large source base");
    check(addition({}, 10, {1}, 10, 10).empty(), "empty first number");
    check(addition({1}, 10, {}, 10, 10).empty(), "empty second number");
    check(addition({2}, 2, {1}, 10, 10).empty(), "invalid first digit");
    check(addition({1}, 10, {10}, 10, 10).empty(), "invalid second digit");
    for (int base : {-2, 0, 1}) {
        check(addition({1}, base, {1}, 10, 10).empty(), "invalid first base");
        check(addition({1}, 10, {1}, base, 10).empty(), "invalid second base");
        check(addition({1}, 10, {1}, 10, base).empty(), "invalid result base");
    }

    vector<Number> records;
    istringstream standard("\"FD\" 16\n253 10\n");
    check(readNumbers(standard, records) && records.size() == 2
          && records[0].digits == digits("FD") && records[1].base == 10,
          "standard file format and several records");
    istringstream separateLines("FD\n16\n253\n10\n");
    check(readNumbers(separateLines, records) && records.size() == 2,
          "number and base on separate lines");
    istringstream alternative("16: \"fd\"\n\n10: \"253\"\n");
    check(readNumbers(alternative, records) && records.size() == 2
          && records[0].digits == digits("FD"), "base-colon format and lowercase");
    istringstream numeric("[255 0] 256\n");
    check(readNumbers(numeric, records) && records[0].digits == vector<UCHAR>({255, 0}),
          "numeric digit list");
    const char* invalidFiles[] = {
        "", "\n \n", "FD", "FD 10", "2: \"102\"", "10: \"\"", "1: \"0\"",
        "16abc: \"F\"", "10: \"-1\"", "253 10abc", "253 2.5", "\"123 10",
        "\"123\"", "[256] 300", "[-1] 10", "[] 10", "[1 2 10", "1 9999999999999",
        "10: \"1\" extra", "16: \"F\"\n1 2", "16: \"F\"\nnot a record"
    };
    for (const char* file : invalidFiles) {
        istringstream input(file);
        check(!readNumbers(input, records), file);
    }
    ostringstream numericOutput;
    writeNumber(numericOutput, {255, 0}, 256);
    check(numericOutput.str() == "[255 0]", "numeric output format");

    if (failures == 0) cout << "All addition tests passed." << endl;
    return failures == 0 ? 0 : 1;
}
