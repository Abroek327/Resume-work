import mysql.connector
import random
import tkinter as tk
import csv
from tkinter import ttk
from helper import helper
from tabulate import tabulate
import os

#NOTE the password changes from cpsc408! to cpsc408 like below. Make sure to change it back when you run it
#NOTE use pip install tabulate for the tabulate module above
conn = mysql.connector.connect(host="localhost", user="root", password="cpsc408",
                                auth_plugin='mysql_native_password', database="pokemon")

#create cursor Object
cur_obj = conn.cursor()


## show all databases... used for testing purposes
#cur_obj.execute("SHOW DATABASES;")
#for row in cur_obj:
    #print(row)
## test
#cur_obj.execute("SELECT * FROM abilities;")
#result = cur_obj.fetchall()
#helper.pretty_print(result)

# tuple to string
def tupToStr(tup):
    s = ''
    for item in tup:
        s = s + str(item)
    return s

def getUserID(username):
    query = "SELECT UID FROM user WHERE Username LIKE '" + username + "';"
    cur_obj.execute(query)
    uID = cur_obj.fetchall()[0]

    uID = tupToStr(uID)
    return uID

def startScreen():
    print("~ Pokemon Team Maker ~\nPress [1] for Returning User\nPress [2] for New User\nPress [0] to Quit\n")

    userInput = helper.get_choice([0,1,2,3])

    if userInput == 1:
        returningUser()
    if userInput == 2:
        newUser()
    if userInput == 0:
        print("Goodbye!\n")
    ##FOR TESTING
    if userInput == 3:
        query = "SELECT * FROM user;"
        cur_obj.execute(query)
        result = cur_obj.fetchall()
        helper.pretty_print(result)

def checkIfUserExists(username):
    isUser = 0
    query = "SELECT * FROM user WHERE Username LIKE '" + username + "';"
    cur_obj.execute(query)
    userCheck = cur_obj.fetchall()
    if userCheck:
        isUser = 1
    return isUser

def returningUser():
    user = input("Enter username, or enter [0] to go back.\n")

    if user == "0":
        print("\n")
        startScreen()
    else:
        if checkIfUserExists(user) == 0:
            print("User not found! Please try again\n")
            returningUser()
        if checkIfUserExists(user) == 1:
            p = input("Enter password: \n")
            passwordCheck(user,p)

def passwordCheck(username, password):
    query = "SELECT Password FROM user WHERE Username LIKE '" + username + "';"
    cur_obj.execute(query)
    passwordCheck = cur_obj.fetchone()
    helper.pretty_print(passwordCheck) #FOR TESTING PURPOSES

    if (password == passwordCheck[0]):
        userPortal(username)
    else:
        print("Incorrect password, please try again.\n")
        returningUser()


def newUser():
    print('''~ Creating new User account ~
    (Enter [0] to quit)
    ''')
    newUsername = input("Create a unique uername: \n")

    if newUsername == 0:
        startScreen()
    else:
        if checkIfUserExists(newUsername) == 1:
            #check if the new id created is already in database
            print("Username already in use! Please enter a different one.\n")
            newUser()
        else:
            password = input("Enter a password: \n")

            nuid = random.randrange(1, 999)

            query = "INSERT INTO user (UID, Username, Password) VALUES (%s, %s, %s)"
            values = [(nuid, newUsername, password)]

            cur_obj.executemany(query, values)
            conn.commit()

            userCheck = cur_obj.fetchall()
            helper.pretty_print(userCheck)

            print("Successfully created new account!\n")
            userPortal(newUsername)

def userPortal(username):
    print("Welcome, " + username + " !\n")
    print('''
    [1] View Team
    [2] Create Team
    [3] Edit Team
    [4] View Type Matchups
    [5] View Item Info
    [6] Export Team
    [0] Log Out
    ''')

    userInput = helper.get_choice([0,1,2,3,4,5,6])

    if userInput == 1:
        teamViewer(username)
    if userInput == 2:
        askToImport(username)
        #teamMaker(username)
    if userInput == 3:
        teamEditor(username)
    if userInput == 4:
        viewMatchups(username)
    if userInput == 5:
        viewItems(username)
    if userInput == 6:
        exportTeam()
    if userInput == 0:
        print("Logging out...\n")
        startScreen()

