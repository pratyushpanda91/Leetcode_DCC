class Solution:
    def isEvenOrOdd(self, num: float) -> str:
        integer_part = int(num)   # ignore decimal part
        if integer_part % 2 == 0:
            return "even"
        else:
            return "odd"
