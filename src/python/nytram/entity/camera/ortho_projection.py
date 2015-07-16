from nytram.engine import CppEngine
from ctypes import c_float

class OrthoProjection:
    """ Represents an Orthographic Projection """
    
    def __init__(self, width=2, height=2, nearClip=1, farClip=100):
        """ Initialize the projection """
        self.width = width
        self.height = height
        self.nearClip = nearClip
        self.farClip = farClip
        
    def apply(self):
        """ Apply the projection """
        CppEngine.Camera_SetProjection(c_float(self.width), c_float(self.height), c_float(self.nearClip), c_float(self.farClip))