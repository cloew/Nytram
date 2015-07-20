from distutils.core import setup

setup(name='nytram',
      version='0.1',
      description='Nytram Game Engine',
      author='Chris Loew',
      author_email='cloew123@gmail.com',
      #url='http://www.python.org/sigs/distutils-sig/',
      packages=['nytram',
                'nytram.engine',
                'nytram.entity', 'nytram.entity.camera',
                'nytram.ext',
                'nytram.input',
                'nytram.renderers',
                'nytram.shaders',
                'nytram.vector',],
      install_requires=['kao_ext>=0.0.1']
     )