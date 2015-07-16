from kao_decorators import proxy_for

@proxy_for("_vector", ["__iter__", "__len__"])
class Vec3:
    """ Represents a 3-dimension Vector """
    
    def __init__(self, x, y=0, z=0):
        """ Initialize the vector with each coordinate """
        if hasattr(x, '__iter__'):
            self.assign(*x)
        else:
            self.assign(x, y, z)
        
    def assign(self, x=0, y=0, z=0):
        """ Assign all the dimensions in the vector """
        self._vector = [x, y, z]
        
    def setDimension(self, value, index):
        """ Set the given vector index to the value given """
        self._vector[index] = value
        
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