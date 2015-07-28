from ..behavior import Behaviors
from ..engine import NytramEngine

class Scene(object):
    """ Represents a scene to render in the game engine """
    nonBehaviorAttrs = ["behaviors", "app"]
    
    def __init__(self, app):
        """ Initialize the scene with the app """
        self.app = app
        self.behaviors = Behaviors(self, parentAttr="scene")
        NytramEngine.Scene_SetStartCallback(self.behaviors.start.engineCallback)
        NytramEngine.Scene_SetUpdateCallback(self.behaviors.update.engineCallback)
            
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