from .all_input import AllInput

class InputEvent:
    """ Represents an Input Event received from the C++ Engine """
    PRESSED_STRING = {True:"pressed", False:"released"}
    
    def __init__(self, eventType, pressed=True, enum=AllInput):
        """ Initiliaze the Event """
        self.eventType = eventType
        self.pressed = pressed
        self.enum = enum
        
    def __eq__(self, other):
        """ Compare if Input Events are equal """
        return self.eventType == other.eventType and self.pressed == other.pressed
        
    def __hash__(self):
        return hash((self.eventType, self.pressed))
        
    def __repr__(self):
        """ Return the string representation of the event """
        return "{0} was {1}".format(self.enum.tostring(self.eventType), self.PRESSED_STRING[self.pressed])