from .keys import Keys
from .mouse_buttons import MouseButtons

from nytram.enum import wrapped_enum

@wrapped_enum(Keys, MouseButtons)
class AllInput:
    """ Represents a composite Enum for all input codes """