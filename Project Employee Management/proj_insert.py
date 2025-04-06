import sqlite3
db = sqlite3.connect('emp.db')
cursor = db.cursor()

import random
designation = [ "Manager", "Director", "HR", "SD1", "SD2", "SD3" ]
for i in range( 100 ):
    cmd = """INSERT INTO %s
             ( fname, lname, id, doj, designation, age, experience, salary) VALUES
             ( "%s",  "%s", %d, "1-1-2015", "%s", %d, %d, %d )""" % \
              ( tableName, "Radical" + str( i ), "Technology" + str( i ), i, random.choice( designation ), random.randint( 18, 60 ),
                random.randint( 1, 40 ), random.randint(1, 50) * 100000  )
    cursor.execute( cmd )

db.commit()
db.close()

import proj_lib
proj_lib.printTable( tableName )

