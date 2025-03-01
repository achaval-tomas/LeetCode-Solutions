class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        i, j, n = 0, 1, len(s)
        longest = 0

        # range of unicode values for numbers, symbols and letters
        chars = [False for _ in range(128)]

        while (i < j <= n):
            # "use" char at position i
            chars[ord(s[i])] = True
            
            while j < n and not chars[ord(s[j])]:
                # find new unseen characters until repeated
                chars[ord(s[j])] = True
                j += 1
            
            longest = max(longest, j-i)
            if j == n:
                # longest substring was found
                break

            while s[i] != s[j]:
                # go up to one over the first occurence of the repeated character
                chars[ord(s[i])] = False
                i += 1

            i += 1
            j += 1
        
        return longest