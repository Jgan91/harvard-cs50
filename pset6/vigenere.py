import sys
import cs50

def main():
    if (len(sys.argv) != 2):
        print("missing command-line argument")
        exit(1)
        
    # store cipher key
    k = sys.argv[1]
    
    # return 1 if non-alphabetical characters in k
    if (not k.isalpha()):
        print("only enter alphabetical characters")
        exit(1)    
    
    # convert cipher key to rotation number
    r = list(k)
    
    for i in range(len(r)):
        # convert uppercase
        if (r[i].isupper()):
            r[i] = ord(k[i]) - 65
        else:
            r[i] = ord(k[i]) - 97
            
    
    # ask user for plaintext to cipher
    print("plaintext: ", end="")
    p = cs50.get_string()
    print("ciphertext: ", end="")
    # initialise position in rotation number
    rp = 0
    
    # iterate through characters in plaintext
    for char in range(len(p)):
        # if position in cipher key is longer than key, reset to 0 
        if (rp >= len(k)):
            rp = 0
        # check if character is alphabetical
        if (p[char].isalpha()):
            # check if character is uppercase
            if (p[char].isupper()):
                print(chr(((ord(p[char]) - 65 + r[rp]) % 26 + 65)), end="")
            else:
                print(chr(((ord(p[char]) - 97 + r[rp]) % 26 + 97)), end="")
            rp += 1
        else:
            print(p[char], end="")

    print("")

if __name__ == "__main__":
    main()