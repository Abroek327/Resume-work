#set up global variable time
time=int(input('How many companies did you buy stocks from '))

#define the load function
def load()->(str,int,float,float,float):
    '''Allows the user to input required information'''
    name=input('What company did you buy shares of? ')
    shares=int(input('How many shares did you purchase? '))
    pprice=float(input('What was the purchase price? $'))
    sprice=float(input('What was the selling price? $'))
    comm=float(input('What was the commission percent? '))
    return name,shares,pprice,sprice,comm

#define the calc funtion
def calc(shares:int,pprice,sprice,comm:float)->float:
    '''Processes numbers in order to generate an output later'''
    spay=shares*pprice
    cpay1=spay*comm
    sell=shares*sprice
    cpay2=sell*comm
    profit=(sell-cpay1)-(spay+cpay2)
    return spay,cpay1,sell,cpay2,profit

#define the output function and print the resutls 
def output(name:str,shares:int,pprice,sprice,comm,spay,cpay1,sell,cpay2,profit:float)->None:
    '''Print the output based on user input'''
    print('Stock name:', name)
    print('You bought',shares,'shares of',name)
    print('You payed $',format(spay,',.2f'),'for the stock')
    print('You payed $',format(cpay1,',.2f'),'in purchase commission')
    print('You sold the stock for $',format(sell,',.2f'))
    print('You payed $',format(cpay2,',.2f'),'in sale commission')
    print('You profited or lost $',format(profit,',.2f'))

#set up the main function to call the previous functions 
def main():
    '''Call the previously defined functions'''
    name,shares,pprice,sprice,comm=load()
    spay,cpay1,sell,cpay2,profit=calc(shares,pprice,sprice,comm)
    output(name,shares,pprice,sprice,comm,spay,cpay1,sell,cpay2,profit)

#et up the if statement so the program runs
if __name__=='__main__':
    for value in range(time):
        main()
