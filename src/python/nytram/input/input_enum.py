from .input_code import InputCode

def input_enum(cls):
    """ Wrap an enum so it works as a colection of input codes """
    codeToName = {}
    codeToInput = {}
    for name in dir(cls):
        if not name.startswith('_'):
            code = getattr(cls, name)
            codeToName[code] = name.replace('_', ' ')
            
            inputCode = InputCode(code)
            inputCode.enum = cls
            codeToInput[code] = inputCode
            setattr(cls, name, inputCode)
            
    cls.__codeToName = codeToName
    cls.__codeToInput = codeToInput

    @classmethod
    def getCode(cls, code):
        try:
            return cls.__codeToInput[code]
        except KeyError:
            return None
    cls.getCode = getCode
    
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