def askToImport(username):
    print("Do you want to import a team? [CSV file]\n")
    print("[1] YES | [2] NO")

    userInput = helper.get_choice([1,2])

    if userInput == 1:
        query = "SELECT * FROM Team WHERE userID LIKE '" + getUserID(username) + "';"
        cur_obj.execute(query)
        result = cur_obj.fetchall()
        if result:
            print("You already have a team!/n")
            userPortal(username)
        else:
            userFile = input("Please enter the name of the file with your team: ")
            if not os.path.isfile(userFile):
                print("Could not find file! Aborting.")
                userPortal(username)
            else:

                cleanedFile = helper.data_cleaner(userFile)

                attribute_count = len(cleanedFile[0])
                placeholders = ("?,"*attribute_count)[:-1]
                query = "INSERT INTO team VALUES("+placeholders+")"
                cur_obj.executemany(query,cleanedFile)
                conn.commit()
                print(userFile + " has been imported.\n")
                userPortal(username)
    if userInput == 2:
        teamMaker(username)

#BUG if the user inputs the same dexNum twice the program crashes (duplicate key error?)
def teamMaker(username):
    print("~ Create a Team ~\n")

    promptTimes = 6

    uID = getUserID(username)
    tID = random.randrange(1, 999)
    size = 6
    dbl=0
    tName=input("Enter a name for your team: \n")
    #ask if the user if they want the team to be for doubles or not
    dbl_or_nah=input("Would you like this team to be for doubles? [1 YES, 2 NO]\n")
    if dbl_or_nah==1:
        dbl=1
    elif dbl_or_nah==2:
        dbl=0
    
    #insert all the team info into the team table
    query = "INSERT INTO Team (TeamID, size, UserID, dbl, name) VALUES (%s, %s, %s, %s, %s)"
    values = [(tID, size, uID, dbl, tName)]
    cur_obj.executemany(query, values)
    conn.commit()
  
    #counter = 1

    for i in range(promptTimes):
        #get user input for what pokemon they want
        userMon = input("Provide the dex number of the Pokemon you would like to add to your team: \n")
        query = "SELECT name FROM mons WHERE dexNum = " + userMon + ";"
        cur_obj.execute(query)
        #get the name of the pokemon from the dex number as a variable 
        pkmnName = cur_obj.fetchall()[0]
        pkmnName = tupToStr(pkmnName)
        print(pkmnName + " has been added to your team.\n")
        uAbility=input("Enter the ID of the ability you would like to give to your " + pkmnName + ".\n")
        uItem=giveItem(pkmnName) 
        
        #Insert into the team_mon foregin key table
        query2 = "INSERT INTO team_mon(mID,tID,heldItem,aID) VALUES (%s, %s, %s, %s);"
        values = [(userMon,tID,uItem,uAbility)]
        cur_obj.executemany(query2, values)
        conn.commit()
        
        print(pkmnName + " has been inserted into your team.\n")

        movesetMaker(userMon, pkmnName) #DONE 

        #uItem=giveItem(userMon, pkmnName) # wip

  
    userPortal(username)


#TODO need to add teamID foreign key to move_set table and if possible remove move_ID from move_set table
def movesetMaker(dexNum, pkmnName):

    #generate random 3 digit set num
    setNum = random.randrange(1, 999)

    

    print("Create moveset for " + pkmnName + "\n")
    #ask for move ID's
    move1=input("Enter the ID of the first move you would like to add to " + pkmnName + "'s moveset: \n")
    move2=input("Enter the ID of the second move you would like to add to " + pkmnName + "'s moveset: \n")
    move3=input("Enter the ID of the third move you would like to add to " + pkmnName + "'s moveset: \n")
    move4=input("Enter the ID of the fourth move you would like to add to " + pkmnName + "'s moveset: \n")

    #insert into move_set table
    query="INSERT INTO move_set(setID, move1, move2, move3, move4, dexNum) VALUES (%s, %s, %s, %s, %s, %s)"
    values=[(setNum, move1, move2, move3, move4, dexNum)]
    cur_obj.executemany(query, values)
    conn.commit()


  

    print("Moveset creation completed.\n")

def giveItem(pkmnName):
    print("Give " + pkmnName + " an item? [1 YES, 2 NO]\n")

    userInput = helper.get_choice([1,2])

    if userInput == 1:
        userItem = input("Enter the ID of the item you want to give to your " + pkmnName + ".\n")
        #print ("UserItem: "+userItem)
        #query = "SELECT * FROM items WHERE item = " + userItem + ";"
        #cur_obj.execute(query)
        #selecteditem = cur_obj.fetchall()[0]
        return userItem
        #selecteditem = tupToStr(selecteditem)
        #dNum=str(dexNum)
        #print("DEX NUM: "+str(dexNum))
        #query = "INSERT INTO team_mon (heldItem) VALUE ("+userItem+") WHERE mID = " + str(dexNum) + ";"

        
        #cur_obj.execute(query)
        #conn.commit()

        #print("You have given a " + userItem + " to your " + pkmnName + "!\n")


    if userInput == 2:
        print("You have decided to not give " +  pkmnName + " an item.\n")
        pass



