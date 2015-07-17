from nytram.engine import CppEngine, EngineAttr
from ctypes import c_float

aroundZ = EngineAttr("setRotationInXYPlane")
aroundY = EngineAttr("setRotationInXZPlane")
aroundX = EngineAttr("setRotationInYZPlane")

class Rotation:
    """ Represents an entity's rotation """
    aroundZ = aroundZ
    inXY = aroundZ
    aroundY = aroundY
    inXZ = aroundY
    aroundX = aroundX
    inYZ = aroundX
    
    def __init__(self, aroundX=0, aroundY=0, aroundZ=0, inXY=0, inXZ=0, inYZ=0):
        """ Initialize the Rotation """
        self.inXY = aroundZ if aroundZ != 0 else inXY
        self.inXZ = aroundY if aroundY != 0 else inXZ
        self.inYZ = aroundX if aroundX != 0 else inYZ
        
    def apply(self, entity):
        """ Apply the rotation """
        self.entity = entity
        self.setRotationInXYPlane()
        self.setRotationInXZPlane()
        self.setRotationInYZPlane()
        
    def setRotationInXYPlane(self):
        """ Set the rotation in the XY plane """
        if hasattr(self, "entity"):
            CppEngine.Entity_RotateInXY(self.entity.id, c_float(self.inXY))
            
    def setRotationInXZPlane(self):
        """ Set the rotation in the XZ plane """
        if hasattr(self, "entity"):
            CppEngine.Entity_RotateInXZ(self.entity.id, c_float(self.inXZ))
            
    def setRotationInYZPlane(self):
        """ Set the rotation in the YZ plane """
        if hasattr(self, "entity"):
            CppEngine.Entity_RotateInYZ(self.entity.id, c_float(self.inYZ))