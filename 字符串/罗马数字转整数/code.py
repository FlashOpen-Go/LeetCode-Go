roman = input("=>")

def romanToInt(s):
    ret = 0
    if s is None or len(s) == 0:
        return ret
    romanInt = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}

    for i in range(len(s) - 1):
        if romanInt[s[i]] < romanInt[s[i + 1]]:
            ret -= romanInt[s[i]]
        else:
            ret += romanInt[s[i]]
    ret += romanInt[s[len(s) - 1]]
    if ret <= 3999 and ret >= 1:
        return ret
    else:
        return False

print(romanToInt(roman))
    