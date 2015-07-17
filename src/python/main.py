from nytram import Application, Window
from nytram.entity import Entity, Transform, Rotation
from nytram.entity.camera import Camera, OrthoProjection
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
    transform = Transform()
    transform.entity = entity
    transform.position = [0, 0, 0]
    transform.scale = [1, 1, 1]
    transform.rotation = Rotation(inXY=90)
    
    projection = OrthoProjection(width=2, height=2)
    camera = Camera(eye=[0.0, 0.0, 10.0], projection=projection)
    
    print(app.run())

if __name__ == "__main__":
    main(sys.argv[1:])