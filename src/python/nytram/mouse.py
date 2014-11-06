from nytram_cpp_wrapper import CPP_LIB, MouseButtonCallback


class Mouse:
    """ Represents the mouse/trackpad that is connected """
    
    def applyCallback(self):
        """ Set the Mouse Button callback to this Mouse """
        self.buttonCallback = self.getCallbackMethod()
        CPP_LIB.Mouse_SetButtonCallback(self.buttonCallback)
        
    def getCallbackMethod(self):
        def callback(button, pressed):
            self.on_mouse_button_pressed(button, pressed)
        return MouseButtonCallback(callback)
    
    def on_mouse_button_pressed(self, button, pressed):
        """ Callback to be called when a mouse button is pressed """
        if pressed:
            print "Button: {0} was pressed".format(button)
        else:
            print "Button: {0} was released".format(button)
            
mouse = Mouse()