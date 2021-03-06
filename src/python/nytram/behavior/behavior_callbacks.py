from ..engine import EntityCallback
from kao_decorators import proxy_for

@proxy_for("callbacks", ["add", "__contains__", "__len__", "__iter__"])
class BehaviorCallbacks:
    """ Rerpesents a set of callbacks for an Entity's behaviors """
    
    def __init__(self):
        """ Initialize with the entity Id and Engine Fn to call """
        self.callbacks = set()
        self.engineCallback = EntityCallback(self.__call__)
        
    def __call__(self):
        """ Run the callbacks """
        for callback in self.callbacks:
            callback()