from kao_decorators import proxy_for

import math

@proxy_for("_vector", ["__iter__", "__len__", "__getitem__"])
class Vec3:
    """ Represents a 3-dimension Vector """
    
    def __init__(self, x, y=0, z=0, onChange=None):
        """ Initialize the vector with each coordinate """
        self.onChange = None
        if hasattr(x, '__iter__'):
            self.assign(*x)
        else:
            self.assign(x, y, z)
        self.onChange = onChange
        
    def assign(self, x=0, y=0, z=0):
        """ Assign all the dimensions in the vector """
        self._vector = [x, y, z]
        if self.onChange is not None:
            self.onChange()
        
    def setDimension(self, value, index):
        """ Set the given vector index to the value given """
        self._vector[index] = value
        if self.onChange is not None:
            self.onChange()
    
    def __add__(self, other):
        """ Add two vectors of equal length """
        if len(other) == len(self):
            return Vec3(*[self[i]+other[i] for i in range(len(self))])
        else:
            return NotImplemented
    
    def __sub__(self, other):
        """ Add two vectors of equal length """
        return self + (-other)
    
    def __neg__(self):
        """ Negate a vector """
        return self*-1
    
    def __mul__(self, other):
        """ Add scalar multiplication to the vector """
        return Vec3(*[d*other for d in self._vector])
    
    def __eq__(self, other):
        """ Compare 2 vectors for equality """
        return list(self) == list(other)
        
    @property
    def unitVector(self):
        """ Return a unit vector in the direction of this vector """
        magnitude = self.magnitude
        return Vec3(self.x/magnitude, self.y/magnitude, self.z/magnitude)
        
    @property
    def magnitude(self):
        """ Return the magnitude of the vector """
        return math.sqrt(self.x**2 + self.y**2 + self.z**2)
        
    @property
    def x(self):
        """ Returns the x component of the vector """
        return self._vector[0]
        
    @x.setter
    def x(self, value):
        """ Set the x component of the vector """
        self.setDimension(value, 0)
        
    @property
    def y(self):
        """ Returns the y component of the vector """
        return self._vector[1]
        
    @y.setter
    def y(self, value):
        """ Set the y component of the vector """
        self.setDimension(value, 1)
        
    @property
    def z(self):
        """ Returns the z component of the vector """
        return self._vector[2]
        
    @z.setter
    def z(self, value):
        """ Set the z component of the vector """
        self.setDimension(value, 2)
        
    def __repr__(self):
        """ Return the string representation """
        return "Vec3({0}, {1}, {2})".format(self.x, self.y, self.z)