class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(words) == 0:
            return []
        counts = {}
        for word in words:
            counts[word] = words.count(word)
        indexes = []
        n, num, length = len(s), len(words), len(words[0])
        for i in range(n - num * length + 1):
            seen = {}
            j = 0
            while j < num:
                word = s[i + j * length: i + (j + 1) * length]
                if word in counts:
                    seen[word] = seen.get(word, 0) + 1
                    if seen[word] > counts[word]:
                        break
                else:
                    break
                j += 1
            if j == num:
                indexes.append(i)

        return indexes
