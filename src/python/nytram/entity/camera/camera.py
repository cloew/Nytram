from .ortho_projection import OrthoProjection

from nytram.engine import CppEngine, ListToArray
from ctypes import c_float

class Camera:
    """ Represents a Camera in the Engine """
    
    def __init__(self, eye=[0, 0, 10], projection=OrthoProjection()):
        """ Initialize the camera """
        self.eye = eye
        self.projection = projection
        self.projection.apply()
        
    @property
    def eye(self):
        """ Return the camera's eye coordinates """
        return self.__eye
        
    @eye.setter
    def eye(self, value):
        """ Set the camera's eye coordinates """
        self.__eye = value
        CppEngine.Camera_SetEye(*[c_float(v) for v in value])