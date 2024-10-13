#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;  // Для зберігання максимальних значень
        std::deque<int> dq;       // Двостороння черга для зберігання індексів

        for (int i = 0; i < nums.size(); i++) {
            // Видалення індексів, які виходять за межі поточного вікна
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // Видалення індексів з dq, значення яких менше, ніж nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Додаємо індекс поточного елемента
            dq.push_back(i);

            // Додаємо максимум в результат, якщо вікно заповнене
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;  // Повертаємо список максимальних значень
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> result = solution.maxSlidingWindow(nums, k);
    for (int max : result) {
        std::cout << max << " "; // Виводить: 3 3 5 5 6 7
    }
    std::cout << std::endl;

    return 0;
}
