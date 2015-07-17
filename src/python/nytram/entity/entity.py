from ..engine import CppEngine, EngineAttr

class Entity:
    """ Represents an entity in the game engine """
    renderer = EngineAttr("setRenderer")
    
    def __init__(self, renderer=None):
        """ Initialize the Entity """
        self.id = CppEngine.Entity_Add()
        self.renderer = renderer
        
    def setRenderer(self):
        """ Set the Renderer in the C++ Engine """
        if self.renderer is not None:
            CppEngine.Entity_AddRenderer(self.id, self.renderer.id)