from cryptography.hazmat.primitives.asymmetric import dh

parameters = dh.generate_parameters(generator=2, key_size=2048)

alice_private = parameters.generate_private_key()
alice_public = alice_private.public_key()

bob_private = parameters.generate_private_key()
bob_public = bob_private.public_key()

alice_shared = alice_private.exchange(bob_public)
bob_shared = bob_private.exchange(alice_public)

print("Do shared keys match?", alice_shared == bob_shared)
print("Shared Key Length:", len(alice_shared), "bytes")