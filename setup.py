from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
from pybind11 import get_cmake_dir

__version__ = "1.0"


ext_modules = [
    Pybind11Extension("candybar",
        ["src/pysetup.cpp", "src/candybar.cpp"],
        define_macros = [('VERSION_INFO', __version__)],
        ),
]

setup(
    name="candybar",
    version=__version__,
    author="Dumitru Duca",
    author_email="me@dumitruduca.com",
    url="https://github.com/MacDumi/CandyBar",
    description="A simple progress bar with the ILoveCandy style",
    long_description="",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)
