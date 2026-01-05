# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "Intern.hpp"
# include <cstdlib>
# include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << PURPLE << "---- Creating Intern ----" << RESET << std::endl;
    Intern someRandomIntern;

    std::cout << PURPLE << "---- Creating Bureaucrat ----" << RESET << std::endl;
    Bureaucrat boss("Boss", 1);

    std::cout << PURPLE << "---- Intern Create Forms ----" << RESET << std::endl;

    AForm* f1;
    AForm* f2;
    AForm* f3;

    try
    {
        f1 = someRandomIntern.makeForm("shrubbery creation", "Home");
        f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        f3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    
    std::cout << PURPLE << "---- Signing and Executing Forms ----" << RESET << std::endl;
    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }

    std::cout << PURPLE << "---- Testing Invalid Form Creation ----" << RESET << std::endl;
    try
    {
        AForm *invalid = someRandomIntern.makeForm("invalid form", "Target");
        if (invalid)
            delete invalid;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << '\n';
    }
    return 0;
}