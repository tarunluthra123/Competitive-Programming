class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for word in strs:
            key = "".join(sorted(word))
            d[key] = d.get(key, [])+[word]
        return d.values()
