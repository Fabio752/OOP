#include <string>
#include <stdexcept>

class not_available: public std::logic_error{
    public:
        not_available(const std::string &what): std::logic_error(what){}
};