[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FMacDumi%2FCandyBar.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FMacDumi%2FCandyBar?ref=badge_shield)
# CandyBar

A Progress Bar inspired by Arch pacman with `ILoveCandy` option enabled.
![CandyBar](https://github.com/MacDumi/CandyBar/blob/dc57d6b6d3d807b85b1b5e8b0eb4d7ab5313cf65/images/candybar.gif)

## Instalation

### Python

#### Manual instalation

Clone the repository, build, and install the package:

```bash
git clone https://github.com/MacDumi/CandyBar.git
cd CandyBar
sudo python.py install
```

#### Install with `pip`

```bash
pip install candy_bar
```

### C++

Don't like `Python`? Use it with `C++`!
Clone the repository and copy the files to the search path of your compiler:

```bash
git clone https://github.com/MacDumi/CandyBar.git
cd CandyBar
cp src/candybar.* <search_path>
```

## Usage

Import the package and create the progress bar object:

###### Python
```python
# Python
from candy_bar import CandyBar

cb = CandyBar(100, "Progress")
```

###### C++
```C++
// C++
#include "candybar.h"

...

CandyBar cb(100, "Progress");
```

#### Parameters

| Parameter | Default        | Description                                               |
| ---       | ---            | ---                                                       |
| total     |   100          | Defines the value corresponding to 100%                   |
| message   | `None`         | Write some text at the beginning of the line              |
| width     | `console size` | Size (in chars) of the bar, by default max console size   |

To update the position of the progress bar use the `update` method:

###### Python
```python
total = 100

for i in range(total + 1):
    # Your code goes here
    cb.update(i)
```

###### C++
```C++
int total = 100;

for (int i = 0; i <= total; i++)
{
    // Your code goes here
    cb.update(i);
}
```
The __total__ value and the __message__ of the progress bar can be changed:

###### Python
```python
cb.set_total(150)
cb.set_message("Another message")
```

###### C++
```C++
cb.set_total(150);
cb.set_message("Another message");
```

#### Like what I do?

Buy me coffee
<img src="https://web.getmonero.org/press-kit/symbols/monero-symbol-480.png" alt="Donate with monero" width="15"/> `85jJPcfLPZRUKm3Re6qHZsKBZskVS2tYMWFoY5sYXUSQJzqzqpuPFepXMtqTKCRfuhYXaiJ3zQVeRPDYJUfepVjnJDpApH5`
