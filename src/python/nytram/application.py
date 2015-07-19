from .engine import CppEngine
from .event.event_queue import EventQueue
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
        return CppEngine.Nytram_Run()
        
    def stop(self):
        """ Stop the application """
        CppEngine.Nytram_Stop()