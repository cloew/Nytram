
class EngineCallback:
    """ Represents a callback to be registered with the C++ Engine """
    
    def __init__(self, cFunctionPrototype):
        """ Initialize with C Function Prototype to mimic """
        self.cFunctionPrototype = cFunctionPrototype
        
    def __call__(self, callback):
        """ Return the C Function """
        def placeholder(*args):
            callback(*args)
        return self.cFunctionPrototype(placeholder)