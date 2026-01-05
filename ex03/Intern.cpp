#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
    std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*creators[3]) (const std::string &) = {
        &ShrubberyCreationForm::create,
        &RobotomyRequestForm::create,
        &PresidentialPardonForm::create 
    };
    for(int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern couldn't create form because form name is invalid." << formName << std::endl;
    return NULL;
}
