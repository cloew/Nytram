from kao_decorators import proxy_for

@proxy_for("callbacks", ["add", "__contains__", "__len__", "__iter__"])
class BehaviorCallbacks:
    """ Rerpesents a set of callbacks for an Entity's behaviors """
    
    def __init__(self, entityId, callback, engineFn):
        """ Initialize with the  """
        self.callbacks = set()
        self.engineCallback = callback
        engineFn(entityId, self.engineCallback)
        
    def add(self, callback):
        """ Add the callback to the set of callbacks """
        self.callbacks.add(callback)
        
    def __call__(self):
        """ Run the callbacks """
        for callback in self.callbacks:
            callback()