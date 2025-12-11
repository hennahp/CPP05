# include "Bureaucrat.hpp"

int main(void)
{
    std::cout << PURPLE << "----- Creating Bureaucrat -----" << RESET << std::endl;
    try
    {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        std::cout << ORANGE << "----- Incrementing Grade -----" << RESET << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        std::cout << ORANGE << "----- Incrementing Grade Beyond Limit -----" << RESET << std::endl;
        b1.incrementGrade(); 
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << PURPLE << "----- Creating Bureaucrat with Low Grade -----" << RESET << std::endl;
    try
    {
        Bureaucrat b2("Bob", 151);
        std::cout << b2 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << PURPLE << "----- Creating Bureaucrat with High Grade -----" << RESET << std::endl;
    try
    {
        Bureaucrat b3("Charlie", 0);
        std::cout << b3 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << PURPLE << "----- Creating invalid Bureaucrat -----" << RESET << std::endl;
    try
    {
        Bureaucrat b4("Dave", 151);
        std::cout << b4 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}