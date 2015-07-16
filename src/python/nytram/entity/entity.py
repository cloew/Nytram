from ..engine import CppEngine, ListToArray

class Entity:
    """ Represents an entity in the game engine """
    
    def __init__(self, renderer=None):
        """ Initialize the Entity """
        self.id = CppEngine.Entity_Add()
        self.renderer = renderer
        
    @property
    def renderer(self):
        """ Return the renderer """
        return self.__renderer
        
    @renderer.setter
    def renderer(self, value):
        """ Set the renderer """
        self.__renderer = value
        if value is not None:
            CppEngine.Entity_AddRenderer(self.id, self.renderer.id)