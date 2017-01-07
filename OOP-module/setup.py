from distutils.core import setup, Extension
setup(
	name="heap", 
	version="1.0", 
	ext_modules=[
		Extension(
			"heap", ["heap.c"]
		)
	]
)