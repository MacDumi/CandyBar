[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FMacDumi%2FCandyBar.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FMacDumi%2FCandyBar?ref=badge_shield)
# CandyBar

A Progress Bar inspired by Arch pacman with `ILoveCandy` option enabled.
![CandyBar](https://github.com/MacDumi/CandyBar/blob/eef60efef1e73c8a2a0628ad314226a11b21cd19/images/candybar.gif)

## Instalation

### Python

#### Manual instalation

Clone the repository, build, and install the package:

```bash
git clone https://github.com/MacDumi/CandyBar.git
cd CandyBar
pip install .
```

#### Install from PyPi

```bash
pip install candy_bar
```

### C++

Don't like `Python`? Use it with `C++`!
Clone the repository and either install the library or build against it:

```bash
git clone https://github.com/MacDumi/CandyBar.git
cd CandyBar
make && make install
```

## Usage

Import the package and create the progress bar object:

```python
# Python
from candy_bar import CandyBar

cb = CandyBar(100, "Progress")
```

```C++
// C++
#include "candybar.h"

...

CandyBar cb(100, "Progress");
```

#### Parameters

| Parameter      | Default        | Description                                                 |
| ---            | ---            | ---                                                         |
| total          |   100          | Defines the value corresponding to 100%                     |
| message        | `None`         | Write some text at the beginning of the line                |
| width          | `console size` | Size (in chars) of the bar, by default max console size     |
| left_justified |   True         | Defines the justification of the bar (not the message text) |
| disable        |   False        | When set, the progress bar will be disabled                 |

To update the position of the progress bar use the `update` method:

```python
# Python
total = 100

for i in range(total + 1):
    # Your code goes here
    cb.update(i)
```

```C++
// C++
int total = 100;

for (int i = 0; i <= total; i++)
{
    // Your code goes here
    cb.update(i);
}
```
The progress bar can be disabled:

```python
# Python
def function(verbose):
    ...
    cb.disable(not verbose)
    ...
```

```C++
// C++
void function(bool verbose)
{
    ...
    cb.disable(!verbose);
    ...
}
```

The __total__ value, the __message__, and the __justification__ of the progress bar can be changed:

```python
# Python
cb.set_total(150)
cb.set_message("Another message")
cb.set_left_justified(False)
```

```C++
// C++
cb.set_total(150);
cb.set_message("Another message");
cb.set_left_justified(false);
```

#### Like what I do?

Buy me coffee
<img src="https://web.getmonero.org/press-kit/symbols/monero-symbol-480.png" alt="Donate with monero" width="15"/> `85jJPcfLPZRUKm3Re6qHZsKBZskVS2tYMWFoY5sYXUSQJzqzqpuPFepXMtqTKCRfuhYXaiJ3zQVeRPDYJUfepVjnJDpApH5`
