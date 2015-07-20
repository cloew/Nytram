
class InputEvent:
    """ Represents an Input Event received from the C++ Engine """
    PRESSED_STRING = {True:"pressed", False:"released"}
    
    def __init__(self, inputCode, pressed=True):
        """ Initiliaze the Event """
        self.inputCode = inputCode
        self.pressed = pressed
        
    def __eq__(self, other):
        """ Compare if Input Events are equal """
        return self.inputCode == other.inputCode and self.pressed == other.pressed
        
    def __hash__(self):
        return hash((self.inputCode, self.pressed))
        
    def __repr__(self):
        """ Return the string representation of the event """
        return "{0} was {1}".format(self.inputCode, self.PRESSED_STRING[self.pressed])