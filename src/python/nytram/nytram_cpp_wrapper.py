from ctypes import cdll, c_char_p, c_int, CFUNCTYPE

CPP_LIB = cdll.LoadLibrary("Nytram.dll")