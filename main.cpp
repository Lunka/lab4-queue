#include <iostream>
#include <unordered_map>
#include <string>

int firstUniqueChar(const std::string& s) {
    std::unordered_map<char, int> charCount;

    // Підрахунок частоти кожного символу
    for (char c : s) {
        charCount[c]++;
    }

    // Знаходження першого неповторюваного символу
    for (size_t i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;  // Повертаємо індекс першого неповторюваного символу
        }
    }

    return -1;  // Якщо немає неповторюваних символів
}

int main() {
    std::string s1 = "leopard";
    std::string s2 = "loveleopard";
    std::string s3 = "aabb";

    std::cout << "Input: " << s1 << ", Output: " << firstUniqueChar(s1) << std::endl;
    std::cout << "Input: " << s2 << ", Output: " << firstUniqueChar(s2) << std::endl;
    std::cout << "Input: " << s3 << ", Output: " << firstUniqueChar(s3) << std::endl;

    return 0;
}
