/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:40:25 by damoncad          #+#    #+#             */
/*   Updated: 2025/10/31 19:46:32 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// int main() {
//     try {
//         Bureaucrat a("Arnold", 2);
//         std::cout << a << std::endl;

//         a.incrementGrade();
//         std::cout << "After increment: " << a << std::endl;

//         std::cout << "Trying to increment beyond 1..." << std::endl;
//         a.incrementGrade();
//     }
//     catch (std::exception& e) {
//         std::cerr << "Caught exception: " << e.what() << std::endl;
//     }

//     try {
//         //costruzione grade invalido gradetoolow
//         std::cout << "Trying to create Bob with grade 151..." << std::endl;
//         Bureaucrat b("Bob", 151);
//         (void)b;
//     }
//     catch (std::exception& e) {
//         std::cerr << "Caught exception while construction Bob: " << e.what() << std::endl;
//     }

//     try {
//         Bureaucrat c("Carlo", 150);
//         std::cout << c << std::endl;
//         c.decrementGrade();
//     }
//     catch (std::exception& e) {
//         std::cerr << "Caught exception: " << e.what() << std::endl;
//     }

//     //test defautl ctor e copy/assign
//     Bureaucrat def;
//     std::cout << "Default: " << def << std::endl;
//     Bureaucrat copy(def);
//     std::cout << "Copy: " << copy << std::endl;
//     Bureaucrat assigned("Temp", 10);
//     std::cout << "Before assign: " << assigned << std::endl;
//     assigned = def;
//     std::cout << "After assign: " << assigned << std::endl;
//     return 0;
// }


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form tax("Tax Declaration", 60, 100);
        Form secret("Secret Form", 40, 20);

        std::cout << tax << std::endl;
        std::cout << secret << std::endl;

        bob.signForm(tax);    // ✅ riuscirà
        bob.signForm(secret); // ❌ fallirà

        std::cout << tax << std::endl;
        std::cout << secret << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
