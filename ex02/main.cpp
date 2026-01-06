/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:52:19 by hparveen          #+#    #+#             */
/*   Updated: 2026/01/06 10:30:20 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    Bureaucrat steve("Steve", 138);
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
    steve.signForm(robot);
    steve.signForm(pardon);
    steve.signForm(shrub);

    std::cout << PURPLE << "\n----- Executing Forms -----" << RESET << std::endl;
    alice.executeForm(shrub);
    alice.executeForm(robot);
    alice.executeForm(pardon);
    bob.executeForm(shrub);
    bob.executeForm(robot);
    bob.executeForm(pardon);

    return 0;
}