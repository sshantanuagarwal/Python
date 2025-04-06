import sqlite3
db = sqlite3.connect('emp.db')
cursor = db.cursor()

tableName = "emp"

cmd = """CREATE TABLE %s  ( fname CHAR( 20 ),
                            lname CHAR( 20 ),
                            id INT,
                            doj DATE,
                            designation CHAR( 20 ),
                            age INT,
                            experience INT,
                            salary INT,
                            PRIMARY KEY ( id ) )""" % ( tableName )
try:
    cursor.execute( cmd )
except:
    print( "table %s already exists" % ( tableName ) )

tableName = "leaves"
cmd = """CREATE TABLE %s ( id INT,
                           date DATE )""" % ( tableName )        
try:
    cursor.execute( cmd )
except:
    print( "table %s already exists" % ( tableName ) )


tableName = "login"
cmd = """CREATE TABLE %s ( id INT,
                           password CHAR ( 20 ),
                           PRIMARY KEY ( id ) )""" % ( tableName )        
try:
    cursor.execute( cmd )
except:
    print( "table %s already exists" % ( tableName ) )