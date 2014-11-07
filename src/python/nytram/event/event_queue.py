from nytram.nytram_cpp_wrapper import CPP_LIB, MouseButtonCallback, GetCallbackMethod

from collections import deque

class Event:
    """ Represents a Game Event """
    
    def __init__(self, eventType, pressed):
        """ Initiliaze the Event """
        self.eventType = eventType
        self.pressed = pressed
        
    def __repr__(self):
        """ Return the string representation of the event """
        if self.pressed:
            return "Button: {0} was pressed".format(self.eventType)
        else:
            return "Button: {0} was released".format(self.eventType)

class EventQueue:
    """ Represents the queu of events to process in the game """
    
    def __init__(self):
        """ Initialize the event queue """
        self.eventQueue = deque()
        
    def addEvent(self, event):
        """ Add the given event to the queue """
        self.eventQueue.append(event)
    
    def applyCallback(self):
        """ Set the Mouse Button callback """
        self.buttonCallback = GetCallbackMethod(self, MouseButtonCallback, self.on_mouse_button_pressed)
        CPP_LIB.Mouse_SetButtonCallback(self.buttonCallback)
    
    def on_mouse_button_pressed(self, button, pressed):
        """ Callback to be called when a mouse button is pressed """
        self.addEvent(Event(button, pressed))
        # if pressed:
            # print "Button: {0} was pressed".format(button)
        # else:
            # print "Button: {0} was released".format(button)
            
    def pop(self):
        """ Return and pop the first element of the queue """
        return self.eventQueue.popleft()
            
    def hasEvents(self):
        """ Return the length of the event queue """
        return len(self.eventQueue) > 0