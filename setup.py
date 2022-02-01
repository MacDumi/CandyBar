from setuptools import setup, Extension
from os import path

try:
    from Cython.Build import cythonize
except:
    import sys, subprocess
    subprocess.check_call([sys.executable, "-m", "pip", "install", "cython"])
finally:
    from Cython.Build import cythonize

__version__ = "1.3.4"


this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name="candy_bar",
    version=__version__,
    author="Dumitru Duca",
    author_email="me@dumitruduca.com",
    url="https://github.com/MacDumi/CandyBar",
    download_url="https://github.com/MacDumi/CandyBar/archive/refs/tags/1.3.4.tar.gz",
    description="A simple progress bar with the ILoveCandy style",
    long_description=long_description,
    long_description_content_type='text/markdown',
    keywords = ['Progress Bar', 'ILoveCandy', 'Pacman'],
    ext_modules = cythonize(Extension("candy_bar", ["candy_bar.pyx"],
                            include_dirs=["include/"])),
    zip_safe=False,
    setup_requires=['setuptools>=18.0', 'cython'],
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'Topic :: Software Development :: Build Tools',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.4',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
      ],
)
