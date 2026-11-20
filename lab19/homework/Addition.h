#pragma once
#include <vector>
#include <iosfwd>

using UCHAR = unsigned char;

// Digits contain numeric values (not character codes), most significant first.
// Bases must be >= 2; invalid input produces an empty vector.
std::vector<int> addition(const std::vector<UCHAR>& A, int baseA,
                          const std::vector<UCHAR>& B, int baseB, int baseResult);

struct Number {
    std::vector<UCHAR> digits;
    int base;
};

// File formats: FD 16, "FD" 16, or a separate line 16: "FD".
// Several records are allowed. Numeric digit lists, e.g. [255 0] 256,
// also support bases whose digits cannot be written with 0..9 and A..Z.
bool readNumbers(std::istream& in, std::vector<Number>& numbers);
void writeNumber(std::ostream& out, const std::vector<int>& digits, int base);
