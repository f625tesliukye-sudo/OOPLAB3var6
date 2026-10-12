#include "ArrayOfReals.h"
#include <iostream>

ArrayOfReals::ArrayOfReals() {}

ArrayOfReals::~ArrayOfReals() {}

void ArrayOfReals::addElement(const RealNumber& num) {
    elements.push_back(num);
}

void ArrayOfReals::clear() {
    elements.clear();
}

size_t ArrayOfReals::getSize() const {
    return elements.size();
}

void ArrayOfReals::printAll() const {
    if (elements.empty()) {
        std::cout << "[Array is empty]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for (const auto& el : elements) {
        std::cout << el << " ";
    }
    std::cout << "]" << std::endl;
}

RealNumber ArrayOfReals::findMin() const {
    if (elements.empty()) {
        throw std::invalid_argument("Search exception: Array is empty, cannot find minimum!");
    }
    RealNumber minEl = elements[0];
    for (size_t i = 1; i < elements.size(); ++i) {
        if (elements[i] < minEl) {
            minEl = elements[i];
        }
    }
    return minEl;
}

RealNumber ArrayOfReals::findMax() const {
    if (elements.empty()) {
        throw std::invalid_argument("Search exception: Array is empty, cannot find maximum!");
    }
    RealNumber maxEl = elements[0];
    for (size_t i = 1; i < elements.size(); ++i) {
        if (elements[i] > maxEl) {
            maxEl = elements[i];
        }
    }
    return maxEl;
}

RealNumber ArrayOfReals::find(const std::string& criterion) const {
    if (criterion == "min") {
        return findMin();
    }
    else if (criterion == "max") {
        return findMax();
    }
    else {
        throw std::invalid_argument("Search exception: Unknown text criterion! Use 'min' or 'max'.");
    }
}

RealNumber ArrayOfReals::find(bool findMaxMode) const {
    return findMaxMode ? findMax() : findMin();
}

RealNumber ArrayOfReals::find(double threshold, bool findGreater) const {
    if (elements.empty()) {
        throw std::invalid_argument("Search exception: Array is empty!");
    }
    RealNumber threshNum(threshold);
    for (const auto& el : elements) {
        if (findGreater && el > threshNum) {
            return el;
        }
        else if (!findGreater && el < threshNum) {
            return el;
        }
    }
    throw std::runtime_error("Search exception: No element matching threshold condition was found!");
}