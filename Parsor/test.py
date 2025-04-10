from json import *

assert parse('123') == (123, '') 
assert parse('123abc') == (123, 'abc')
assert parse('"123"abc') == ('123', 'abc')
assert parse('"abc"[123]') == ('abc', '[123]')
assert parse('[1,2,3]') == ([1,2,3], '')
#assert parse('[1,2,3][abc]') == ([1,2,3], '[abc]')
assert parse('[[[]]]') == ([[[]]], '')
assert parse('[[],[[]]]') == ([[],[[]]], '')
assert parse('["a",123,["x","y"]]') == (["a", 123, ["x", "y"]], '')
assert parse('{"a":1}') == ({"a": 1}, '')
assert parse('{"a":1,"b":2}') == ({"a":1,"b":2},'')
assert parse('{}') == ({}, '')
assert parse('{}abc') == ({}, 'abc')
assert parse('{"a":[[[]]]}') == ({"a":[[[]]]}, '')
assert parse('{"a":1,"b":[1,2,3],"c":{"d":1}}') == ({"a":1,"b":[1,2,3],"c":{"d":1}}, '')