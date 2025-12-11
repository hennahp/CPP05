#include "Form.hpp"

int main(void)
{
    std::cout << PURPLE << "----- Creating Bureaucrat and Form -----" << RESET << std::endl;
    Bureaucrat b1("Alice", 42);
    Form f1("TopSecret", 50, 30);

    b1.signForm(f1);
    b1.signForm(f1);

    Bureaucrat b2("Bob", 100);
    b2.signForm(f1);
    return 0;
}