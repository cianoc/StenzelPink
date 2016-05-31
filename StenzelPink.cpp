/*

    StenzelPink SuperCollider UGen
    Copyright (C) 2016 Nathan Ho.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include "SC_PlugIn.hpp"
#include "pink.h"

static InterfaceTable *ft;

struct StenzelPink : public SCUnit {
public:
    StenzelPink() {
        if (mBufLength & 15 == 0) {
            set_calc_function<StenzelPink, &StenzelPink::next16>();
        } else {
            mBuf = (float*)RTAlloc(mWorld, 16 * sizeof(float));
            mPhase = 0;
            set_calc_function<StenzelPink, &StenzelPink::next>();
        }
    }

    ~StenzelPink() {
        RTFree(mWorld, mBuf);
    }

private:
    pink mPink;
    float* mBuf;
    int mPhase;

    // If the buffer size is a multiple of 16, we can just split the buffer size into 16-sample chunks
    void next16(int inNumSamples) {
        for (int i = 0; i < inNumSamples; i += 16) {
            mPink.generate16(out(0) + i);
        }
    }

    // Otherwise, gotta write to a danged size-16 buffer, track phase and all that
    void next(int inNumSamples) {
        for (int i = 0; i < inNumSamples; i += 1) {
            if (mPhase == 0) {
                mPink.generate16(mBuf);
            }
            out(0)[i] = mBuf[mPhase];
            mPhase = (mPhase + 1) & 15;
        }
    }
};

PluginLoad(StenzelPinkUGens) {
    ft = inTable;
    registerUnit<StenzelPink>(ft, "StenzelPink");
}