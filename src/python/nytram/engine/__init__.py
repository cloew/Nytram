from ctypes import cdll, c_bool, c_int, c_long, CFUNCTYPE
from .engine_attr import EngineAttr
from .wrapped_engine_attr import WrappedEngineAttr
from .engine_callback import EngineCallback
from .time import Time

NytramEngine = cdll.LoadLibrary("Nytram.dll")
Time = Time(NytramEngine)

EntityCallback = EngineCallback(CFUNCTYPE(None))
LoopCallback = EngineCallback(CFUNCTYPE(None, c_long))
KeyboardCallback = EngineCallback(CFUNCTYPE(None, c_int, c_bool))
MouseButtonCallback = EngineCallback(CFUNCTYPE(None, c_int, c_bool))
    
def ListToArray(l, ctype):
    """ Convert a List to an Array """
    return (ctype*len(l))(*l), len(l)
    
def VectorToArguments(v, ctype):
    """ Convert a Vector to a list of arguments """
    return [ctype(value) for value in v]