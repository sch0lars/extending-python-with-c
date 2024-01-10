from setuptools import setup, Extension

setup(
    name='geometry',
    version='1.0',
    description='A sample geometry module for learning C++ extensions in Python',
    ext_modules=[
        Extension(
            'geometry',
            sources=['geometrymodule.cpp'],
            py_limited_api=True
        )
    ]
)
