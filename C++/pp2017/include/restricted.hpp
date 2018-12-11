#include <string>
#include <iostream>

#include "item.hpp"

#ifndef RESTRICTED_HPP
#define RESTRICTED_HPP

class Restricted: public Item {
    private:
        std::string super_user_;

    public:
        ~Restricted();
        Restricted(const std::string& code, const int& quantity, const std::string& super_user);

        void Print(std::ostream& os) const;
};

#endif