def teamViewer(username):
    query = "SELECT * FROM Team WHERE userID LIKE '" + getUserID(username) + "';"
    cur_obj.execute(query)
    result = cur_obj.fetchall()
    if result:
        print("YOUR TEAM\n")
        helper.pretty_print(result)
    else:
        print("No team found in database!\n")
        userPortal(username)

def teamEditor(username): #WIP
    teamViewer(username)

    userMon = input("Enter the dex number of which pokemon you would like to edit: \n")
    print('''Choose what you would like to edit.
    [1] Create new moveset for pokemon
    [2] Give pokemon a new item.
    [3] Delete entire team.''')

    userInput = helper.get_choice([1,2])

    query = "SELECT name FROM mons WHERE dexNum = " + userMon + ";"
    cur_obj.execute(query)
    pkmnName = cur_obj.fetchall()[0]

    pkmnName = tupToStr(pkmnName)

    if userInput == 1:
        query = "DELETE * FROM Move_set WHERE dexNum LIKE '" + userMon + "';"
        cur_obj.execute(query)
        movesetMaker(userMon, pkmnName)
        userPortal(username)
    if userInput == 2:
        query = "DELETE itemID FROM team WHERE dexNum LIKE '" + userMon + "';"
        cur_obj.execute(query)
        giveItem(userMon, pkmnName)
        userPortal(username)
    if userInput == 3:
        print("Are you sure you want to delete your team? This cannot be undone\n")
        print("[1] YES | [2] NO\n")
        deleteChoice = helper.get_choice([1,2])
        if deleteChoice == 1:
            query = "DELETE * FROM team;"
            cur_obj.execute(query)
            query = "DELETE * FROM Move_set;"
            cur_obj.execute(query)
            print("Your team has been deleted.\n")
            userPortal(username)
        if deleteChoice == 2:
            print("Going back to main menu...\n")
            userPortal(username)


def viewMatchups(username):
    promptLoop = True
    while promptLoop:
        type1 = input("Enter a type: \n")
        # null check needed
        type2 = input("Enter the type you want to compare with: \n")

        query = "SELECT * FROM moves WHERE type LIKE " + type1 + " OR " + type2 + ";"
        cur_obj.execute(query)
        result = cur_obj.fetchall()
        helper.pretty_print(result)
        promptLoop = False

    print("See another matchup? [1] Yes [2] No \n")
    userInput = helper.get_choice([1,2])

    if userInput == 1:
        promptLoop = True
    if userInput == 2:
        userPortal(username)

def viewItems(username):
    print('''[1] Print list of all items
    [2] Print list of items with descriptions''')

    userInput = helper.get_choice([1,2])

    if userInput == 1:
        query = "SELECT item FROM items;"
        cur_obj.execute(query)
        result = cur_obj.fetchall()
        helper.pretty_print(result)
    if userInput == 2:
        query = "SELECT * FROM items;"
        cur_obj.execute(query)
        result = cur_obj.fetchall()
        helper.pretty_print(result)

    userPortal(username)


def exportTeam(): #WIP

    # reference: https://gist.github.com/madan712/f27ac3b703a541abbcd63871a4a56636
    print("Exporting your team...\n")
    try:
        query = "SELECT * FROM team;"
        cur_obj.execute(query)

        header = [row[0] for row in cur_obj.description]
        result = cur_obj.fetchall()
        rows = result

        f = open('PokemonTeam.csv', 'w')

        f.write(','.join(header) + '\n')

        for row in rows:
            f.write(','.join(str(r) for r in row) + '\n')

        f.close()
        print(str(len(rows)) + ' rows written successfully to ' + f.name)
    except:
        print("Error! Could not export!\n")




startScreen()
#giveItem(706, "Goodra")

