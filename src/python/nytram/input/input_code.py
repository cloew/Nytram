from .input_event import InputEvent

class InputCode:
    """ Represents an InputCode """
    
    def __init__(self, name, code):
        """ Initialize with the code """
        self.name = name
        self.code = code
        
    def getEvent(self, pressed):
        """ Return the proper event """
        return self.pressed if pressed else self.released
        
    @property
    def pressed(self):
        """ Return a pressed event for this InputCode """
        return self.buildEvent(pressed=True)
        
    @property
    def released(self):
        """ Return a released event for this InputCode """
        return self.buildEvent(pressed=False)
        
    def buildEvent(self, pressed=True):
        """ Return an event with the proper pressed flag set """
        return InputEvent(self, pressed=pressed)
        
    def __repr__(self):
        """ Return the string representation of this code """
        return self.name