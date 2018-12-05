#include <string>
#include <stdexcept>

class divide_zero: public std::invalid_argument{
    public:
        divide_zero(const std::string &what): std::invalid_argument(what){}

};
