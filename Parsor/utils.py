class Token:
    STRING_BEGIN = STRING_END = '"'
    LIST_BEGIN = '['
    LIST_END = ']'
    LIST_DELIMITER = DICT_DELIMITER = ','
    DICT_SYMBOL = ':'
    DICT_BEGIN = '{'
    DICT_END = '}'
    WHITESPACE = ' '
    NEWLINE = '\n'

class ParserException(Exception):
    pass

