#include <iostream>
#include <vector>

class MyCircularQueue {
private:
    std::vector<int> queue; // Вектор для зберігання елементів черги
    int head;               // Індекс переднього елемента
    int tail;               // Індекс наступної вільної позиції
    int size;               // Кількість елементів у черзі
    int capacity;           // Максимальна ємність черги

public:
    // Конструктор, який ініціалізує чергу з розміром k
    MyCircularQueue(int k) {
        capacity = k;
        queue.resize(k);
        head = 0;
        tail = 0;
        size = 0;
    }

    // Отримує передній елемент з черги. Якщо черга порожня, повертає -1.
    int Front() {
        if (isEmpty()) return -1;
        return queue[head];
    }

    // Отримує останній елемент з черги. Якщо черга порожня, повертає -1.
    int Rear() {
        if (isEmpty()) return -1;
        // Враховуємо кругову природу черги
        return queue[(tail - 1 + capacity) % capacity];
    }

    // Вставляє елемент у циклічну чергу. Повертає true, якщо операція виконана успішно.
    bool enQueue(int value) {
        if (isFull()) return false;
        queue[tail] = value;
        tail = (tail + 1) % capacity; // Круговий індекс
        size++;
        return true;
    }

    // Видаляє елемент із циклічної черги. Повертає true, якщо операція виконана успішно.
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity; // Круговий індекс
        size--;
        return true;
    }

    // Перевіряє, чи циклічна черга порожня чи ні.
    bool isEmpty() {
        return size == 0;
    }

    // Перевіряє, чи заповнена циклічна черга.
    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue myCircularQueue(3); // Ініціалізація черги з розміром 3
    std::cout << myCircularQueue.enQueue(1) << std::endl; // Повертає true
    std::cout << myCircularQueue.enQueue(2) << std::endl; // Повертає true
    std::cout << myCircularQueue.enQueue(3) << std::endl; // Повертає true
    std::cout << myCircularQueue.enQueue(4) << std::endl; // Повертає false
    std::cout << myCircularQueue.Rear() << std::endl;     // Повертає 3
    std::cout << myCircularQueue.isFull() << std::endl;   // Повертає true
    std::cout << myCircularQueue.deQueue() << std::endl;   // Повертає true
    std::cout << myCircularQueue.enQueue(4) << std::endl;  // Повертає true
    std::cout << myCircularQueue.Rear() << std::endl;      // Повертає 4

    return 0;
}
