from .shader_vertex_data import ShaderVertexData
from ..engine import CppEngine, ListToArray
from ctypes import c_uint

class EntityRenderer:
    """ Represents a method for rendering an entity using supplied vertex lists """
    
    def __init__(self, shaderProgram, elements=[], vertexData={}):
        """ Initialize the Entity Renderer """
        self.id = CppEngine.Renderer_Add(shaderProgram.id)
        self.elements = elements
        self.__vertexData = ShaderVertexData(self.id)
        self.vertexData = vertexData
        
    @property
    def elements(self):
        """ Return the element indices to use when rendering the entity """
        return self.__elements
        
    @elements.setter
    def elements(self, value):
        """ Set the elements """
        self.__elements = value
        if len(value) > 0:
            CppEngine.Renderer_AddElementBuffer(self.id, *ListToArray(self.__elements, c_uint))
        
    @property
    def vertexData(self):
        """ Return the vertex data """
        return self.__vertexData
        
    @vertexData.setter
    def vertexData(self, value):
        """ Set the vertex data """
        self.__vertexData.update(value)