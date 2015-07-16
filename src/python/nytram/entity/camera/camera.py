from .ortho_projection import OrthoProjection

from nytram.engine import CppEngine, VectorToArguments
from nytram.vector import Vec3
from ctypes import c_float

class Camera:
    """ Represents a Camera in the Engine """
    
    def __init__(self, eye=Vec3(0, 0, 10), projection=OrthoProjection()):
        """ Initialize the camera """
        self.eye = Vec3(eye)
        self.projection = projection
        self.projection.apply()
        
    @property
    def eye(self):
        """ Return the camera's eye coordinates """
        return self.__eye
        
    @eye.setter
    def eye(self, value):
        """ Set the camera's eye coordinates """
        self.__eye = Vec3(value)
        CppEngine.Camera_SetEye(*VectorToArguments(value, c_float))