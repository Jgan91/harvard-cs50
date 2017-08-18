import cs50

def main():
    # prompt user for credit card no.
    print("Number: ", end="")
    ccn = cs50.get_string()
    
    # check & report the card's validity
    print(check(ccn))

def check(ccn):
    # check which creditor the card belongs to then check for validity
    digits = len(ccn)
    if digits == 15 and (ccn[:2] == "34" or ccn[:2] == "37") and check_sum(ccn):
        return "AMEX"
    if (digits == 16 or digits == 13) and ccn[:1] == "4" and check_sum(ccn):
        return "VISA"
    if digits == 16 and (ccn[:2] == "51" or ccn[:2] == "52" or ccn[:2] == "53" or ccn[:2] == "54" or ccn[:2] == "55"):
        return "Mastercard"
    return "INVALID"

def check_sum(ccn):
    # starting from the second-last digit, multiply every other digit by 2
    multiply = ccn[-2::-2]
    products = []
    for i in range(len(multiply)):
        product = int(multiply[i]) * 2
        if (product > 9):
            for j in range(len(str(product))):
                products.append(int(str(product)[j]))
        else:
            products.append(product)
    
    # add the product's digits (not the products themselves)
    product_sum = 0
    for i in products:
        product_sum += i

    # add the previous sum to the digits that weren't multiplied by 2
    not_multiplied = ccn[::-2]
    for i in not_multiplied:
        product_sum += int(i)

    # if the last digit is 0 (sum % 10 == 0) the number is valid
    if (product_sum % 10 == 0):
        return True
        
    return False
    
    
if __name__ == "__main__":
    main()