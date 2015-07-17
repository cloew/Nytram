from .ortho_projection import OrthoProjection

from nytram.engine import CppEngine, VectorToArguments, EngineAttr, WrappedEngineAttr
from nytram.vector import Vec3
from ctypes import c_float

class Camera:
    """ Represents a Camera in the Engine """
    eye = WrappedEngineAttr(Vec3, 'setEye')
    projection = EngineAttr('setProjection')
    
    def __init__(self, eye=Vec3(0, 0, 10), projection=OrthoProjection()):
        """ Initialize the camera """
        self.eye = eye
        self.projection = projection
        
    def setEye(self):
        """ Set the eye in the C++ Engine """
        CppEngine.Camera_SetEye(*VectorToArguments(self.eye, c_float))
        
    def setProjection(self):
        """ Set the projection in the C++ Engine """
        self.projection.apply(self)