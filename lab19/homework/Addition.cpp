#include "Addition.h"
#include <algorithm>
#include <sstream>
#include <string>
#include <limits>
#include <iostream>

using namespace std;

namespace {

bool valid(const vector<UCHAR>& digits, int base) {
    if (base < 2 || digits.empty()) return false;
    for (UCHAR digit : digits) {
        if (static_cast<int>(digit) >= base) return false;
    }
    return true;
}

// Horner's rule, with the result stored least significant digit first.
vector<int> convert(const vector<UCHAR>& digits, int base, int resultBase) {
    vector<int> result(1, 0);
    for (UCHAR digit : digits) {
        unsigned long long carry = digit;
        for (int& x : result) {
            unsigned long long value = static_cast<unsigned long long>(x) * base + carry;
            x = static_cast<int>(value % resultBase);
            carry = value / resultBase;
        }
        while (carry > 0) {
            result.push_back(static_cast<int>(carry % resultBase));
            carry /= resultBase;
        }
    }
    return result;
}

string trim(const string& s) {
    size_t first = s.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

bool parseDigits(string text, int base, vector<UCHAR>& digits) {
    text = trim(text);
    if (base < 2 || text.empty()) return false;
    if (text.front() == '"') {
        if (text.size() < 2 || text.back() != '"') return false;
        text = text.substr(1, text.size() - 2);
    }
    if (text.empty()) return false;

    digits.clear();
    if (text.front() == '[') {
        if (text.back() != ']') return false;
        istringstream values(text.substr(1, text.size() - 2));
        while (values >> ws && !values.eof()) {
            int x;
            if (!(values >> x) || x < 0 || x > numeric_limits<UCHAR>::max() || x >= base)
                return false;
            digits.push_back(static_cast<UCHAR>(x));
        }
    } else {
        for (char c : text) {
            int x;
            if (c >= '0' && c <= '9') x = c - '0';
            else if (c >= 'A' && c <= 'Z') x = c - 'A' + 10;
            else if (c >= 'a' && c <= 'z') x = c - 'a' + 10;
            else return false;
            if (x >= base) return false;
            digits.push_back(static_cast<UCHAR>(x));
        }
    }
    return !digits.empty();
}

bool readToken(istream& in, string& text) {
    in >> ws;
    char first;
    if (!in.get(first)) return false;
    if (first == '"' || first == '[') {
        char last = first == '"' ? '"' : ']';
        string content;
        if (!getline(in, content, last) || in.eof()) return false;
        text = string(1, first) + content + last;
        return true;
    }
    in.putback(first);
    return static_cast<bool>(in >> text);
}

}

vector<int> addition(const vector<UCHAR>& A, int baseA,
                     const vector<UCHAR>& B, int baseB, int baseResult) {
    if (!valid(A, baseA) || !valid(B, baseB) || baseResult < 2) return {};

    vector<int> a = convert(A, baseA, baseResult);
    vector<int> b = convert(B, baseB, baseResult);
    vector<int> result;
    unsigned long long carry = 0;
    for (size_t i = 0; i < max(a.size(), b.size()); i++) {
        unsigned long long sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        result.push_back(static_cast<int>(sum % baseResult));
        carry = sum / baseResult;
    }
    if (carry > 0) result.push_back(static_cast<int>(carry));
    reverse(result.begin(), result.end());
    return result;
}

bool readNumbers(istream& in, vector<Number>& numbers) {
    vector<string> lines;
    string line;
    bool withColon = false;
    while (getline(in, line)) {
        line = trim(line);
        if (line.empty()) continue;
        if (line.find(':') != string::npos) withColon = true;
        lines.push_back(line);
    }
    if (in.bad() || lines.empty()) return false;

    vector<Number> result;
    if (withColon) {
        for (const string& record : lines) {
            size_t colon = record.find(':');
            if (colon == string::npos) return false;
            istringstream baseText(record.substr(0, colon));
            Number number;
            if (!(baseText >> number.base)) return false;
            baseText >> ws;
            if (!baseText.eof()) return false;
            if (!parseDigits(record.substr(colon + 1), number.base, number.digits)) return false;
            result.push_back(number);
        }
    } else {
        string contents;
        for (const string& record : lines) contents += record + '\n';
        istringstream records(contents);
        while (records >> ws && !records.eof()) {
            string text;
            Number number;
            if (!readToken(records, text) || !(records >> number.base)) return false;
            // Require a separator after the base (reject "16abc" and "2.5").
            if (!records.eof()) {
                int next = records.peek();
                if (next != ' ' && next != '\t' && next != '\r' && next != '\n') return false;
            }
            if (!parseDigits(text, number.base, number.digits)) return false;
            result.push_back(number);
        }
    }
    if (result.empty()) return false;
    numbers.swap(result);
    return true;
}

void writeNumber(ostream& out, const vector<int>& digits, int base) {
    if (base <= 36) {
        const char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int digit : digits) out << symbols[digit];
    } else {
        out << '[';
        for (size_t i = 0; i < digits.size(); i++) {
            if (i > 0) out << ' ';
            out << digits[i];
        }
        out << ']';
    }
}
