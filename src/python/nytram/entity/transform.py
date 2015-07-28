from .rotation import Rotation

from nytram.engine import NytramEngine, VectorToArguments, EngineAttr, WrappedEngineAttr
from nytram.vector import Vec3
from ctypes import c_float

from smart_defaults import smart_defaults, PerCall

class Transform:
    """ Represents an entity's transformation matrix """
    entity = EngineAttr('apply')
    position = WrappedEngineAttr(Vec3, 'setPosition')
    scale = WrappedEngineAttr(Vec3, 'setScale')
    rotation = EngineAttr('setRotation')
    
    @smart_defaults
    def __init__(self, position=Vec3(0,0,0), scale=Vec3(1,1,1), rotation=PerCall(Rotation())):
        """ Initialize the Transform """
        self.position = position
        self.scale = scale
        self.rotation = rotation
        
    def apply(self):
        """ Apply the transform """
        self.setPosition()
        self.setScale()
        self.setRotation()
        
    def setPosition(self):
        """ Set the position for this entity in the C++ engine """
        if self.entity is not None:
            NytramEngine.Entity_Translate(self.entity.id, *VectorToArguments(self.position, c_float))
        
    def setScale(self):
        """ Set the scale for this entity in the C++ engine """
        if self.entity is not None:
            NytramEngine.Entity_Scale(self.entity.id, *VectorToArguments(self.scale, c_float))
        
    def setRotation(self):
        """ Set the rotation for this entity in the C++ engine """
        if self.entity is not None:
            self.rotation.apply(self.entity)