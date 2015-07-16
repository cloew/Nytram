from nytram import Application, Window
from nytram.entity import Entity
from nytram.renderers import EntityRenderer
from nytram.shaders import Shader, ShaderProgram, ShaderTypes

import sys

def main(args):
    """ Run the main file """
    window = Window(width=400, height=400, title="Test Application")
    app = Application(window=window)
    shaders = [Shader(1, "../cpp/resources/basic.vert", ShaderTypes.VERTEX_SHADER),
               Shader(2, "../cpp/resources/basic.frag", ShaderTypes.FRAGMENT_SHADER)]
    shaderProgram = ShaderProgram(1, shaders)
    renderer = EntityRenderer(shaderProgram, elements=[0,1,2], vertexData={0:[-1, 1, 0, 0, 0, 0, -1, -1, 0],
                                                                           1:[1, 0, 0, 0, 1, 0, 0, 0, 1]})
    entity = Entity(renderer=renderer)
    print(app.run())

if __name__ == "__main__":
    main(sys.argv[1:])