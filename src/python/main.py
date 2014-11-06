from nytram import Run, Window

from ctypes import cdll, c_char_p, c_int, CFUNCTYPE
import sys

def main(args):
    """ Run the main file """
    window = Window()
    window.apply()
    print Run()

if __name__ == "__main__":
    main(sys.argv[1:])