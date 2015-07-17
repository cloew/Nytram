
class Time:
    """ Represents aspects of time in the C++ Engine """
    
    def __init__(self, engine):
        """ Initialize the Time """
        self.engine = engine
        
    def sinceLastFrame(self):
        """ Return the time since the last frame in milliseconds """
        return self.engine.Time_SinceLastFrame()