/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:13:22 by damoncad          #+#    #+#             */
/*   Updated: 2026/01/21 19:58:21 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(NULL));
    {
        Intern someRandomIntern;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Home");
        
        if (scf) {
            Bureaucrat bob("Bob", 137);
            std::cout << *scf << std::endl;
        
            bob.signForm(*scf);
            bob.executeForm(*scf);
            delete scf;
        }
    }
    {
        Intern intern;
        AForm* rrf = intern.makeForm("robotomy request", "Bender");

        if (rrf) {
            Bureaucrat alice("alice", 1);

            std::cout << *rrf << std::endl;
            alice.signForm(*rrf);
            alice.executeForm(*rrf);

            delete rrf;
        }
    }
    {
        Intern intern;
        AForm* ppf = intern.makeForm("presidential pardon", "Marvin Gave");

        if (ppf) {
            Bureaucrat president("President", 1);

            std::cout << *ppf << std::endl;
            president.signForm(*ppf);
            president.executeForm(*ppf);

            delete ppf;
        }
    }
    {
        Intern intern;
        AForm* invalid = intern.makeForm("invalid form", "davide");

        if (invalid == NULL) {
            std::cout << "-> Correctly returned NULL for invalid form request name." << std::endl;
        }
        else {
            std::cout << "ERROR: Should have returned NULL!" << std::endl;
            delete invalid;
        }
    }
    {
        Intern intern;
        Bureaucrat god("God", 1);

        AForm* forms[3];

        forms[0] = intern.makeForm("shrubbery creation", "Garden");
        forms[1] = intern.makeForm("robotomy request", "Criminal");
        forms[2] = intern.makeForm("presidential pardon", "Politician");

        for (int i = 0; i < 3; i++) {
            if (forms[i]) {
                std::cout << "\n------ Processing form " << i + 1 << " ---" << std::endl;
                std::cout << *forms[i] << std::endl;

                god.signForm(*forms[i]);
                god.executeForm(*forms[i]);

                delete forms[i];
            }
        }
    }
    {
        Intern intern1;
        Intern intern2(intern1);
        Intern intern3;
        intern3 = intern1;

        AForm* f1 = intern1.makeForm("shrubbery creation", "office");
        AForm* f2 = intern2.makeForm("robotomy request", "target");
        AForm* f3 = intern3.makeForm("presidential pardon", "citizen");

        delete f1;
        delete f2;
        delete f3;
    }
    return 0;
}
