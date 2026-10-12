#ifndef ARRAYOFREALS_H
#define ARRAYOFREALS_H

#include <vector>
#include <string>
#include "RealNumber.h"

class ArrayOfReals {
private:
    std::vector<RealNumber> elements;

public:
    ArrayOfReals();
    ~ArrayOfReals();

    void addElement(const RealNumber& num);
    void clear();
    size_t getSize() const;
    void printAll() const;

    RealNumber findMin() const;
    RealNumber findMax() const;

    RealNumber find(const std::string& criterion) const; 
    RealNumber find(bool findMaxMode) const;             
    RealNumber find(double threshold, bool findGreater) const; 
};

#endif 