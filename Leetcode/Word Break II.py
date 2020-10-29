class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:

        def rec(s, words, memo):
            if s in memo:
                return memo[s]
            if not s:
                return []
            res = []
            for word in words:
                if s.startswith(word):
                    if len(word) == len(s):
                        res.append(word)
                    else:
                        resultOfTheRest = rec(s[len(word):], words, memo)
                        for item in resultOfTheRest:
                            item = word + ' ' + item
                            res.append(item)
            memo[s] = res
            return res

        return rec(s, wordDict, {})
