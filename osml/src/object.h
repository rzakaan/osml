#include <string>

class Object {
public:
    std::string toString();
    long hashCode();
    virtual Object* clone() = 0;
};
