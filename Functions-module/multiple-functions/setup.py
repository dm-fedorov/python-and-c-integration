from distutils.core import setup, Extension

module1 = Extension( 
	'sequences', 
	sources = ['sequences.c'] 
)

setup( 
	name = 'sequences',
	version = '1.0',
	description = 'sequences module', 
	ext_modules= [module1]
)