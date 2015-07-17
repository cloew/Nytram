from .ortho_projection import OrthoProjection

from nytram.engine import CppEngine, VectorToArguments, EngineAttr
from nytram.vector import Vec3
from ctypes import c_float

class Camera:
    """ Represents a Camera in the Engine """
    eye = EngineAttr('setEye')
    projection = EngineAttr('setProjection')
    
    def __init__(self, eye=Vec3(0, 0, 10), projection=OrthoProjection()):
        """ Initialize the camera """
        self.eye = Vec3(eye)
        self.projection = projection
        
    def setEye(self):
        """ Set the eye in the C++ Engine """
        CppEngine.Camera_SetEye(*VectorToArguments(self.eye, c_float))
        
    def setProjection(self):
        """ Set the projection in the C++ Engine """
        self.projection.apply()