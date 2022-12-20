def main():
    '''call the isPalindrome() function'''
    isPalindrome()
#ask the user for input 
def isPalindrome():
    '''ask the user for an imput and string and check if it's a palndrome'''
    word=input('Enter a string or enter n to quit ')
    notpalin=True
    while word!='n':
        for value in range(len(word)):
            if word[value]!=word[-value-1]:
                notpalin=False
        if notpalin==True:
            print(word,'is a palindrome')
        if notpalin==False:
            print(word,'is not a palindrome')
        word=input('Enter a string or enter n ot quit ')


if __name__=='__main__':
    main()
    
