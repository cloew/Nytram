from .engine import NytramEngine
from .input import InputHandler
from .mouse import mouse
from .window import Window

from smart_defaults import smart_defaults, EvenIfNone

class Application:
    """ Represents the current application """
    
    @smart_defaults
    def __init__(self, inputHandler=EvenIfNone(InputHandler()), window=EvenIfNone(Window())):
        """ Initialize the application """
        self.inputHandler = inputHandler
        self.window = window
        
    def run(self):
        """ Run the Application """
        self.window.apply()
        self.inputHandler.applyCallbacks()
        return NytramEngine.Nytram_Run()
        
    def stop(self):
        """ Stop the application """
        NytramEngine.Nytram_Stop()