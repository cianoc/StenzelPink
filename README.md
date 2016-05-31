Implements Stefan Stenzel's [pink noise algorithm](https://github.com/Stenzel/newshadeofpink) as a SuperCollider ugen, claimed to be both more efficient and more accurate than the Voss-McCartney algorithm implemented in PinkNoise.

## Installation ##

```shell
sc3-plugins/$ mkdir build && cd build
sc3-plugins/build/$ cmake -DSC_PATH=/path/to/sc3source/ ..
sc3-plugins/build/$ make
```

Move it or link it in your extensions directory and you're done