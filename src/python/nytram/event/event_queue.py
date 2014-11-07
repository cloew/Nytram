from nytram.nytram_cpp_wrapper import CPP_LIB, MouseButtonCallback

from collections import deque

class Event:
    """ Represents a Game Event """
    
    def __init__(self, eventType, pressed):
        """ Initiliaze the Event """
        self.eventType = eventType
        self.pressed = pressed

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
        self.buttonCallback = self.getCallbackMethod()
        CPP_LIB.Mouse_SetButtonCallback(self.buttonCallback)
        
    def getCallbackMethod(self):
        def callback(button, pressed):
            self.on_mouse_button_pressed(button, pressed)
        return MouseButtonCallback(callback)
    
    def on_mouse_button_pressed(self, button, pressed):
        """ Callback to be called when a mouse button is pressed """
        self.addEvent(Event(button, pressed))
        # if pressed:
            # print "Button: {0} was pressed".format(button)
        # else:
            # print "Button: {0} was released".format(button)