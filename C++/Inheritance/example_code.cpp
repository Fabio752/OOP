#include <iostream> 
#include <vector>

class Base {
    private:
        int n_priv;
        
        void f_priv(){
            std::cout << "Base::f_priv()" <<std::endl;
        }

    public:
        Base(): n_priv(0), n_prot(0) {}
        Base(int n1, int n2) : n_priv(n1), n_prot(n2) {}

        ~Base() { 
            std::cout << "~Base(): n_priv = " << n_priv << ", n_prot = " <<n_prot <<std::endl;
        }

        void f(){
            std::cout << "Base::f()" <<std::endl;
        }
        void display() {
            std::cout << "Base::display(): n_priv = " <<n_priv << "n_prot= " <<n_prot <<std::endl;
        }

        void call_all_functions() {
            std::cout << "Base::call_all_functions()" <<std::endl; 
            f();
            f_priv();
            f_prot();
        }

    protected:
        int n_prot;

    void f_prot(){
        std::cout <<"Base::f_prot()" <<std::endl;
    }

};

class Derived : public Base{
    public:
        Derived() : Base(), n_base(0){}
        Derived(int n1, int n2, int n3) : Base(n1, n2), n_base(n3) {}
        ~Derived(){
            std::cout <<"~Derived(): n_base=" <<n_base <<" is leaving" <<std::endl;
        }
        
        void f(){
            std::cout <<"Derived::f()" <<std::endl;
        }

        void f(int n){
            std::cout << "Derived::f(int n) with n=" <<n <<std::endl;
        }

        void display(){
            std::cout << "Derived::display(): " <<std::endl;
            Base::display();
            std::cout <<"n_base=" << n_base <<std::endl;
        }

    void new_function(){
        std::cout << "Derived::new_function()" <<std::endl;
    }

    protected:
        int n_base;

};

class DerivedAgain: public Derived{};
    
void test_1(Base& base, Base& base_2, Derived& derived, Derived& derived_2);
void test_2(DerivedAgain& derived_again);
void test_3();
void test_4();

int main(){
    //TEST  1
    // Base base; 
    // Base base_2(1, 2); 
    // Derived derived;
    // Derived derived_2(7, 2, 3);

    // test_1(base, base_2, derived, derived_2);
    // //TEST  2 
    // DerivedAgain derived_again;
    // test_2(derived_again);
    //TEST  3 
    // test_3();
    //TEST  4 
    test_4();
    //TEST  5 

}

void test_1(Base& base, Base& base_2, Derived& derived, Derived& derived_2){
    std::cout <<"/////////////TEST 1//////////" <<"\n";
    std::cout <<"Base Default constructor:" <<"\n";
    base.call_all_functions();
    std::cout <<"\n" <<"\n" <<"Base Customized constructor:" <<"\n";
    base_2.call_all_functions();
    std::cout <<"\n" <<"\n" <<"Derived Default constructor:" <<"\n";
    derived.f(13);
    derived.display();
    std::cout <<"\n" <<"\n" <<"Derived Customized constructor:" <<"\n";
    derived_2.f(13);
    derived.display();
    std::cout <<"\n" <<"\n";
}

void test_2(DerivedAgain& derived_again){
    std::cout <<"/////////////TEST 2//////////" <<"\n";
    std::cout <<"DerivedAgain Default constructor:" <<"\n";
    derived_again.f(13);
    derived_again.display();
    std::cout <<"\n" <<"\n";
}

void test_3(){
    std::vector<Base> vector_base;
    std::cout <<"/////////////TEST 3//////////" <<"\n";
    
    Base base(1, 1);
    vector_base.push_back(base);
    std::cout <<"vector size: " << vector_base.size() << "\n";
    std::cout <<"vector capacity: " << vector_base.capacity() << "\n";
    
    Derived derived(3, 3, 3);
    vector_base.push_back(derived);
    std::cout <<"vector size: " << vector_base.size() << "\n";
    std::cout <<"vector capacity: " << vector_base.capacity() << "\n";
    
    DerivedAgain derived_again;
    vector_base.push_back(derived_again);
    std::cout <<"vector size: " << vector_base.size() << "\n";
    std::cout <<"vector capacity: " << vector_base.capacity() << "\n";
}

void test_4(){
    std::vector<Base> vector_base;
    std::cout <<"/////////////TEST 3//////////" <<"\n";
    
    Base* base = new Base(1, 1);
    vector_base.push_back(*base);
    std::cout <<"vector size: " << vector_base.size() << "\n";
    std::cout <<"vector capacity: " << vector_base.capacity() << "\n";
    
    Derived* derived = new Derived(3, 3, 3);
    vector_base.push_back(*derived);
    std::cout <<"vector size: " << vector_base.size() << "\n";
    std::cout <<"vector capacity: " << vector_base.capacity() << "\n";
    
    DerivedAgain* derived_again = new DerivedAgain;
    vector_base.push_back(*derived_again);
    std::cout <<"vector size: " << vector_base.size() << "\n";
    std::cout <<"vector capacity: " << vector_base.capacity() << "\n";
}