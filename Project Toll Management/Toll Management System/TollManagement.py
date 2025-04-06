import sqlite3
db=sqlite3.connect('TOLL.db')
cursor=db.cursor()

def display(table):
    command='''SELECT * FROM '''+table
    cursor.execute(command)
    data=cursor.fetchall()
    for d in data:
        for i in d:
           print i,
           print '\t\t',
        print '\n'

def signup(reg_no,name,mob):
    command = '''INSERT INTO LOGIN (
                 VEHICLE_REGISTRATION_NUMBER,
                 USERNAME,
                 MOBILE_NUMBER )
                 VALUES( '%s', '%s', %d ) ''' % ( reg_no, name , mob )
    cursor.execute(command)
    from gtts import gTTS
    myObj = gTTS( text= "welcome " + reg_no.replace( "-", " " ).replace( '0', "Zero" ), 
                  lang = "en", slow=False )
    myObj.save( "Hello.mp3" )
    import os
    os.system( "mpg321 Hello.mp3" )


reg_no = str( input( "Enter the registration number: " ) )
name  = str( input( "Enter the owner name: " ) )
mob = int( input( "Enter your mobile number: " ) )
for i in range(5):
    d = int( input( '''enter the pass type
                       enter 0 for weekly pass
                       enter 1 for monthly pass
                       enter 2 for 6 month pass
                       enter 3 for yearly pass
                       enter 4 for customised pass: ''' ) )
    if( d == 0 ):
        days=7
    elif( d == 1 ):
        days=30
    elif( d == 2 ):
        days=180
    elif( d == 3 ):
        days=365
    elif( d == 4 ):
        days = int( input( 'Enter no of days' ) )
    else:
        print('Wrong choice try again')
    if(d>=0 and d<5):
        break
signup( reg_no, name, mob )
print 'cash to collect' ,5*days

command='''INSERT INTO PAYMENT(
        VEHICLE_REGISTRATION_NUMBER,
        DAYS)
        VALUES('%s',%d)'''%(reg_no,days)


cursor.execute(command)
db.commit()
display('payment')
display('login')
db.close()
