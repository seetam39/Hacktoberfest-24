#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;  // Get the last digit
            x /= 10;  // Remove the last digit from x
            
            // Check if reversing causes overflow for positive or negative values
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            
            rev = rev * 10 + pop;  // Construct the reversed number
        }
        return rev;
    }
};

int main() {
    Solution solution;
    
    // Test the reverse function with a sample input
    int num = 123;
    cout << "Reversed of " << num << " is " << solution.reverse(num) << endl;

    num = -123;
    cout << "Reversed of " << num << " is " << solution.reverse(num) << endl;

    num = 1534236469;  // Case to check overflow
    cout << "Reversed of " << num << " is " << solution.reverse(num) << endl;
    
    return 0;
}