'''
def test1():
    query = "SELECT count(dexNum) FROM mons;"
    cur_obj.execute(query)
    result = cur_obj.fetchall()
    #helper.pretty_print(result)
    print(result[0][0])


#test1()
#page backbone
class Page(tk.Frame):
    def __init__(self, *args, **kwargs):
        tk.Frame.__init__(self, *args, **kwargs)
    #def show(self):
     #   self.lift()
    def show(self):
            # Destroy login page before showing teamBuilder
        login_page = self.master.children['.!mainView.!loginBox']
        login_page.destroy()
            
            # Show teamBuilder
        self.lift()
   
class loginBox(Page):
   def __init__(self, *args, **kwargs):
       Page.__init__(self, *args, **kwargs)
       #label = tk.Label(self, text="Welcome to Pokemon Team Maker")
       #label.pack(side="top", fill="both", expand=True)

       #create entry box for username
       Uname_head=tk.Label(self,text="Username",font=("Arial",10,"bold"))
       Uname_head.pack(pady=20)
       Uname=tk.Entry(self,width=30)
       Uname.pack(pady=20)

       #create entry box for password

       pWord_head=tk.Label(self,text="Password",font=("Arial",10,"bold"))
       pWord_head.pack()
       pWord=tk.Entry(self,width=30)
       pWord.pack(pady=40)

#page 2: new user page
class newUserPage(Page):
   def __init__(self, *args, **kwargs):
       Page.__init__(self, *args, **kwargs)
       #label = tk.Label(self, text="Welcome to Pokemon Team Maker")
       #label.pack(side="top", fill="both", expand=True)

       #create entry box for username
       Uname_head=tk.Label(self,text="Enter your name",font=("Arial",10,"bold"))
       Uname_head.pack(pady=20)
       Uname=tk.Entry(self,width=30)
       Uname.pack(pady=20)

       #create entry box for password

       pWord_head=tk.Label(self,text="Password",font=("Arial",10,"bold"))
       pWord_head.pack()
       pWord=tk.Entry(self,width=30)
       pWord.pack(pady=40)

#page 3; team builder
class teamBuilder(Page):
    def __init__(self, *args, **kwargs):
        Page.__init__(self, *args, **kwargs)
        #Page.destroy(self)
        #get the whole mons table to display
        query1 = "SELECT * FROM mons;"
        cur_obj.execute(query1)
        results = cur_obj.fetchall()


        #get the number of mons in the table (my version is missing the first 3 entries for some reason but it shouldn't matter)
        query2="SELECT count(dexNum) FROM mons;"
        cur_obj.execute(query2)
        results2=cur_obj.fetchall()
        count=results2[0][0]
        #below needs some work but much better than last impelmentation
        table=ttk.Treeview(self, columns=('Dex Number', 'Name', 'Type 1', 'Type 2','Total' , 'HP', 'Attack', 'Defense',
                                          'Sp. Attack', 'Sp. Defense', 'Speed', 'Generation','Legendary'), show='headings')
        table.pack(fill='both', expand=True)
        for i in range (count):
            table.insert(parent='', index='end', iid=i, values=(results[i][0], results[i][1], results[i][2], results[i][3],
                                                                 results[i][4], results[i][5], results[i][6], results[i][7],
                                                                 results[i][8])) #results[i][9], results[i][10]))
        #events
        table.bind('<<TreeviewSelect>>', lambda event: print(table.selection()))
        def show(self):
            # Destroy login page before showing teamBuilder
            login_page = self.master.children['.!mainView.!loginBox']
            login_page.destroy()
            
            # Show teamBuilder
            self.lift()

class mainView(tk.Frame):
    def __init__(self, *args, **kwargs):
        #define the frame
        tk.Frame.__init__(self, *args, **kwargs)
        #call the pages
        p1 = loginBox(self)
        p2 = newUserPage(self)
        p3 = teamBuilder(self)
        #create button frame and containter
        #buttonframe = tk.Frame(self)
        container = tk.Frame(self)
        #buttonframe.pack(pady=25, side="top", fill="x", expand=False)
        container.pack(side="top", fill="both", expand=True)

        p1.place(in_=container, x=0, y=0, relwidth=1, relheight=1)
        p2.place(in_=container, x=0, y=0, relwidth=1, relheight=1)
        p3.place(in_=container, x=0, y=0, relwidth=1, relheight=1)

        #create new user button
        nUser = tk.Button( text="Create an account", command=p2.show)
        nUser.place(x=15,y=350)

        #create login button
        loginButt = tk.Button(text="Login", command=p3.show)
        loginButt.place(x=333,y=350)
        
        p1.show()

#declaration of main
if __name__ == "__main__":
    #create the tk window
    root=tk.Tk()
    #connect to the backbone of the gui
    main=mainView(root)
    main.pack(side="top", fill="both", expand=True)
    #window size
    root.wm_geometry("400x400")
    root.title("Pokemon Team Maker")
    root.mainloop()
'''
conn.close
