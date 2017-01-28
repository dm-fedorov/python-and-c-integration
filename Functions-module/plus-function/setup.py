from distutils.core import setup, Extension

module1 = Extension( 
	'simple', 
	sources = ['pr.c'] 
)

setup( 
	name = 'simple',
	version = '1.1',
	description = 'Simple baby, yeah, simple', # heap.__doc__
	ext_modules= [module1]
)