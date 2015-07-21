from ..engine import CppEngine

class Shader:
    """ Represents an OpenGL shader """
    
    def __init__(self, id, filePath, shaderType):
        """ Initialize the Shader """
        self.id = id
        self.filePath = filePath
        self.shaderType = shaderType
        
        CppEngine.Shader_AddShader(id, filePath.encode("utf-8"), shaderType.value)