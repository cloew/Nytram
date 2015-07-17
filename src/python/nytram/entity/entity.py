from .transform import Transform
from ..engine import CppEngine, EngineAttr, UpdateCallback

class Entity(object):
    """ Represents an entity in the game engine """
    nonBehaviorAttrs = ["id", "_updateCallback", "_updateMethods"]
    renderer = EngineAttr("setRenderer")
    
    def __init__(self, renderer=None, transform=None):
        """ Initialize the Entity """
        self.id = CppEngine.Entity_Add()
        
        self._updateMethods = set()
        self._updateCallback = UpdateCallback(self.update)
        CppEngine.Entity_SetUpdateCallback(self.id, self._updateCallback)
        
        self.renderer = renderer
        self.transform = Transform() if transform is None else transform
        
    def setRenderer(self):
        """ Set the Renderer in the C++ Engine """
        if self.renderer is not None:
            CppEngine.Entity_AddRenderer(self.id, self.renderer.id)
            
    def __setattr__(self, name, value):
        """ Set the attr """
        object.__setattr__(self, name, value)
        potentialBehavior = self.getPotentialBehavior(name)
        if potentialBehavior is not None:
            self.setupNewBehavior(potentialBehavior)
                
    def getPotentialBehavior(self, name):
        """ Return the valid behavior or None """
        potentialBehavior = None
        if name not in self.nonBehaviorAttrs:
            potentialBehavior = getattr(self, name)
        return potentialBehavior
        
    def setupNewBehavior(self, behavior):
        """ Setup the behavior """
        behavior.entity = self
        if hasattr(behavior, "update"):
            self._updateMethods.add(behavior.update)
        
    def update(self):
        """ Update the entity and its child behaviors """
        for callback in self._updateMethods:
            callback()