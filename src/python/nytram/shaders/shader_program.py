from ..nytram_cpp_wrapper import CPP_LIB

from ctypes import c_uint

class ShaderProgram:
    """ Represents a Shader Program """
    
    def __init__(self, id, shaders):
        """ Initialize the shader program """
        self.id = id
        self.shaders = shaders
        
        shaderIds = [shader.id for shader in shaders]
        CPP_LIB.Shader_AddProgram(id, (c_uint*len(shaderIds))(*shaderIds), len(shaderIds))