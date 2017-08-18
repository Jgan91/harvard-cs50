import cs50

def main():
    print("Height: ", end="")
    n = cs50.get_int()
    while (n > 23):
        print("Height: ", end="")
        n = cs50.get_int()
    for i in range(n):
        print_row(n, i)
    
def print_row(n, i):
    print_spaces(n, i)  
    print_blocks(i+1)
    print(" ", end="")
    print_blocks(i+1)
    print_spaces(n, i)
    print("")
    
def print_spaces(n, i):
    for j in range(n-i-1):
        print(" ", end="")
        
def print_blocks(i):
    for j in range(i):
        print("#", end="")
        
    
if __name__ == "__main__":
    main()