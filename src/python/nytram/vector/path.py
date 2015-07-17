from nytram.engine import Time
from nytram.vector import Vec3

class Path:
    """ Represents a path between points """
    
    def __init__(self, transform, destination):
        """ Initialize the path """
        self.transform = transform
        self.destination = Vec3(destination)
        self.direction = (destination - self.transform.position).unitVector
        
    def follow(self, speed):
        """ Return a coroutine that will follow this path """
        while self.transform.position != self.destination:
            distance = self.direction*(speed*Time.sinceLastFrame()/1000.0)
            difference = self.destination - self.transform.position
            
            if distance.magnitude < difference.magnitude:
                self.transform.position += distance
            else:
                self.transform.position.assign(self.destination.x, self.destination.y, self.destination.z)
            yield