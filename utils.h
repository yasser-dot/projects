#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

int getIntInput(const std::string& prompt);
double getDoubleInput(const std::string& prompt);
std::string getStringInput(const std::string& prompt);

// --------------------------------------------------------------------//

template <typename T>
T findMax(const std::vector<T>& items) {
    if (items.empty()) {
        throw std::invalid_argument("Empty vector passed to findMax");
    }
    return *std::max_element(items.begin(), items.end());
}

#endif