from nytram_cpp_wrapper import CPP_LIB

class Window:
    """ Represents the application window """
    
    def __init__(self, width=640, height=480):
        """ Initialize the window with the dimensions """
        self.width = width
        self.height = height
        
    def apply(self):
        """ Apply the Window parameters to the actual window """
        CPP_LIB.Window_SetSize(self.width, self.height)