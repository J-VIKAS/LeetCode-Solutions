class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1 = list(version1.split('.'))
        version2 = list(version2.split('.'))  
        version1 = [int(i) for i in version1]
        version2 = [int(i) for i in version2]
        
        n = max(len(version1),len(version2))
        version1 += [0]*(n-len(version1))
        version2 += [0]*(n-len(version2))
        
        for i in range(len(version1)):
            if version1[i] > version2[i]: return 1
            elif version1[i] < version2[i]: return -1
        return 0