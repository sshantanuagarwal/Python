import sqlite3
db = sqlite3.connect('emp.db')
cursor = db.cursor()

def resignation( id ):
    import proj_lib
    if proj_lib.isValidId( id ):
        cmd = "DELETE FROM emp where id == %d" % ( id )
        cursor.execute(cmd)
        print( "%d resigned" % ( id ) )
    
id = int(input( "Enter your id: " ) )
resignation( id )

db.commit()
db.close()



