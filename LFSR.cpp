#include "LFSR.hpp"

using namespace std;

LFSR::LFSR(string SEED, int T) {

    this->seed = SEED;
    this->seedLength = this->seed.length();
    this->t = T+1;
    this->stepval = 1;
    this->genval = 0;
}

bool LFSR::XOR(string a, string b) {

    /*  two boolean expression that will 
        map to a and b respectively*/
    bool ba = false;
    bool bb = false;

    if( a == "1")
        ba = true;

    if( b == "1" )
        bb = true;

    if( !ba != !bb )
        return true;
    else
        return false;
    
}

int LFSR::step(void) {

    // a will hold the first character of seed
    string a;
    // b will hold the character of seed a is being compared with - t index
    string b;

    a = this->seed[0];
    b = this->seed[this->seedLength-this->t];
    if ( this->XOR(a, b) )
    {
        //erase should delete the first character from seed or seed[0]
        this->seed.erase(0,1);
        //adds the return value for XOR to seed at the end of seed
        // return value in this case is 1 because XOR is true
        this->seed.append("1");
        this->stepval = 1;
        return 1;
    }
    else
    {
        //erase should delete the first character from seed or seed[0]
        this->seed.erase(0,1);
        // adds the return value for XOR to seed at the end of seed 
        // return value in this case is 0 because XOR is false
        this->seed.append("0");
        this->stepval = 0;
        
        return 0;
    }

    return 0;
}

int LFSR::generate(int k) {

    int i;
    this->genval = 0;
    
    for( i = 0; i < k; i++)
    {
        this->step();
        this->genval *= 2; 
        this->genval += this->stepval;
    }

    return this->genval;
}

ostream& operator<< (ostream &out, const LFSR &lfsr) {

    out << lfsr.seed << endl;

    return out;
}


int LFSR::getLength() { return this->seedLength;}

string LFSR::getSeed() { return this->seed; }

void LFSR::setSeed(string newSeed) { this->seed = newSeed; }
/*
int main()
{
    LFSR test("01101000010", 8);
    int i;

    cout << test;
    for( i = 0; i < 10; i++) {
    test.step();
    cout << test; } 

    cout << endl;

    for( i = 0; i < 10; i++) 
    {
        test.generate(5);
        cout << test;
    }

    return 0;
} */