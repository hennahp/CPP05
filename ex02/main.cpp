# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <cstdlib>
# include <ctime>

int main()
{
    std::srand(std::time(NULL));

    std::cout << PURPLE << "----- Creating Bureaucrats -----" << RESET << std::endl;
    Bureaucrat bob("Bob", 150);
    Bureaucrat alice("Alice", 1);

    std::cout << PURPLE << "\n----- Creating Forms -----" << RESET << std::endl;
    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << PURPLE << "\n----- Signing Forms -----" << RESET << std::endl;
    bob.signForm(shrub);
    bob.signForm(robot);
    bob.signForm(pardon);
    alice.signForm(shrub);
    alice.signForm(robot);
    alice.signForm(pardon);

    std::cout << PURPLE << "\n----- Executing Forms -----" << RESET << std::endl;
    alice.executeForm(shrub);
    alice.executeForm(robot);
    alice.executeForm(pardon);
    bob.executeForm(shrub);
    bob.executeForm(robot);
    bob.executeForm(pardon);

    return 0;
}