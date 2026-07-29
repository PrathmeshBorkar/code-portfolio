import random

plaintext = input("Enter hexadecimal text : ").upper()
n = int(input("Enter number of rounds : "))
i = 1

def generate_key(length):
    max_val = 16**length - 1
    return f"{random.randint(0, max_val):0{length}X}"

def fiestel(text, count):
    i = count

    mid = len(text) // 2
    L = int(text[:mid], 16)
    R = int(text[mid:], 16)

    key_hex = generate_key(mid)
    key = int(key_hex, 16)

    print(f"Round {i} Key: {key_hex}")

    R2 = L ^ (R ^ key)
    L2 = R

    width = mid
    ciphertext = f"{L2:0{width}X}{R2:0{width}X}"
    print(f"Round {i}: {ciphertext}")

    if i == n:
        return ciphertext
    else:
        return fiestel(ciphertext, i + 1)

ciphertext = fiestel(plaintext, i)
print("Final Ciphertext:", ciphertext)