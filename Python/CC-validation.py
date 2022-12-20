def main():
    '''call the isValid() function'''
    #user will input the credit card number as a string
    #call the function isValid() and print whether the credit card number is valid
    number=input('Enter a credit card number ')
    truth=isValid(number)
    if truth==True:
        print(number,'is valid')
    if truth==False:
        print(number,'is not valid')
    

def isValid(number)->bool:
    '''call the sumOfDoubleEvenPlace() and sumOfOddPlace() functions'''
    #return true if the card number is valid
    even_sum=sumOfDoubleEvenPlace(number)
    odd_sum=sumOfOddPlace(number)
    total_sum=even_sum+odd_sum
    if total_sum%10==0:
        return True
    else:
        return False

#set up the function to find the sum of the double even place digits
def sumOfDoubleEvenPlace(number)->int:
    '''find the sum of the even place digits and call the getDigit() function'''
    #get the result from step 2
    even_sum=0
    for index in range(-len(number)-2,-1,-2):
        double=int(number[index])*2
        double_even=getDigit(double)
        even_sum+=double_even
    return even_sum

#set the rules for doubling the even place numbers
def getDigit(double)->int:
    '''add the two digits of numbers>10 but<20'''
    #return this digit if it is a single digit, otherwise, return
    #the sum of the two digits
    if double==10:
        double=1
    if double==12:
        double=3
    if double==14:
        double=5
    if double==16:
        double=7
    if double==18:
        double=9
    if double<10:
        double=double
    return double

#set up the function for finding the sum of the odd place digits
def sumOfOddPlace(number)->int:
    '''find the sum of the odd place digits'''
    #return the sum of odd place digits in number
    odd_sum=0
    for index in range(-len(number)-2,-1,-2):
        odd_sum+=int(number[index])
    return odd_sum           

if __name__=='__main__':
    main()
