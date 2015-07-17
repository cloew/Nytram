from nytram.engine import CppEngine, EngineAttr
from ctypes import c_float

class OrthoProjection:
    """ Represents an Orthographic Projection """
    width = EngineAttr("setProjection")
    height = EngineAttr("setProjection")
    nearClip = EngineAttr("setProjection")
    farClip = EngineAttr("setProjection")
    
    def __init__(self, width=2, height=2, nearClip=1, farClip=100):
        """ Initialize the projection """
        self.width = width
        self.height = height
        self.nearClip = nearClip
        self.farClip = farClip
        
    def apply(self, camera):
        """ Apply the projection """
        self.camera = camera
        self.setProjection()
        
    def setProjection(self):
        """ Set the active projection in the C++ Engine """
        if hasattr(self, "camera") and None not in [self.width, self.height, self.nearClip, self.farClip]:
            CppEngine.Camera_SetProjection(c_float(self.width), c_float(self.height), c_float(self.nearClip), c_float(self.farClip))