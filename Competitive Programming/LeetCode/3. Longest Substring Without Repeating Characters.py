# 3. Longest Substring Without Repeating Characters

# Given a string s, find the length of the longest 
# substring
#  without repeating characters.

# Example 1:

# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
# Example 2:

# Input: s = "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# Example 3:

# Input: s = "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3.
# Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

# Constraints:

# 0 <= s.length <= 5 * 104
# s consists of English letters, digits, symbols and spaces.

class Solution:
    def lengthOfLongestSubstring(self, s):
        alphaSet = set()
        start = 0
        length = 0

        for index, char in enumerate(s):
            while char in alphaSet:
                alphaSet.remove(s[start])
                start += 1

            alphaSet.add(char)
            length = max(length, index - start + 1)

        return length


if __name__ == '__main__':
	obj = Solution()
	print(obj.lengthOfLongestSubstring('pwwkew'))