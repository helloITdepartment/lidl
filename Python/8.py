class Solution:
    def myAtoi(self, s: str) -> int:
        return max(min(int((re.findall("^([+-]?[0-9]+)", s.strip()) + ["0"])[0]), (1 << 31) - 1), -(1 << 31))
