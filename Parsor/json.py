import re
from utils import *

def isdigit(s):
    return s in "01234567890"
   
def parse_string(string):
    m = re.search( "\"([a-zA-Z0-9]+)\"(.*)", string )
    if( m ):
        groups = list( m.groups() )
        if groups[1] is None:
            groups[1] = ''
    return tuple( groups )        

def parse_number(string):
    m = re.search( "([0-9]+)(.*)", string )
    assert m
    groups = list( m.groups() )
    if groups[1] is None:
        groups[1] = ''
    groups[ 0 ] = int( groups[ 0 ] )
    return tuple( groups )                

def parse_list(string):
    l = []
    m = re.search( "\[(.*)\](.*)", string )
    assert m
    groups = list( m.groups() )
    if groups[1] is None:
        groups[1] = ''
    data = groups[ 0 ]
    length = len( data )
    start = 0
    for i in range(length):
        if( data[ i ] == Token.LIST_DELIMITER ):
            if( data[ start : i ].isnumeric() ):
                l.append( int( data[ start : i ] ) )
            else:
                l.append( data[ start : i ] )
            start = i + 1
        elif( i == length - 1 ):
            if( data[ start : ].isnumeric() ):
                l.append( int( data[ start : ] ) )
            else:
                l.append( data[ start : ] )
    groups[ 0 ] = l
    return tuple( groups )  

def parse_dict(string):
    d = {}
    m = re.search( "\{(.*)\}(.*)", string )
    assert m
    groups = list( m.groups() )
    if groups[1] is None:
        groups[1] = ''
    data = groups[ 0 ].split( Token.DICT_DELIMITER )
    for item in data:
        length = len( item )
        print( item )
        for i in range( length ):
            if( item[ i ] == Token.DICT_SYMBOL ):
                break
        
        d[ item[ :i ] ] = item[ i + 1 : ]
        print( d )
    groups[ 0 ] = d
    return tuple( groups )

def parse(string):
    s = string[0]
    if s == Token.STRING_BEGIN:
        return parse_string(string)
    elif s == Token.LIST_BEGIN:
        return parse_list(string)
    elif s == Token.DICT_BEGIN:
        return parse_dict(string)
    elif isdigit( s ):
        return parse_number(string)
    else:
        raise ParserException( "Unknown Token: %s" % s )
