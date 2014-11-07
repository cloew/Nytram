# This is copied from http://github.com/aholkner/bacon/blob/master/bacon/native.py

def enum(cls):
    names = {}
    for key in dir(cls):
        if key[0] != '_':
            names[getattr(cls, key)] = key
    cls.__names = names
    
    @classmethod
    def tostring(cls, value):
        try:
            return cls.__names[value]
        except KeyError:
            return str(value)
    cls.tostring = tostring

    @classmethod
    def parse(cls, name):
        try:
            return getattr(cls, name)
        except KeyError:
            return int(name)
    cls.parse = parse
    return cls