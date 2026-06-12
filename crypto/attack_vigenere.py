#Vigenere Cipher Attack Implementation

import math

def VignereAttack(cipher):

    # To find the indexes of first letters of 3 length substrings occuring ateast 3 times
    cipher=cipher.lower()
    n=len(cipher)
    L=[]
    for i in range(n-2):
        cnt=0
        S=[]
        for j in range(i+3,n-2):
            if(cipher[i]==cipher[j] and cipher[i+1]==cipher[j+1] and cipher[i+2]==cipher[j+2]):
                cnt+=1
                if(j not in L):
                    S.append(j)
            if(cnt==2):
                L.append(i)
                L.extend(S)
                break

        if(len(L)==3):
            break
    
    # To find the length of key
    g=math.gcd(L[1]-L[0],L[2]-L[1])
    
    # Storing the actual probabilities of alphabets occuring in dictionary
    eng_freq = {
        'a': 0.08167, 'b': 0.01492, 'c': 0.02782, 'd': 0.04253, 'e': 0.12702,
        'f': 0.02228, 'g': 0.02015, 'h': 0.06094, 'i': 0.06966, 'j': 0.00153,
        'k': 0.00772, 'l': 0.04025, 'm': 0.02406, 'n': 0.06749, 'o': 0.07507,
        'p': 0.01929, 'q': 0.00095, 'r': 0.05987, 's': 0.06327, 't': 0.09056,
        'u': 0.02758, 'v': 0.00978, 'w': 0.02360, 'x': 0.00150, 'y': 0.01974,
        'z': 0.00074
    }
    
    # Divide the ciphertext into length of key columns
    d=len(cipher)//g
    Lcols=[""]*g
    for j in range(g):
        col=""
        for i in range(j,len(cipher),g):
            col+=cipher[i]
        Lcols[j]=col
    
    # Finding key 
    key=""
    for i in Lcols:
        diff = 0.065
        shift = 0
        for j in range(26):
            p = 0
            for k in eng_freq:
                f = i.count(chr(((ord(k) - 97 + j) % 26) + 97)) / len(i)
                p += f * eng_freq[k]
        
            if abs(p - 0.065) < diff:
                diff = abs(p - 0.065)
                shift = j
    
        key += chr(shift + 97)
    
    # Decrypting the cipherText
    while(len(key)<len(cipher)):
        key+=key
    plain=""
    for i in range(len(cipher)):
        if(cipher[i].isalpha()):
            a=chr(((ord(cipher[i].lower())-ord(key[i].lower())+26)%26)+97)
            plain+=a
    print("Plaintext: ",plain)
cipher=input("Enter CipherText: ")
VignereAttack(cipher)
