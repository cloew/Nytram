from ctypes import cdll, c_bool, c_int, CFUNCTYPE

CPP_LIB = cdll.LoadLibrary("Nytram.dll")

GameLoopCallback = CFUNCTYPE(None)    
MouseButtonCallback = CFUNCTYPE(None, c_int, c_bool)
    
def GetCallbackMethod(self, cfunctionPrototype, objectMethod):
    def callback(*args):
        objectMethod(*args)
    return cfunctionPrototype(callback)