from weakref import WeakKeyDictionary

class EngineAttr:
    """ Represents an attribute that is tied to the engine """
    
    def __init__(self, callback):
        """ Initialize the Engine Attr """
        self.values = WeakKeyDictionary()
        self.callback = callback
        
    def __get__(self, obj, type=None):
        """ Return this attribute """
        result = None
        if type is not None:
            if obj in self.values:
                result = self.values[obj]
        else:
            result = self
        return result
        
    def __set__(self, obj, value):
        """ Set this attribute """
        self.values[obj] = value
        self.getCallback(obj)()
        
    def getCallback(self, obj):
        """ Return the callback function """
        return getattr(obj, self.callback)