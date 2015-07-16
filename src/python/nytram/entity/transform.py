from nytram.engine import CppEngine, VectorToArguments
from nytram.vector import Vec3
from ctypes import c_float

class Transform:
    """ Represents an entity's transformation matrix """
    
    def __init__(self, position=Vec3(0,0,0)):
        """ Initialize the Transform """
        self.position = Vec3(position)
        
    @property
    def position(self):
        """ Return the position vector """
        return self.__position
        
    @position.setter
    def position(self, value):
        """ Set the position """
        self.__position = Vec3(value)
        if hasattr(self, "entity"):
            CppEngine.Entity_Translate(self.entity.id, *VectorToArguments(self.__position, c_float))