class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        a = version1.split('.')
        b = version2.split('.')

        i,j = 0,0
        while i<len(a) or j<len(b):
            if i<len(a):
                q = int(a[i])
            else:
                q = 0

            if j<len(b):
                w = int(b[j])
            else:
                w = 0
            i += 1
            j += 1
            if q<w:
                return -1
            elif q>w:
                return 1

        return 0
