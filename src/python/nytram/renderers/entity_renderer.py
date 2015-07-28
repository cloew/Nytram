from .shader_vertex_data import ShaderVertexData
from ..engine import NytramEngine, ListToArray, EngineAttr
from ctypes import c_uint

class EntityRenderer:
    """ Represents a method for rendering an entity using supplied vertex lists """
    entity = EngineAttr("apply")
    
    def __init__(self, shaderProgram, elements=[], vertexData={}):
        """ Initialize the Entity Renderer """
        self.id = NytramEngine.Renderer_Add(shaderProgram.id)
        self.elements = elements
        self.__vertexData = ShaderVertexData(self.id)
        self.vertexData = vertexData
        
    def apply(self):
        """ Apply the Renderer in the C++ Engine """
        if self.entity is not None:
            NytramEngine.Entity_AddRenderer(self.entity.id, self.id)
        
    @property
    def elements(self):
        """ Return the element indices to use when rendering the entity """
        return self.__elements
        
    @elements.setter
    def elements(self, value):
        """ Set the elements """
        self.__elements = value
        if len(value) > 0:
            NytramEngine.Renderer_AddElementBuffer(self.id, *ListToArray(self.__elements, c_uint))
        
    @property
    def vertexData(self):
        """ Return the vertex data """
        return self.__vertexData
        
    @vertexData.setter
    def vertexData(self, value):
        """ Set the vertex data """
        self.__vertexData.update(value)