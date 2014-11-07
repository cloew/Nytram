from nytram_cpp_wrapper import CPP_LIB, GameLoopCallback, GetCallbackMethod
from event.event_queue import EventQueue
from mouse import mouse
from window import Window

class Application:
    """ Represents the current application """
    
    def __init__(self, window=None):
        """ Initialize the application """
        if window is None:
            window = Window()
        self.window = window
        self.eventQueue = EventQueue()
        
    def run(self):
        """ Run the Application """
        self.window.apply()
        self.eventQueue.applyCallback()
        
        self.gameLoopCallback = GetCallbackMethod(self, GameLoopCallback, self.on_tick)
        return CPP_LIB.Nytram_Run(self.gameLoopCallback)
        
    def stop(self):
        """ Stop the application """
        CPP_LIB.Nytram_Stop()
        
    def on_tick(self):
        """ Runs on each frame """
        while self.eventQueue.hasEvents():
            event = self.eventQueue.pop()
            print event