#include <iostream>

class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);

        return slow == 1;
    }
};

int main() {
    Solution sol;

    // 测试用例1: 快乐数 19
    int n1 = 19;
    std::cout << "测试 " << n1 << ": ";
    if (sol.isHappy(n1))
        std::cout << "是快乐数" << std::endl;
    else
        std::cout << "不是快乐数" << std::endl;

    // 测试用例2: 非快乐数 2
    int n2 = 2;
    std::cout << "测试 " << n2 << ": ";
    if (sol.isHappy(n2))
        std::cout << "是快乐数" << std::endl;
    else
        std::cout << "不是快乐数" << std::endl;

    // 测试用例3: 快乐数 7
    int n3 = 7;
    std::cout << "测试 " << n3 << ": ";
    if (sol.isHappy(n3))
        std::cout << "是快乐数" << std::endl;
    else
        std::cout << "不是快乐数" << std::endl;

    return 0;
}