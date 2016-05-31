StenzelPink : UGen {
    *ar { |mul = 1, add = 0|
        ^this.multiNew('audio').madd(mul, add);
    }

    *kr { |mul = 1, add = 0|
        ^this.multiNew('control').madd(mul, add);
    }
}