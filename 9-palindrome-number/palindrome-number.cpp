#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        // Special cases:
        // As discussed above, when x < 0, x is not a palindrome.
        // Also if the last digit of the number is 0, for it to be a palindrome,
        // the first digit of the number also needs to be 0. Only 0 satisfies this.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        // Keep reversing digits until the reverted number becomes greater than or equal to the remaining x
        while (x > revertedNumber) {
            revertedNumber = (revertedNumber * 10) + (x % 10);
            x /= 10;
        }

        // When the length is an odd number, we can get rid of the middle digit by revertedNumber / 10
        // For example, for 12321, at the end of the while loop x = 12, revertedNumber = 123.
        // Since the middle digit doesn't matter in palindrome, we can safely remove it.
        return x == revertedNumber || x == revertedNumber / 10;
    }
};