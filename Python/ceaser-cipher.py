def encrypt():
    text = input("Enter text : ")
    shift = int(input("Enter shift : "))
    encrypted_text = ""
    for ch in text:
        if ch.isalpha():
            base = 'A' if ch.isupper() else 'a'
            encrypted_text += chr((ord(ch) - ord(base) + shift) % 26 + ord(base))
        else:
            encrypted_text += chr(ord(ch) + shift)
    
    print("Encrypted text : ", encrypted_text)
    
def decrypt():
    text = input("Enter encrypted text : ")
    shift = int(input("Enter shift : "))
    decrypted_text = ""
    for ch in text:
        if ch.isalpha():
            base = 'A' if ch.isupper() else 'a'
            decrypted_text += chr((ord(ch) - ord(base) - shift) % 26 + ord(base))
        else:
            decrypted_text += chr(ord(ch) - shift)
    
    print("Decrypted text : ", decrypted_text)
    
    
flag = 0

while(flag == 0):
    print("\n1.Encryption\n2.Decryption\n3.Exit")
    n = int(input("Enter your operation number : "))
    if(n == 1):
        encrypt()
    elif(n == 2):
        decrypt()
    elif(n == 3):
        flag = 1
    else:
        print("\nEnter valid number\n")
    