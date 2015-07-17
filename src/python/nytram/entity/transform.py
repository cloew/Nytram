from .rotation import Rotation

from nytram.engine import CppEngine, VectorToArguments, EngineAttr
from nytram.vector import Vec3
from ctypes import c_float

from smart_defaults import smart_defaults, PerCall

class Transform:
    """ Represents an entity's transformation matrix """
    position = EngineAttr('setPosition')
    scale = EngineAttr('setScale')
    rotation = EngineAttr('setRotation')
    
    @smart_defaults
    def __init__(self, position=Vec3(0,0,0), scale=Vec3(1,1,1), rotation=PerCall(Rotation())):
        """ Initialize the Transform """
        self.position = Vec3(position)
        self.scale = Vec3(scale)
        self.rotation = rotation
        
    def setPosition(self):
        """ Set the position for this entity in the C++ engine """
        if hasattr(self, "entity"):
            CppEngine.Entity_Translate(self.entity.id, *VectorToArguments(self.position, c_float))
        
    def setScale(self):
        """ Set the scale for this entity in the C++ engine """
        if hasattr(self, "entity"):
            CppEngine.Entity_Scale(self.entity.id, *VectorToArguments(self.scale, c_float))
        
    def setRotation(self):
        """ Set the rotation for this entity in the C++ engine """
        if hasattr(self, "entity"):
            self.rotation.apply(self.entity)