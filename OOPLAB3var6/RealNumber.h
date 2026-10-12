#ifndef REALNUMBER_H
#define REALNUMBER_H

#include <iostream>
#include <stdexcept>
#include <string>

class RealNumber {
private:
    double value;

public:
    RealNumber();                             
    explicit RealNumber(double val);          
    RealNumber(const RealNumber& other);      
    ~RealNumber();                            

    double getValue() const;
    void setValue(double val);

    RealNumber operator+(const RealNumber& other) const;
    RealNumber operator-(const RealNumber& other) const;
    RealNumber operator*(const RealNumber& other) const;
    RealNumber operator/(const RealNumber& other) const;

    bool operator==(const RealNumber& other) const;
    bool operator!=(const RealNumber& other) const;
    bool operator<(const RealNumber& other) const;
    bool operator>(const RealNumber& other) const;

    friend std::ostream& operator<<(std::ostream& os, const RealNumber& num);
    friend std::istream& operator>>(std::istream& is, RealNumber& num);
};

#endif 