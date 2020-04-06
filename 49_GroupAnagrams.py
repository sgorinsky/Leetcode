class Solution(object):
    def groupAnagrams(self, strs):
        result = {}
        for word in strs:
            current_word_tuple = tuple(sorted(word))
            result[current_word_tuple] = [word] if current_word_tuple not in result else result[current_word_tuple] + [word]
        return result.values()

# solution for 30 day leetcode challenge
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        word_dict = {}
        
        for word in strs:
            list_word = list(word)
            list_word.sort()
            tup_word = tuple(list_word)
            if tup_word in word_dict:
                word_dict[tup_word].append(word)
            else:
                word_dict[tup_word] = [word]
        
        return [words for key, words in word_dict.items()]
