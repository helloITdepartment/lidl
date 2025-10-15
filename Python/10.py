class Solution:
    memo = {}
    def isMatch(self, s: str, p: str) -> bool:
        # print("-", s, p)
        if (s, p) in Solution.memo:
            return Solution.memo[(s,p)]
            
        if s == p:
            return True

        if len(p) == 0:
            Solution.memo[(s,p)] = False
            return False

        if len(s) == 0:
            if not (len(p) > 1 and p[1] == "*"):
                Solution.memo[(s,p)] = False 
                return False

        if len(p) > 1 and p[1] == "*": #we're in a wildcard. Find what we're matching against and...?
            c = p[0]
            #dot case
            if c == ".":
                result = self.isMatch(s, p[2:]) or (s != "" and self.isMatch(s[1:], p))
                Solution.memo[(s,p)] = result
                return result
            else: #letter case
                result = self.isMatch(s, p[2:]) or (s != "" and s[0] == c and self.isMatch(s[1:], p))
                Solution.memo[(s,p)] = result
                return result
        elif p[0] == ".":
            result = self.isMatch(s[1:], p[1:])
            Solution.memo[(s,p)] = result
            return result
        elif s[0] == p[0]:
            result = s[0] == p[0] and self.isMatch(s[1:], p[1:])
            Solution.memo[(s,p)] = result
            return result 
        else:
            return False
