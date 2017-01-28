from distutils.core import setup, Extension

module1 = Extension( 
	'simple', 
	sources = ['sequences.c'] 
)

setup( 
	name = 'sequences',
	version = '1.1',
	description = 'sequences module', 
	ext_modules= [module1]
)