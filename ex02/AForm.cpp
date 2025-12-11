#include "AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << GREEN << "AForm Default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : 
    _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "AForm Parameterized constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm &other) :
    _name(other._name), _isSigned(other._isSigned), 
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << BLUE << "AForm Copy constructor called" << RESET << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if(this != &other)
        this->_isSigned = other._isSigned;
    std::cout << BLUE << "AForm Copy assignment operator called" << RESET << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << RED << "AForm Destructor called" << RESET << std::endl;
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << PURPLE << "AForm Name: " << obj.getName() 
        << ", Signed: " << (obj.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << obj.getGradeToSign()
        << ", Grade to Execute: " << obj.getGradeToExecute() << RESET;
    return out;
}