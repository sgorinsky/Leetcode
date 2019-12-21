class Solution(object):
    def groupAnagrams(self, strs):
        result = {}
        for word in strs:
            current_word_tuple = tuple(sorted(word))
            result[current_word_tuple] = [word] if current_word_tuple not in result else result[current_word_tuple] + [word]
        return result.values()
