from ..engine import NytramEngine, ListToArray
from ctypes import c_float

from kao_decorators import proxy_for

@proxy_for("attrToData", ["__len__", "__iter__", "__getitem__"])
class ShaderVertexData:
    """ Helper class to correlate shader attributes to the list of vertex data """
    
    def __init__(self, rendererId):
        """ Initialize the Shader Vertex Data dictionary """
        self.rendererId = rendererId
        self.attrToData = {}
        
    def update(self, other):
        """ Update with the contents of another dictionary """
        for key in other:
            self[key] = other[key]
        
    def __setitem__(self, key, value):
        """ Return the requested attribute """
        self.attrToData[key] = value
        NytramEngine.Renderer_AddVertexBuffer(self.rendererId, key, *ListToArray(value, c_float))