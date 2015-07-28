from .transform import Transform
from ..behavior import Behaviors
from ..engine import CppEngine

class Entity(object):
    """ Represents an entity in the game engine """
    nonBehaviorAttrs = ["id", "behaviors", "app"]
    
    def __init__(self, app, renderer=None, transform=None):
        """ Initialize the Entity """
        self.id = CppEngine.Entity_Add()
        self.app = app
        self.behaviors = Behaviors(self, CppEngine.Entity_SetStartCallback, CppEngine.Entity_SetUpdateCallback, parentAttr="entity")
        
        self.renderer = renderer
        self.transform = Transform() if transform is None else transform
            
    def __getattr__(self, name):
        """ Return the requested attr """
        if name in self.nonBehaviorAttrs:
            return object.__getattr__(self, name)
        else:
            return getattr(self.behaviors, name)
            
    def __setattr__(self, name, value):
        """ Set the attr """
        if name in self.nonBehaviorAttrs:
            object.__setattr__(self, name, value)
        else:
            setattr(self.behaviors, name, value)