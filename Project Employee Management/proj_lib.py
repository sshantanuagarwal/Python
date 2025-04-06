import sqlite3
db = sqlite3.connect('emp.db')
cursor = db.cursor()

def printTable( table ):
    cmd = "SELECT * FROM " + str( table ) 
    print( cmd )
    cursor.execute( cmd )
    data = cursor.fetchall()
    if data:
        for d in data:
            for i in d:
                print(i, end="\t" )
            print()  
    else:
        print( "TABLE DOES NOT EXISTS", table )
        
def isValidId( id, tableName="emp" ):
    cmd = "SELECT id FROM %s where id == %d" % ( tableName, id )
    print( cmd )
    cursor.execute( cmd )
    data=cursor.fetchone()
    if data:
        return True
    else:
        print( "Invalid ID %d" % ( id ) )
        return False


def generateReport( id, tableName ):
    cmd = "SELECT * FROM %s WHERE id == %d" % ( tableName, id )  
    print( cmd )
    cursor.execute( cmd )
    data = cursor.fetchall()
    if isValidId( id ) and data:
        file = open( str( id ) + ".txt", "a" )
        file.write( "Table data from %s:\n" % ( tableName ) )
        for d in data:
            for i in d:
                file.write( str( i ) + "\n" )
            file.write( "\n\n\n" )
        file.close()
