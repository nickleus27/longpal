#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        /**
         * concantenate string of odd length by using a meta character
         * in between each regular character and at the beginning and end
         * of string. This will simplify implementing Manachers algorithm
         * for even length strings and even length sub-palindromes.
         */
        std::string odd_str = "^#";
        for (char c : s)
        {
            odd_str += c;
            odd_str += '#';
        }
        odd_str += "$";

        int strlen = odd_str.size();
        /**
         * pal_radii will hold the value at each index,
         * of the number of characters that are palindrome
         * to the left and right of the same index in the
         * string odd_str. So pal_radii[i] is the palindrome
         * radius of odd_str[i]
         */
        std::vector<int> pal_radii(strlen, 0); // fill vector with 0's to init
        int center = 0;                        // holds the index of the center of the largest palindrome
        int right = 0;                         // holds the index of the

        for (int i = 1; i < strlen - 1; ++i)
        {
            pal_radii[i] = (right > i) ? std::min(right - i, pal_radii[2 * center - i]) : 0;
            while (odd_str[i + 1 + pal_radii[i]] == odd_str[i - 1 - pal_radii[i]])
                pal_radii[i]++;

            if (i + pal_radii[i] > right)
            {
                center = i;
                right = i + pal_radii[i];
            }
        }

        int max_len = *std::max_element(pal_radii.begin(), pal_radii.end());
        int center_index = std::distance(pal_radii.begin(), std::find(pal_radii.begin(), pal_radii.end(), max_len));
        return s.substr((center_index - max_len) / 2, max_len);
    }
};

int main()
{
    std::string str;
    Solution sol;
    std::cout << "Enter string: ";
    getline(std::cin, str);
    std::cout << sol.longestPalindrome(str) << std::endl;
    return 0;
}