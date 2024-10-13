#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> movesToStamp(std::string stamp, std::string target) {
        int sLen = stamp.length();
        int tLen = target.length();
        std::string s(tLen, '?');  // Створюємо рядок s з усіх символів '?'
        std::vector<int> indices;    // Для зберігання індексів
        std::vector<bool> stamped(tLen, false); // Для відстеження, які частини вже "штамповані"
        
        // Функція для перевірки, чи можемо "штампувати" на позиції idx
        auto canStamp = [&](int idx) {
            bool can_stamp = false;
            for (int i = 0; i < sLen; i++) {
                // Якщо символ у s не '!' або символи однакові, дозволяємо штампування
                if (s[idx + i] == '?' || s[idx + i] == stamp[i]) {
                    if (s[idx + i] == stamp[i]) {
                        stamped[idx + i] = true; // Мітимо як "штамповане"
                    }
                    can_stamp = true; // Дозволяємо штампування
                } else {
                    return false; // Неприпустимо
                }
            }
            return can_stamp; // Повертаємо статус
        };

        // Функція для штампування на позиції idx
        auto stampAt = [&](int idx) {
            for (int i = 0; i < sLen; i++) {
                s[idx + i] = stamp[i]; // Замінюємо символи
            }
            indices.push_back(idx); // Додаємо індекс у список
        };

        int totalStamps = 0; // Лічильник для загальної кількості замін
        while (totalStamps < 10 * tLen) {
            bool stampedSomething = false;
            for (int i = 0; i <= tLen - sLen; i++) {
                if (canStamp(i)) { // Якщо можемо "штампувати"
                    stampAt(i); // Штампуємо
                    totalStamps++;
                    stampedSomething = true; // Зміна сталася
                }
            }
            if (!stampedSomething) break; // Якщо нічого не змінилося, виходимо
        }

        // Перевірка, чи ми досягли цільового рядка
        if (s == target) {
            std::reverse(indices.begin(), indices.end()); // Реверсуємо індекси для правильного порядку
            return indices; // Повертаємо індекси
        }
        return {}; // Якщо не вдалося, повертаємо порожній список
    }
};

int main() {
    Solution solution;
    std::string stamp = "abc";
    std::string target = "ababc";

    std::vector<int> result = solution.movesToStamp(stamp, target);
    for (int index : result) {
        std::cout << index << " ";
    }
    std::cout << std::endl; // Виводить [0, 2] або інші можливі варіанти

    return 0;
}
