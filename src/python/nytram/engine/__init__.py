from ctypes import cdll, c_bool, c_int, CFUNCTYPE
from .engine_attr import EngineAttr

CppEngine = cdll.LoadLibrary("Nytram.dll")

GameLoopCallback = CFUNCTYPE(None)
KeyboardCallback = CFUNCTYPE(None, c_int, c_bool)
MouseButtonCallback = CFUNCTYPE(None, c_int, c_bool)
    
def GetCallbackMethod(self, cfunctionPrototype, objectMethod):
    def callback(*args):
        objectMethod(*args)
    return cfunctionPrototype(callback)
    
def ListToArray(l, ctype):
    """ Convert a List to an Array """
    return (ctype*len(l))(*l), len(l)
    
def VectorToArguments(v, ctype):
    """ Convert a Vector to a list of arguments """
    return [ctype(value) for value in v]