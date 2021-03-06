/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <msarr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/23 14:24:17 by msarr             #+#    #+#             */
/*   Updated: 2015/06/23 14:24:17 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat b("joe", 4);

    ShrubberyCreationForm f("salut");
    PresidentialPardonForm p("coucou");
    RobotomyRequestForm r("robot");

    std::cout << b << std::endl;
    std::cout << f << std::endl;

    try {
        b.signForm(f);
        b.signForm(p);
        b.signForm(r);
    }
    catch (std::exception const &e) {
        std::cout << e.what() << std::endl;
    }

    b.executeForm(f);
    b.executeForm(p);
    b.executeForm(r);
    std::cout << f << std::endl;

    return 0;
}