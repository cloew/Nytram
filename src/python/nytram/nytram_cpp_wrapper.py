from ctypes import cdll, c_bool, c_int, CFUNCTYPE

CPP_LIB = cdll.LoadLibrary("Nytram.dll")
    
MouseButtonCallback = CFUNCTYPE(None, c_int, c_bool)