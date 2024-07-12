#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            if (charMap.find(s[right]) != charMap.end()) {
                // Move the left pointer to the right of the last occurrence of s[right]
                left = max(charMap[s[right]] + 1, left);
            }
            // Update the last occurrence of the character s[right]
            charMap[s[right]] = right;
            // Calculate the maximum length
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main() {
    Solution solution;
    string s = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " << solution.lengthOfLongestSubstring(s) << endl;

    s = "bbbbb";
    cout << "Length of longest substring without repeating characters: " << solution.lengthOfLongestSubstring(s) << endl;

    s = "pwwkew";
    cout << "Length of longest substring without repeating characters: " << solution.lengthOfLongestSubstring(s) << endl;

    s = "";
    cout << "Length of longest substring without repeating characters: " << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}
