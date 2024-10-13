#include <iostream>
#include <queue>

class RecentCounter {
private:
    std::queue<int> requests; // Черга для зберігання запитів

public:
    // Конструктор
    RecentCounter() {}

    // Додає новий запит у момент часу t та повертає кількість запитів за останні 3000 мілісекунд
    int ping(int t) {
        // Додаємо новий запит у чергу
        requests.push(t);

        // Визначаємо діапазон часу для видалення запитів, які виходять за межі 3000 мілісекунд
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop(); // Видаляємо старі запити
        }

        // Повертаємо кількість запитів у черзі
        return requests.size();
    }
};

int main() {
    RecentCounter recentCounter;
    std::cout << recentCounter.ping(1) << std::endl;    // Повертає 1
    std::cout << recentCounter.ping(100) << std::endl;  // Повертає 2
    std::cout << recentCounter.ping(3001) << std::endl; // Повертає 3
    std::cout << recentCounter.ping(3002) << std::endl; // Повертає 3

    return 0;
}
