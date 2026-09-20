from cryptography.hazmat.primitives.asymmetric import dsa
from cryptography.hazmat.primitives import hashes
from cryptography.exceptions import InvalidSignature

# Key Pair Generation for Alice
alice_private_key = dsa.generate_private_key(key_size=2048)
alice_public_key = alice_private_key.public_key()

# Key Pair Generation for Bob
bob_private_key = dsa.generate_private_key(key_size=2048)
bob_public_key = bob_private_key.public_key()

data = b"Confidential Transaction Data"

# Signing the data using alice's private key
signature = alice_private_key.sign(
    data,
    hashes.SHA256()
)

print("Original Data:", data.decode())
print("---")

# Test 1 : with Alice's Key
try:
    alice_public_key.verify(signature, data, hashes.SHA256())
    print("Test 1 : Verification done")
except InvalidSignature:
    print("Test 1 : Invalid user detected")

# Test 2 : with Bob's Key
try:
    bob_public_key.verify(signature, data, hashes.SHA256())
    print("Test 2 : Verification done")
except InvalidSignature:
    print("Test 2 : Invalid user detected")