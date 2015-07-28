from .transform import Transform
from ..behavior import Behaviors
from ..engine import NytramEngine

class Entity(object):
    """ Represents an entity in the game engine """
    nonBehaviorAttrs = ["id", "behaviors", "scene"]
    
    def __init__(self, scene, renderer=None, transform=None):
        """ Initialize the Entity """
        self.id = NytramEngine.Entity_Add()
        self.scene = scene
        self.behaviors = Behaviors(self, parentAttr="entity")
        NytramEngine.Entity_SetStartCallback(self.id, self.behaviors.start.engineCallback)
        NytramEngine.Entity_SetUpdateCallback(self.id, self.behaviors.update.engineCallback)
        
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