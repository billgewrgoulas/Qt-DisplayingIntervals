#include "dummyinterval.h"
#include "createIntervals.h"
#include <iostream>
// for random
#include <cstdlib>
#include <ctime>
#include <cmath>

createIntervals::createIntervals(int size){
    this->size = size;
}

void createIntervals::getIntervals(dummyInterval *intervalArray){
    int rand = 0;

    std::srand((unsigned int) std::time(NULL));

    int counter = 0;
    int base = 0;
    double overlap_ratio = 0.1; // for high overlap make this close to 0.

    for (int i = 0; i < this->size; i ++) {

        base = this->size*counter*overlap_ratio;
        rand = std::rand() % (this->size + 1);
        int r = rand + base;
        rand = std::rand() % (this->size + 1);
        int l = rand + base;

        // swap values to always have (l < r) for each interval
        if (l > r) {
            int temp = l;
            l = r;
            r = temp;
        }

        intervalArray[i] = dummyInterval(l, r);
        intervalArray[i].setNameLabel("i"+std::to_string(r));
        counter ++;
    }

    for (int i = 0; i < this->size; i ++) {

        std::cout << intervalArray[i].nameLabel() << " ["
                  << std::to_string(intervalArray[i].left()) << ", "
                  << std::to_string(intervalArray[i].right()) << "]"
                  << std::endl;
    }

}



