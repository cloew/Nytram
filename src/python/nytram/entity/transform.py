from nytram.engine import CppEngine, VectorToArguments, EngineAttr
from nytram.vector import Vec3
from ctypes import c_float

class Transform:
    """ Represents an entity's transformation matrix """
    position = EngineAttr('setPosition')
    scale = EngineAttr('setScale')
    
    def __init__(self, position=Vec3(0,0,0), scale=Vec3(1,1,1)):
        """ Initialize the Transform """
        self.position = Vec3(position)
        self.scale = scale
        
    def setPosition(self, value):
        """ Set the position for this entity in the C++ engine """
        if hasattr(self, "entity"):
            CppEngine.Entity_Translate(self.entity.id, *VectorToArguments(self.position, c_float))
        
    def setScale(self, value):
        """ Set the scale for this entity in the C++ engine """
        if hasattr(self, "entity"):
            CppEngine.Entity_Scale(self.entity.id, *VectorToArguments(self.scale, c_float))