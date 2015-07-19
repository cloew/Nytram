
class InputEvent:
    """ Represents an Input Event received from the C++ Engine """
    PRESSED_STRING = {True:"pressed", False:"released"}
    
    def __init__(self, eventType, pressed, enum):
        """ Initiliaze the Event """
        self.eventType = eventType
        self.pressed = pressed
        self.enum = enum
        
    def __repr__(self):
        """ Return the string representation of the event """
        return "{0} was {1}".format(self.enum.tostring(self.eventType), self.PRESSED_STRING[self.pressed])