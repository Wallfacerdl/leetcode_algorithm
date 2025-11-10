class Solution:

    def isValid(self, s: str) -> bool:
        lst = []
        for i in s:
            if lst == []:
                if i in [")", "}", "]"]:
                    return False
                else:
                    lst.append(i)
            else:
                if (
                    (lst[-1] == "(" and i == ")")
                    or (lst[-1] == "[" and i == "]")
                    or (lst[-1] == "{" and i == "}")
                ):
                    lst = lst[-1]
                else:
                    lst.append(i)

        if lst == []:
            return True
        else:
            return False


Solution().isValid("()")
