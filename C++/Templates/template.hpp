#include <vector>
#include <algorithm>

template <class type>

void my_swap(type& a, type& b){
    type c;
    c = a;
    a = b;
    b = c;
}

template <class type>
void my_sort(std::vector<type>& numbers){
    sort(numbers.begin(), numbers.end());
}


template <typename type>
void iter_vec(const std::vector<type>& v) {
    typename std::vector<type>::const_iterator it;
    for (it = v.begin(); it != v.end(); ++it){
        std::cout << *it <<std::endl;
    }
}

template <typename type>
int index_smallest_element(const type& vect) {
    if (vect.empty()) {
        return -1;
    }

    auto min_value = *(vect.begin());
    int index = 0;
    int min_index = 0;
    for (typename type::const_iterator it = vect.begin(); it != vect.end(); ++it) {
        if (*it < min_value) {
            min_value = *it;
            min_index = index;
        }
        index++;
    }
    return min_index;
}