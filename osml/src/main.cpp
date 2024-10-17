#include <iostream>
#include "vec.h"

using namespace std;

int main(int argc, char** argv) {
    osml::Vec vec1(3, 3);
    vec1.set(0, 0, 100);
    vec1.set(1, 1, 1);
    vec1.set(2, 2, 1);

    osml::Vec vec2(3, 3);
    vec2.set(0, 0, 2);
    vec2.set(1, 1, 2);
    vec2.set(2, 2, 2);

    //vec1.add(vec2);
    vec1.print();
}
