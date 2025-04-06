import sqlite3
db = sqlite3.connect('emp.db')
cursor = db.cursor()

tableName = "leaves"

id = int( input( "Enter ur id ( 0 to 99 ): ") )
date = input( "Enter the date for leave: ")

import proj_lib
if proj_lib.isValidId( id ):
    cmd="INSERT INTO %s (id,date) values (%d,'%s')" % ( tableName, id, date )
    cursor.execute(cmd)

db.commit()
db.close()

proj_lib.printTable( tableName )