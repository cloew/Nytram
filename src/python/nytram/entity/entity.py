from .transform import Transform
from ..engine import CppEngine, EngineAttr

class Entity(object):
    """ Represents an entity in the game engine """
    renderer = EngineAttr("setRenderer")
    
    def __init__(self, renderer=None, transform=None):
        """ Initialize the Entity """
        self.id = CppEngine.Entity_Add()
        self.renderer = renderer
        self.transform = Transform() if transform is None else transform
        
    def setRenderer(self):
        """ Set the Renderer in the C++ Engine """
        if self.renderer is not None:
            CppEngine.Entity_AddRenderer(self.id, self.renderer.id)
            
    def __setattr__(self, name, value):
        """ Set the attr """
        object.__setattr__(self, name, value)
        if name is not "id":
            potentialBehavior = getattr(self, name)
            if potentialBehavior is not None:
                potentialBehavior.entity = self