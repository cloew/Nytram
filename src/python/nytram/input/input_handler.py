from .input_event import InputEvent
from ..event.events import Keys, MouseButtons
from ..engine import CppEngine, KeyboardCallback, MouseButtonCallback

class InputHandler:
    """ Class to handle processing input from the engine """
    
    def __init__(self):
        """ Initialize the Input Handler """
        self.inputToCallbacks = {}
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
        if input not in self.inputToCallbacks:
            self.inputToCallbacks[input] = []
        self.inputToCallbacks[input].append(callback)
        
    def getEngineInputCallback(self, inputType):
        """ Return a engine input callback """
        def onInput(input, pressed):
            if input in self.inputToCallbacks:
                event = InputEvent(input, pressed, inputType)
                for callback in self.inputToCallbacks[input]:
                    callback(event)
                
        return onInput