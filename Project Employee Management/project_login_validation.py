import proj_lib
import sqlite3

db = sqlite3.connect('emp.db')
cursor = db.cursor()


def login(id,password):
    cmd = "SELECT id FROM login where id==%d and password =='%s'" % ( id, password )
    cursor.execute(cmd)
    data = cursor.fetchone()
    
    if proj_lib.isValidId(id):
        if data:
            print( "%d successfully logged in." % ( id ) )
        else:
            if proj_lib.isValidId( id, tableName="login" ):
                print( "Forgot password???" )
                updatePassword( id )
            else:
                print( "Incorrect username %d" % ( id ) )

def updatePassword( id ):
    password = input( "Enter new password: " )
    cmd = "UPDATE login SET password='%s' WHERE id == %d" % ( password, id )
    print( cmd )
    cursor.execute( cmd )
    db.commit()
    login(id,password)
    
def signup( id, password ):
    if proj_lib.isValidId( id ):
        password=password
        print(id,password)
        cmd="SELECT * FROM login WHERE id == %d" % ( id )
        cursor.execute( cmd )
        data = cursor.fetchone()
        if data:
            print( "ID %d already signed up" % ( id ) )
        else:
            cmd= "INSERT into login ( id, password ) values (%d,'%s')" %(id,password)
            cursor.execute( cmd )
            print( "%d successfull logged in." %d ( id ) )
            
        login( id, password )

for id in range( 0, 100 ):
    signup( id, "pass" + str( id ) )

db.commit()
db.close()