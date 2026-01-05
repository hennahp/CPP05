# include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    :AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    :AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::checkExecutable(executor);

    std::cout << ORANGE << "Bzzzzzz... Vrrrrrrr... " << RESET << std::endl;

    if(std::rand() % 2)
         std::cout << GREEN << _target << " has been robotomized successfully!" << RESET << std::endl;
    else
        std::cout << RED << "Robotomy failed on " << _target << "!" << RESET << std::endl;
}

AForm* RobotomyRequestForm::create(const std::string &target)
{
    return new RobotomyRequestForm(target);
}