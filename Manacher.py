# Manacher's algorithm for to find longest palindrome substring in a string


class Solution:
    def longestPalindrome(self, s: str) -> str:

        if not s: 
            return ""

        modified_s = '#' + '#'.join(s) + '#'
        n = len(modified_s)

        P = [0] * n
        center = right = maxLen = 0
        start = end = 0 

        for i in range(n): 
            if i < right: 
                P[i] = min(right - i, P[2 * center - i])
            else: 
                P[i] = 1

            while i - P[i] >=0 and i + P[i] < n and modified_s[i - P[i]] == modified_s[i + P[i]]:
                P[i] += 1

            if i + P[i] - 1 > right: 
                center = i
                right = i + P[i] - 1

            if P[i] > maxLen: 
                maxLen = P[i]
                start = (i - P[i] + 1) // 2
                end = (i + P[i] - 1) // 2

        return s[start:end]

         


        
