import random

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def ext_gcd(a, b):
    if a == 0:
        return b, 0, 1
    g, x1, y1 = ext_gcd(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return g, x, y

def mod_inverse(e, phi):
    g, x, y = ext_gcd(e, phi)
    return x % phi

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def generate_keys(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)

    e = random.randrange(2, phi)
    while gcd(e, phi) != 1:
        e = random.randrange(2, phi)

    d = mod_inverse(e, phi)
    return (e, n), (d, n)

def encrypt(msg, pub_key):
    e, n = pub_key
    return [pow(ord(ch), e, n) for ch in msg]

def decrypt(cipher, priv_key):
    d, n = priv_key
    return ''.join(chr(pow(c, d, n)) for c in cipher)

p = 61
q = 53

if not is_prime(p) or not is_prime(q):
    print("p and q must be prime numbers")
elif p == q:
    print("p and q cannot be the same")
else:
    pub_key, priv_key = generate_keys(p, q)
    print("Public Key :", pub_key)
    print("Private Key:", priv_key)

    msg = "HELLO"
    print("\nOriginal Message :", msg)

    enc = encrypt(msg, pub_key)
    print("Encrypted Message:", enc)

    dec = decrypt(enc, priv_key)
    print("Decrypted Message:", dec)
    