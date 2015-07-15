from ..engine import CppEngine, ListToArray

from ctypes import c_uint

class ShaderProgram:
    """ Represents a Shader Program """
    
    def __init__(self, id, shaders):
        """ Initialize the shader program """
        self.id = id
        self.shaders = shaders
        
        shaderIds = [shader.id for shader in shaders]
        CppEngine.Shader_AddProgram(id, *ListToArray(shaderIds, c_uint))