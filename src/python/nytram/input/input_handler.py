from .input_event import InputEvent
from .keys import Keys
from .mouse_buttons import MouseButtons
from ..engine import CppEngine, KeyboardCallback, MouseButtonCallback

class InputHandler:
    """ Class to handle processing input from the engine """
    
    def __init__(self):
        """ Initialize the Input Handler """
        self.eventToCallbacks = {}
        self.onKey = self.getEngineInputCallback(Keys)
        self.onMouseButton = self.getEngineInputCallback(MouseButtons)
    
    def applyCallbacks(self):
        """ Apply the input callbacks for the mouse and keyboard """
        self.buttonCallback = MouseButtonCallback(self.onMouseButton)
        CppEngine.Mouse_SetButtonCallback(self.buttonCallback)
        
        self.keyboardCallback = KeyboardCallback(self.onKey)
        CppEngine.Keyboard_SetCallback(self.keyboardCallback)
        
    def register(self, input, callback):
        """ Register the given callback for the given Input """
        events = [input]
        if input.__class__ is not InputEvent:
            events = [input.pressed, input.released]
            
        for event in events:
            if event not in self.eventToCallbacks:
                self.eventToCallbacks[event] = []
            self.eventToCallbacks[event].append(callback)
        
    def getEngineInputCallback(self, inputType):
        """ Return a engine input callback """
        def onInput(input, pressed):
            inputCode = inputType.fromValue(input)
            event = inputCode.getEvent(pressed)
            if event in self.eventToCallbacks:
                for callback in self.eventToCallbacks[event]:
                    callback(event)
                
        return onInput