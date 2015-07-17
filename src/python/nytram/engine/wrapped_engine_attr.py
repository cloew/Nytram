from .engine_attr import EngineAttr

class WrappedEngineAttr:
    """ Represents an Engine Attribute that should be wrapped in a class whenever it is assigned """
    
    def __init__(self, cls, callback):
        """ Initialize the Wrapped Engine Attr """
        self.cls = cls
        self.engineAttr = EngineAttr(callback)
        
    def __get__(self, obj, type=None):
        """ Return this attribute """
        return self.engineAttr.__get__(obj, type)
        
    def __set__(self, obj, value):
        """ Wrap the value then use the Engine Attr to set it """
        newValue = self.cls(value, onChange=self.engineAttr.getCallback(obj))
        self.engineAttr.__set__(obj, newValue)