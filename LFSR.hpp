#ifndef LFSR_H
#define LFSR_H

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class LFSR {
    public:
        LFSR(string SEED, int T);

        bool XOR(string a, string b);

        int step(void);

        int generate(int k);

        friend ostream& operator<< (ostream &out, const LFSR &lsfr);

        int getLength();

        string getSeed();

        void setSeed(string newSeed);

    private:
        string seed;
        int seedLength;
        int stepval;
        int genval;
        int t;

};

#endif