#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q1; // Перша черга
    std::queue<int> q2; // Друга черга

public:
    // Конструктор
    MyStack() {}

    // Додає елемент x на вершину стека
    void push(int x) {
        // Додаємо елемент у q2
        q2.push(x);

        // Переносимо всі елементи з q1 до q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Обмінюємо q1 і q2
        std::swap(q1, q2);
    }

    // Вилучає елемент з верхньої частини стека і повертає його
    int pop() {
        int topElement = q1.front(); // Зберігаємо верхній елемент
        q1.pop(); // Видаляємо верхній елемент
        return topElement;
    }

    // Повертає елемент на верхній частині стека
    int top() {
        return q1.front(); // Повертаємо верхній елемент
    }

    // Повертає true, якщо стек порожній, і false в іншому випадку
    bool empty() {
        return q1.empty(); // Перевіряємо, чи порожня q1
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    std::cout << "Top element: " << myStack.top() << std::endl; // Повертає 2
    std::cout << "Popped element: " << myStack.pop() << std::endl; // Повертає 2
    std::cout << "Is stack empty? " << (myStack.empty() ? "True" : "False") << std::endl; // Повертає False

    return 0;
}
