class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        allpossible = []
        for i in range(33):
            value = list(str(2**i))
            value.sort()
            allpossible.append(value)
        
        value = list(str(n))
        value.sort()
        for i in allpossible:
            if i == value:
                return True
        return False
        