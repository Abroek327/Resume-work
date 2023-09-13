from helper import helper
from db_operations import db_operations

#create connection path to playlist database, create clean data from songs.csv
db_ops = db_operations("playlist.db")
data = helper.data_cleaner("C:\School\Chapman\CPSC 408\playlist_app_complete\songs.csv")

#start screen of code
def startScreen():
    print("Welcome to your playlist!")

#returns if songs table has any records
def is_empty():
    query = '''
    SELECT COUNT(*)
    FROM songs;
    '''

    result = db_ops.single_record(query)
    return result == 0

#fills table from songs.csv if it's empty
def pre_process():
    if is_empty():
        attribute_count = len(data[0])
        placeholders = ("?,"*attribute_count)[:-1]
        query = "INSERT INTO songs VALUES("+placeholders+")"
        db_ops.bulk_insert(query, data)
    #if (is_empty()!=0):
    else:
        choice=input("Would you like to upload new music? Y/N: ")
        if (choice == 'Y' or choice=='y'):
            newData=input("Enter the filepath of the new music ")
            newData=helper.data_cleaner(newData)
            attribute_count = len(newData[0])
            placeholders = ("?,"*attribute_count)[:-1]
            query = "INSERT INTO songs VALUES("+placeholders+")"
            db_ops.bulk_insert(query,newData)
        if (choice =='N' or choice=='n'):
            return



        

#show user menu options
def options():
    print('''Select from the following menu options: 
    1. Find songs by artist
    2. Find songs by genre
    3. Find songs by feature
    4. Update song info
    5. Delete song by name
    6. Exit''')
    return helper.get_choice([1,2,3,4,5,6])

#search the songs table by artist
def search_by_artist():
    #get list of all artists in table
    query = '''
    SELECT DISTINCT Artist
    FROM songs;
    '''
    print("Artists in playlist: ")
    artists = db_ops.single_attribute(query)

    #show all artists, create dictionary of options, and let user choose
    choices = {}
    for i in range(len(artists)):
        print(i, artists[i])
        choices[i] = artists[i]
    index = helper.get_choice(choices.keys())

    #user can ask to see 1, 5, or all songs
    print("How many songs do you want returned for", choices[index]+"?")
    print("Enter 1, 5, or 0 for all songs")
    num = helper.get_choice([1,5,0])

    #print results
    query = '''SELECT DISTINCT name
    FROM songs
    WHERE Artist =:artist ORDER BY RANDOM()
    '''
    dictionary = {"artist":choices[index]}
    if num != 0:
        query +="LIMIT:lim"
        dictionary["lim"] = num
    results = db_ops.name_placeholder_query(query, dictionary)
    helper.pretty_print(results)

#search songs by genre
def search_by_genre():
    #get list of genres
    query = '''
    SELECT DISTINCT Genre
    FROM songs;
    '''
    print("Genres in playlist:")
    genres = db_ops.single_attribute(query)

    #show genres in table and create dictionary
    choices = {}
    for i in range(len(genres)):
        print(i, genres[i])
        choices[i] = genres[i]
    index = helper.get_choice(choices.keys())

    #user can ask to see 1, 5, or all songs
    print("How many songs do you want returned for", choices[index]+"?")
    print("Enter 1, 5, or 0 for all songs")
    num = helper.get_choice([1,5,0])

    #print results
    query = '''SELECT DISTINCT name
    FROM songs
    WHERE Genre =:genre ORDER BY RANDOM()
    '''
    dictionary = {"genre":choices[index]}
    if num != 0:
        query +="LIMIT:lim"
        dictionary["lim"] = num
    results = db_ops.name_placeholder_query(query, dictionary)
    helper.pretty_print(results)

#search songs table by features
def search_by_feature():
    #features we want to search by
    features = ['Danceability', 'Liveness', 'Loudness']
    choices = {}

    #show features in table and create dictionary
    choices = {}
    for i in range(len(features)):
        print(i, features[i])
        choices[i] = features[i]
    index = helper.get_choice(choices.keys())

    #user can ask to see 1, 5, or all songs
    print("How many songs do you want returned for", choices[index]+"?")
    print("Enter 1, 5, or 0 for all songs")
    num = helper.get_choice([1,5,0])

    #what order does the user want this returned in?
    print("Do you want results sorted in asc or desc order?")
    order = input("ASC or DESC: ")

    #print results
    query = "SELECT DISTINCT name FROM songs ORDER BY "+choices[index]+" "+order
    dictionary = {}
    if num != 0:
        query +=" LIMIT:lim"
        dictionary["lim"] = num
    results = db_ops.name_placeholder_query(query, dictionary)
    helper.pretty_print(results)

def update_song_info():
    
    songName=input("Enter the name of the song you wish to update: ")
    #songName=db_operations.single_attribute(songName)

    features=['name', 'Artist', 'Album', 'releaseDate', 'Explicit']
    choices={}
    print('\n'+"Song attributes: Name, Artist, Album, Release date, and Explicit ")
    print('\n'+"Select which attribute of "+songName+" you'd like to update ")
    #this bit is for picking which propery to update
    for i in range(len(features)):
        print(i, features[i])
        choices[i] = features[i]
    index = helper.get_choice(choices.keys())
    change=input("Please enter the updated informaton: ")
    
    songRecord= "SELECT songID FROM songs WHERE name LIKE '"+songName+"';"
   
    songRecord=db_ops.single_record(songRecord)
    
    query=" UPDATE songs SET  "+choices[index]+" = '"+change+ "' WHERE songID='"+songRecord+"';"
    
    db_ops.simple_query(query)

def delete_record():
    songName=input("Enter the name of the song you'd like to delete: ")
    songRecord= "SELECT songID FROM songs WHERE name LIKE '"+songName+"';"
    songRecord=db_ops.single_record(songRecord)
    query="DELETE FROM songs WHERE songID= '"+songRecord+"'"
    db_ops.simple_query(query)



#main program
startScreen()
pre_process()

#main program loop
while True:
    user_choice = options()
    if user_choice == 1:
        search_by_artist()
    if user_choice == 2:
        search_by_genre()
    if user_choice == 3:
        search_by_feature()
    if user_choice== 4 :
        update_song_info()
    if user_choice== 5:
        delete_record()
    if user_choice == 6:
        print("Goodbye!")
        break

db_ops.destructor()