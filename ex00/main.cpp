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
        b1.incrementGrade(); // This should throw an exception
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
}