from nytram import Application, Window
from nytram.shaders import Shader, ShaderProgram, ShaderTypes

import sys

def main(args):
    """ Run the main file """
    window = Window(width=600, height=100, title="Test Application")
    app = Application(window=window)
    shaders = [Shader(1, "../cpp/resources/basic.vert", ShaderTypes.VERTEX_SHADER),
               Shader(2, "../cpp/resources/basic.frag", ShaderTypes.FRAGMENT_SHADER)]
    shaderProgram = ShaderProgram(1, shaders)
    print(app.run())

if __name__ == "__main__":
    main(sys.argv[1:])