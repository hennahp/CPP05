#include "Form.hpp"

int main(void)
{
    std::cout << PURPLE << "----- Creating Bureaucrat and Form -----" << RESET << std::endl;
    try
    {
        Bureaucrat b1("Alice", 42);   
        Form f1("TopSecret", 50, 30);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
        b1.signForm(f1);

        Bureaucrat b2("Bob", 100);
        b2.signForm(f1);
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}