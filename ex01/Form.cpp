#include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << GREEN << "Form Default constructor called" << RESET << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : 
    _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << GREEN << "Form Parameterized constructor called" << RESET << std::endl;
}

Form::Form(const Form &other) :
    _name(other._name), _isSigned(other._isSigned), 
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
    std::cout << BLUE << "Form Copy constructor called" << RESET << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if(this != &other)
        this->_isSigned = other._isSigned;
    std::cout << BLUE << "Form Copy assignment operator called" << RESET << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << RED << "Form Destructor called" << RESET << std::endl;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if(bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form Grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << PURPLE << "Form Name: " << obj.getName() 
        << ", Signed: " << (obj.getIsSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << obj.getGradeToSign()
        << ", Grade to Execute: " << obj.getGradeToExecute() << RESET;
    return out;
}