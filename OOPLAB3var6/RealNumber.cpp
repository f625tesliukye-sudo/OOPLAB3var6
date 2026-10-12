#include "RealNumber.h"
#include <cmath>

RealNumber::RealNumber() : value(0.0) {}

RealNumber::RealNumber(double val) {
    setValue(val);
}

RealNumber::RealNumber(const RealNumber& other) : value(other.value) {}

RealNumber::~RealNumber() {}

double RealNumber::getValue() const {
    if (std::isnan(value) || std::isinf(value)) {
        throw std::runtime_error("Read exception: Field contains invalid number (NaN or Infinity)!");
    }
    return value;
}

void RealNumber::setValue(double val) {
    if (std::isnan(val) || std::isinf(val)) {
        throw std::invalid_argument("Set exception: Cannot set invalid number (NaN or Infinity)!");
    }
    value = val;
}

RealNumber RealNumber::operator+(const RealNumber& other) const {
    return RealNumber(this->getValue() + other.getValue());
}

RealNumber RealNumber::operator-(const RealNumber& other) const {
    return RealNumber(this->getValue() - other.getValue());
}

RealNumber RealNumber::operator*(const RealNumber& other) const {
    return RealNumber(this->getValue() * other.getValue());
}

RealNumber RealNumber::operator/(const RealNumber& other) const {
    if (other.getValue() == 0.0) {
        throw std::runtime_error("Arithmetic exception: Division by zero!");
    }
    return RealNumber(this->getValue() / other.getValue());
}

bool RealNumber::operator==(const RealNumber& other) const {
    return this->getValue() == other.getValue();
}

bool RealNumber::operator!=(const RealNumber& other) const {
    return !(*this == other);
}

bool RealNumber::operator<(const RealNumber& other) const {
    return this->getValue() < other.getValue();
}

bool RealNumber::operator>(const RealNumber& other) const {
    return this->getValue() > other.getValue();
}

std::ostream& operator<<(std::ostream& os, const RealNumber& num) {
    os << num.getValue();
    return os;
}

std::istream& operator>>(std::istream& is, RealNumber& num) {
    double tempVal;
    if (!(is >> tempVal)) {
        is.clear();
        throw std::invalid_argument("Input exception: Invalid numeric data format!");
    }
    num.setValue(tempVal);
    return is;
}