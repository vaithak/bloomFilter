#include <iostream>
#include "src/BloomFilter.h" 

using namespace std;
 
int main()
{
    BloomFilter bf(1024 * 1024, 5);
    
    string check = "Hello World";
    bf.add((uint8_t*)check.c_str(), check.size());

    check = "Vaibhav";
    bf.add((uint8_t*)check.c_str(), check.size());

	check = "Thakkar";
    bf.add((uint8_t*)check.c_str(), check.size());

    check = "Github";
    bf.add((uint8_t*)check.c_str(), check.size());

    check = "Google";
    bf.add((uint8_t*)check.c_str(), check.size());

    check = "Facebook";
    bf.add((uint8_t*)check.c_str(), check.size());    

    check = "Google";
    bool status  = bf.find((uint8_t*)check.c_str(), check.size());
    cout<<"Is "<<check<<" Possibly Contained = "<<status<<endl;

    check = "Yahoo";
    status  = bf.find((uint8_t*)check.c_str(), check.size());
    cout<<"Is "<<check<<" Possibly Contained = "<<status<<endl;
}


/*
-------------OUTPUT------------

Is GooglePossibly Contained = 1
Is YahooPossibly Contained = 0

-------------------------------
*/