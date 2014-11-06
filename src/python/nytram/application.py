from nytram_cpp_wrapper import CPP_LIB
from window import Window

class Application:
    """ Represents the current application """
    
    def __init__(self, window=None):
        """ Initialize the application """
        if window is None:
            window = Window()
        self.window = window
        
    def run(self):
        """ Run the Application """
        self.window.apply()
        return CPP_LIB.Nytram_Run()
        
    def stop(self):
        """ Stop the application """
        CPP_LIB.Nytram_Stop()