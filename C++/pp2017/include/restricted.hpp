#include <string>
#include <iostream>

#include "item.hpp"

#ifndef RESTRICTED_HPP
#define RESTRICTED_HPP

class Restricted: public Item {
    private:
        std::string super_user_;

    public:
        //constructors
        Restricted(const std::string& code, const int& quantity, const std::string& super_user);
        Restricted(const Restricted& restricted);

        //destructor
        ~Restricted();

        //member functions
        std::ostream& Print(std::ostream& os) const;
};

#endif