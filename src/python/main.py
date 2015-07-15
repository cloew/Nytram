from nytram import Application, Window
from nytram.shaders import Shader, ShaderTypes

from ctypes import cdll, c_char_p, c_int, CFUNCTYPE
import sys

def main(args):
    """ Run the main file """
    window = Window(width=600, height=100, title="Test Application")
    app = Application(window=window)
    shader = Shader(1, "../cpp/resources/basic.vert", ShaderTypes.VERTEX_SHADER)
    print(app.run())

if __name__ == "__main__":
    main(sys.argv[1:])