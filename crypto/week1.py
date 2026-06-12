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

def shift_encrypt(key, text):
    text = remove(text)
    result = ''
    for char in text:
        if 'a' <= char <= 'z':
            x = ord(char) - ord('a')
            enc = (x + key) % 26
            result += chr(enc + ord('a'))
        else:
            result += char
    return result

def shift_decrypt(key, text):
    text = remove(text)
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        dec = (x - key + 26) % 26
        result += chr(dec + ord('a'))
    return result

def affine_enc(a, b, text):
    text = remove(text)
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        enc = (a*x + b) % 26
        result += chr(enc + ord('a'))
    return result

def affine_dec(a, b, text):
    text = remove(text)
    a = inv(a)
    b = (a*b) % 26
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        dec = (a*x - b) % 26
        result += chr(dec + ord('a'))
    return result

def vigen_enc(key, text):
    text = remove(text)
    j, n = 0, len(key)
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        y = ord(key[j%n]) - ord('a')
        enc = (x + y) % 26
        result += chr(enc + ord('a'))
        j = j + 1
    return result

def vigen_dec(key, text):
    j, n = 0, len(key)
    text = remove(text)
    result = ''
    for char in text:
        x = ord(char) - ord('a')
        y = ord(key[j%n]) - ord('a')
        dec = (x - y + 26) % 26
        result += chr(dec + ord('a'))
        j = j + 1
    return result

if __name__ == "__main__":
    key, text = "crypto", "goodmorning"
    # key = input()
    key = input("Enter key: ")
    text = input("Enter string: ")
    t1 = shift_encrypt(5, text)
    print(t1)
    print(shift_decrypt(5, t1))
    t1 = affine_enc(5, 8, text)
    print(t1)
    print(affine_dec(5, 8, t1))
    t1 = vigen_enc(key, text)
    print(t1)
    print(vigen_dec(key, t1))
