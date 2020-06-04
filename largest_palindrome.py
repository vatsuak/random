class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 1:
            return s
        if isPalindrome(s):
            return s
        max_len = 0
        max_word =""
        for start in range(0,len(s)):
            for end in range(start+1,len(s)+1):
                word = s[start:end]
                if isPalindrome(word):
                    if max_len < len(word):
                        max_len = len(word)
                        max_word = word
        return max_word

def isPalindrome(s):
    if s == s[::-1]:
        return True 
    return False


if __name__ == '__main__':
    sol = Solution()
    print(sol.longestPalindrome("abba"))