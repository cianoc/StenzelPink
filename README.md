Implements Stefan Stenzel's [pink noise algorithm](https://github.com/Stenzel/newshadeofpink) as a SuperCollider ugen, claimed to be both more efficient and more accurate than the Voss-McCartney algorithm implemented in PinkNoise.

## Installation ##

```shell
mkdir build && cd build
cmake -DSC_PATH=/path/to/sc3source/ ..
make
```

Move it or link it in your extensions directory and you're done