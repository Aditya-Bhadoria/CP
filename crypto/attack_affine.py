def remove(text):
    text = text.lower()
    result = ''
    for char in text:
        if 'a' <= char <= 'z':
            result += char
    return result

def inv(num):
    for i in range(1, 26):
        if (num*i)%26 == 1:
            return i
    return -1

def maxFreq(text):
    freq = [0] * 26
    for ch in text:
        if 'a' <= ch <= 'z':
            freq[ord(ch) - ord('a')] += 1
    first, second = -1, -1
    for i in range(26):
        if first == -1 or freq[i] > freq[first]:
            second = first
            first = i
        elif second == -1 or freq[i] > freq[second]:
            second = i
    return chr(first + ord('a')), chr(second + ord('a'))

def attack(text):
    text = remove(text)
    ch1, ch2 = maxFreq(text)
    # ch1 = 4a + b
    # ch2 = 19a + b
    a = (((ord(ch2) - ord(ch1) + 26) % 26) * 7) % 26
    b = (ord(ch1)-ord('a') - 4*a + 260) % 26
    a = inv(a)
    b = (a*b) % 26
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        dec = (a*x - b) % 26
        result += chr(dec + ord('a'))
    return result

if __name__ == "__main__":
    with open("/Users/Adity/Downloads/CP/input.txt", "r") as f:
        text = f.read()
    print('')
    print(attack(text))
    print('')