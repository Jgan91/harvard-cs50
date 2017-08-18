import sys
import cs50

def main():
    if (len(sys.argv) != 2):
        print("missing command-line argument")
        exit(1)
    
    # store cipher key as k    
    k = int(sys.argv[1])

    # ask user for plaintext to cipher
    print("plaintext: ")
    p = cs50.get_string();
    
    print("ciphertext: ")
    
    # iterate over characters in input
    for i in range(len(p)):
        if (p[i].isalpha()):
            if (p[i].isupper()):
                print(chr((ord(p[i]) - 65 + k) % 26 + 65), end="")
            if (p[i].islower()):
                print(chr((ord(p[i]) - 97 + k) % 25 + 97), end="")
        else:
            print(p[i])
    print("")
    
if __name__ == "__main__":
    main()