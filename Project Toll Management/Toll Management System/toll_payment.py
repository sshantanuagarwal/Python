import sqlite3
db=sqlite3.connect('TOLL.db')
cursor=db.cursor()
command='''CREATE TABLE payment(
        VEHICLE_REGISTRATION_NUMBER varchar(10),
        DAYS int)
        '''
cursor.execute(command)

db.commit()
db.close()
 
 
 

    
 


