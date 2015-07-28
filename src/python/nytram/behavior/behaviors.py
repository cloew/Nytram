from .behavior_callbacks import BehaviorCallbacks

class Behaviors:
    """ Represents the behaviors associated with some entity/scene """
    nonBehaviorAttrs = ["parent", "parentAttr", "start", "update"]
    behaviorCallbackAttrs = ["start", "update"]
    
    def __init__(self, parent, startEngineFn, updateEngineFn, *, parentAttr):
        """ Initialize the Entity """
        self.parent = parent
        self.parentAttr = parentAttr
        self.start = BehaviorCallbacks(parent.id, startEngineFn)
        self.update = BehaviorCallbacks(parent.id, updateEngineFn)
        
    def __setattr__(self, name, value):
        """ Set the attr """
        object.__setattr__(self, name, value)
        potentialBehavior = self.getPotentialBehavior(name)
        if potentialBehavior is not None:
            self.setupNewBehavior(potentialBehavior)
                
    def getPotentialBehavior(self, name):
        """ Return the valid behavior or None """
        potentialBehavior = None
        if name not in self.nonBehaviorAttrs:
            potentialBehavior = getattr(self, name)
        return potentialBehavior
        
    def setupNewBehavior(self, behavior):
        """ Setup the behavior """
        setattr(behavior, self.parentAttr, self.parent)
        for attrName in self.behaviorCallbackAttrs:
            if hasattr(behavior, attrName):
                getattr(self, attrName).add(getattr(behavior, attrName))
                
    def __repr__(self):
        """ Return the string representation of the behaviors """
        return "{0}".format(self.__dict__)