#! /usr/bin/python3

import csv
import codecs
import re

def readFile( fileName ):
    csvReader = csv.reader(codecs.open ( fileName, 'rU' ))# , 'utf-16') )
    count = 0
    data = []
    header = None
    try:
        for row in csvReader:
            count += 1
            try:
                if row:
                    #print count, " : ", row
                    if count == 1:
                        header = row
                    else:
                        data.append( row )
                    if count == 5:
                        break
            except UnicodeEncodeError:
                print( "ERROR at line", count )


    except UnicodeEncodeError as e :
        print( "ERROR at line %d" % count )
        print( "Exiting with error", e )
    except _csv.Error as e: 
        print( "ERROR: CSV error" )
        print( "Exiting with error", e )
    return header, data

def parseFile( fileName ):
    # File read operation
    fileConfig = fileName#input( "Enter the config file" )
    headerConfig, config = readFile( fileConfig )

    configList = []
    for row in config:
        countHeader = 0
        configMap = {}
        for header in headerConfig:
            configMap[ header ] = row[ countHeader ]
            countHeader += 1

        configList.append( configMap )
    
    return configList


def validator():
    print( "Welcome to validator\n" )
    configurationFile = input( "Enter the name of config file path: " )
    dataFilePath = input( "Enter the name of data file path: " )
    config = parseFile( configurationFile )    
    content = parseFile( dataFilePath )

    '''
    print( "Config:\n" )
    for c in config:
        print( c )


    print( "\n\nContent:\n" )
    for c in content:
        print( c )
    '''
    
    print( "Config loaded successfully\n" )

    numRows = len( content )
    errors = []

    for c in config:
        col = c[ 'column' ] 
        man = c[ 'mandatory' ]
        unique = c[ 'unique' ]
        typeof = c[ 'type' ]

        colData = [ row[ col ] for row in content ]
        if( unique == 'true' ):
            if( len( set( colData ) ) != numRows ):
                errors.append( "Column %s should be unique but not all rows are unique" % col )

        count = 0
        for d in colData:
            count += 1
            if( man == 'true' ):
                if( len( d ) == 0 ):
                    errors.append( "Column " + col + " is manadatory but is empyt at row %d" % (count ) )
            if( typeof == 'string' ):
                if( type( d ) != type( "" ) ):
                    errors.append( str( d ) + " not of string type in row %d" % ( count ) )
            elif( typeof == 'phone' ):
                if( not re.match( "^[0-9]+", d ) and not len( d ) == 10 ):
                    errors.append( str( d ) + " not of phone type in row %d" % ( count ) )
            elif( typeof == 'email' ):
                print( d )
                mail = d.split( '@' )
                if len( mail ) != 2:
                    errors.append( str( d ) + " not of email type in row %d" % ( count ) )
                else:
                    for m in mail:
                        if( type( m ) != type( "" ) ):
                            errors.append( str( d ) + " not of email type in row %d" % ( count ) )



    if len( errors ) == 0:
        print( "Data file is valid" )

    else:
        for error in errors:
            print( error )

# Main function
validator()

