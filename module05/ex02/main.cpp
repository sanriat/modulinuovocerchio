/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:13:22 by damoncad          #+#    #+#             */
/*   Updated: 2026/01/20 20:29:27 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main() {
    // Inizializza il seed per numeri random (per RobotomyRequestForm)
    srand(time(NULL));
    
    std::cout << "=== TEST 1: ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 140);  // Grade sufficiente (145 per firmare, 137 per eseguire)
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);        // Bob firma il form
        bob.executeForm(shrub);     // Bob esegue il form (crea il file)
        
        std::cout << "Check if 'home_shrubbery' file was created!" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 2: ShrubberyCreationForm - Grade troppo basso ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);  // Grade troppo basso
        ShrubberyCreationForm shrub("garden");
        
        std::cout << intern << std::endl;
        intern.signForm(shrub);     // Fallirà: grade 150 > 145 richiesto
        intern.executeForm(shrub);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 3: RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 40);  // Grade sufficiente (72 per firmare, 45 per eseguire)
        RobotomyRequestForm robot("Bender");
        
        std::cout << alice << std::endl;
        std::cout << robot << std::endl;
        
        alice.signForm(robot);
        alice.executeForm(robot);   // 50% successo/fallimento
        alice.executeForm(robot);   // Prova di nuovo per vedere risultati diversi
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 4: RobotomyRequestForm - Form non firmato ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 1);
        RobotomyRequestForm robot("Target");
        
        // Non firma il form
        charlie.executeForm(robot);  // Fallirà: form non firmato
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 5: PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat president("Mr. President", 1);  // Il grade più alto possibile
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);   // Grade 1 < 25, OK
        president.executeForm(pardon); // Grade 1 < 5, OK
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 6: PresidentialPardonForm - Grade insufficiente ===" << std::endl;
    try {
        Bureaucrat manager("Manager", 10);  // Grade 10: può firmare (< 25) ma non eseguire (> 5)
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << manager << std::endl;
        manager.signForm(pardon);      // OK, 10 < 25
        manager.executeForm(pardon);   // Fallirà: 10 > 5
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TEST 7: Tutti i form con un solo Bureaucrat ===" << std::endl;
    try {
        Bureaucrat god("God", 1);
        
        ShrubberyCreationForm s("office");
        RobotomyRequestForm r("Employee");
        PresidentialPardonForm p("Citizen");
        
        god.signForm(s);
        god.signForm(r);
        god.signForm(p);
        
        god.executeForm(s);
        god.executeForm(r);
        god.executeForm(p);
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}