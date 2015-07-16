from weakref import WeakKeyDictionary

class EngineAttr:
    """ Represents an attribute that is tied to the engine """
    
    def __init__(self, callback):
        """ Initialize the Engine Attr """
        self.values = WeakKeyDictionary()
        self.callback = callback
        
    def __get__(self, obj, type=None):
        """ Return this attribute """
        return self.values[obj] if type is not None else self
        
    def __set__(self, obj, value):
        """ Set this attribute """
        self.values[obj] = value
        getattr(obj, self.callback)(value)