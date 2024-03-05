#include "main.h"

LongNumber::LongNumber(const std::string& num) : number(num) {}

LongNumber::LongNumber(const LongNumber& other) : number(other.number) {} // Реализация конструктора копирования

LongNumber::~LongNumber() {}

bool LongNumber::operator<(const LongNumber& other) const {
    return number.length() < other.number.length() || (number.length() == other.number.length() && number < other.number);
}

bool LongNumber::operator>(const LongNumber& other) const {
    return other < *this;
}

bool LongNumber::operator<=(const LongNumber& other) const {
    return !(other < *this);
}

bool LongNumber::operator>=(const LongNumber& other) const {
    return !(*this < other);
}

bool LongNumber::operator==(const LongNumber& other) const {
    return number == other.number;
}

bool LongNumber::operator!=(const LongNumber& other) const {
    return !(*this == other);
}

LongNumber LongNumber::operator+(const LongNumber& other) const {
    std::string result;
    int carry = 0;
    int i = number.length() - 1;
    int j = other.number.length() - 1;

    while (i >= 0 || j >= 0 || carry != 0) {
        int digit1 = (i >= 0) ? number[i--] - '0' : 0;
        int digit2 = (j >= 0) ? other.number[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result.insert(result.begin(), sum + '0');
    }

    return LongNumber(result);
}

LongNumber LongNumber::operator-(const LongNumber& other) const {
    std::string result;
    int borrow = 0;
    int i = number.length() - 1;
    int j = other.number.length() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? number[i--] - '0' : 0;
        int digit2 = (j >= 0) ? other.number[j--] - '0' : 0;
        int diff = digit1 - digit2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.insert(result.begin(), diff + '0');
    }

    // Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));

    return LongNumber(result.empty() ? "0" : result);
}

LongNumber LongNumber::operator*(const LongNumber& other) const {
    std::string result(number.length() + other.number.length(), '0');

    for (int i = number.length() - 1; i >= 0; --i) {
        int carry = 0;
        for (int j = other.number.length() - 1; j >= 0; --j) {
            int tmp = (number[i] - '0') * (other.number[j] - '0') + (result[i + j + 1] - '0') + carry;
            result[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        result[i] += carry;
    }

    // Remove leading zeros
    result.erase(0, result.find_first_not_of('0'));

    return LongNumber(result.empty() ? "0" : result);
}

LongNumber LongNumber::operator/(const LongNumber& other) const {
    LongNumber quotient(""), remainder("");
    divide(*this, other, quotient, remainder);
    return quotient;
}

LongNumber LongNumber::operator%(const LongNumber& other) const {
    LongNumber quotient(""), remainder("");
    divide(*this, other, quotient, remainder);
    return remainder;
}

std::ostream& operator<<(std::ostream& os, const LongNumber& num) {
    os << num.number;
    return os;
}

void LongNumber::divide(const LongNumber& dividend, const LongNumber& divisor, LongNumber& quotient, LongNumber& remainder) {
    if (divisor == LongNumber("0")) {
        throw std::runtime_error("Division by zero");
    }

    LongNumber current_dividend = dividend;
    quotient = LongNumber("0");

    while (current_dividend >= divisor) {
        LongNumber temp_divisor = divisor;
        LongNumber temp_quotient = LongNumber("1");

        while (current_dividend >= (temp_divisor + temp_divisor)) {
            temp_divisor = temp_divisor + temp_divisor;
            temp_quotient = temp_quotient + temp_quotient;
        }

        quotient = quotient + temp_quotient;
        current_dividend = current_dividend - temp_divisor;
    }

    remainder = current_dividend;
}