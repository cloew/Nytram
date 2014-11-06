from nytram import Application, Window

from ctypes import cdll, c_char_p, c_int, CFUNCTYPE
import sys

def main(args):
    """ Run the main file """
    window = Window(width=600, height=100)
    print Application(window=window).run()

if __name__ == "__main__":
    main(sys.argv[1:])