#include <string>
#include <stdexcept>

class not_accessible: public std::logic_error{
    public:
        not_accessible(const std::string &what): std::logic_error(what){}
};