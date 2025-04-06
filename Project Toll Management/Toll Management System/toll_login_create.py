import sqlite3
db=sqlite3.connect('TOLL.db')
cursor=db.cursor()
command='''CREATE TABLE LOGIN(
        VEHICLE_REGISTRATION_NUMBER varchar(10),
        USERNAME char(20),
        MOBILE_NUMBER bigint(10),
        PRIMARY KEY (VEHICLE_REGISTRATION_NUMBER))
        '''
cursor.execute(command)

db.commit()
db.close()
 
 
 

    
 

