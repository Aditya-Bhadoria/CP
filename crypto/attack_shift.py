def remove(text):
    text = text.lower()
    result = ''
    for char in text:
        if 'a' <= char <= 'z':
            result += char
    return result

def maxFreq(text):
    freq = [0] * 26
    for ch in text:
        freq[ord(ch)-ord('a')] += 1
    max_freq, maxChar = 0, ''
    for i in range(26):
        if freq[i] > max_freq:
            max_freq = freq[i]
            maxChar = chr(i + ord('a'))
    return maxChar

def attack(text):
    text = remove(text)
    ch = maxFreq(text)
    key = (ord(ch) - ord('e') + 26) % 26
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        enc = (x - key + 26) % 26
        result += chr(enc + ord('a'))
    return result

if __name__ == "__main__":
    with open("/Users/Adity/Downloads/CP/input.txt", "r") as f:
        text = f.read()
    print('')
    print(attack(text))
    print('')