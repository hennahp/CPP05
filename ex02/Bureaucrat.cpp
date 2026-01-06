/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:52:11 by hparveen          #+#    #+#             */
/*   Updated: 2026/01/06 09:52:12 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    std::cout << GREEN << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "Bureaucrat Parameterized constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << BLUE << "Bureaucrat Copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->_grade = other._grade;
    std::cout << BLUE << "Bureaucrat Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << "Bureaucrat Destructor called" << RESET << std::endl;
}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if(_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if(_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << _name << " signed " << form.getName() << RESET << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << RED << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << RED << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << RESET << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << PURPLE << obj.getName() << ", bureaucrat grade " << obj.getGrade() << RESET;
    return out;
}
