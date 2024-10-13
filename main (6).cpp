#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxSumSubsequence(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> dp(n, INT_MIN); // Ініціалізація dp з мінімальним значенням
        int maxSum = INT_MIN; // Змінна для зберігання максимального значення

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i]; // Ініціалізація dp[i] як nums[i]

            // Перевірка попередніх елементів в межах k
            for (int j = std::max(0, i - k); j < i; j++) {
                if (dp[j] > 0) { // Додаємо лише позитивні значення
                    dp[i] = std::max(dp[i], dp[j] + nums[i]);
                }
            }

            // Оновлюємо загальне максимальне значення
            maxSum = std::max(maxSum, dp[i]);
        }

        return maxSum; // Повертаємо максимальну суму
    }
};

int main() {
    Solution solution;
    std::vector<int> nums1 = {10, 2, -10, 5, 20};
    int k1 = 2;
    std::cout << solution.maxSumSubsequence(nums1, k1) << std::endl; // Виведе: 37

    std::vector<int> nums2 = {-1, -2, -3};
    int k2 = 1;
    std::cout << solution.maxSumSubsequence(nums2, k2) << std::endl; // Виведе: -1

    std::vector<int> nums3 = {10, -2, -10, -5, 20};
    int k3 = 2;
    std::cout << solution.maxSumSubsequence(nums3, k3) << std::endl; // Виведе: 23

    return 0;
}
