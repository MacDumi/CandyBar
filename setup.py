from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext
from pybind11 import get_cmake_dir

__version__ = "1.2.1"


ext_modules = [
    Pybind11Extension("candy_bar",
        ["src/pysetup.cpp", "src/candybar.cpp"],
        define_macros = [('VERSION_INFO', __version__)],
        ),
]

setup(
    name="candy_bar",
    version=__version__,
    author="Dumitru Duca",
    author_email="me@dumitruduca.com",
    url="https://github.com/MacDumi/CandyBar",
    download_url="https://github.com/MacDumi/CandyBar/archive/refs/tags/1.2.1.tar.gz",
    description="A simple progress bar with the ILoveCandy style",
    keywords = ['Progress Bar', 'ILoveCandy', 'Pacman'],
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    install_requires=['pybind11'],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Build Tools',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
      ],
)
