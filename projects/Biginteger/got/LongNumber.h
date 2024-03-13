#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>

class LongNumber {
protected:
    std::string number;

public:
    LongNumber(const std::string& num);
    LongNumber(const LongNumber& other);
    ~LongNumber();

    bool operator<(const LongNumber& other) const;
    bool operator>(const LongNumber& other) const;
    bool operator<=(const LongNumber& other) const;
    bool operator>=(const LongNumber& other) const;
    bool operator==(const LongNumber& other) const;
    bool operator!=(const LongNumber& other) const;

    LongNumber operator+(const LongNumber& other) const;
    LongNumber operator-(const LongNumber& other) const;
    LongNumber operator*(const LongNumber& other) const;
    LongNumber operator/(const LongNumber& other) const;
    LongNumber operator%(const LongNumber& other) const;

    friend std::ostream& operator<<(std::ostream& os, const LongNumber& num);

private:
    static void divide(const LongNumber& dividend, const LongNumber& divisor, LongNumber& quotient, LongNumber& remainder);
};