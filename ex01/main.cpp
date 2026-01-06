/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hparveen <hparveen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 09:39:49 by hparveen          #+#    #+#             */
/*   Updated: 2026/01/06 09:39:50 by hparveen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
    std::cout << PURPLE << "----- Creating Bureaucrat and Form -----" << RESET << std::endl;
    try
    {
        Bureaucrat b1("Alice", 42);   
        Form f1("TopSecret", 50, 30);
        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
        b1.signForm(f1);

        Bureaucrat b2("Bob", 100);
        b2.signForm(f1);
    }
    catch(const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    return 0;
}