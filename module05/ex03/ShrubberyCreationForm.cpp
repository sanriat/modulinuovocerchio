/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:11:53 by damoncad          #+#    #+#             */
/*   Updated: 2026/01/20 20:23:24 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Costruttore: inizializza AForm con nome, grade per firma (145) e grade per esecuzione (137)
// Poi inizializza il nostro attributo _target
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

// Copy constructor: copia la classe base e il target
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
	: AForm(other), _target(other._target) {}

// Assignment operator: copia la classe base e il target
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);  // Chiama l'operatore della classe base
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Implementazione del metodo execute
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	// 1. Controllo prerequisiti: form firmato + executor con grade sufficiente
	//    Se fallisce, lancia un'eccezione (GradeTooLowException o FormNotSignedException)
	checkExecution(executor);
	
	// 2. Crea il file <target>_shrubbery
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());  // .c_str() per compatibilità C++98
	
	if (!file.is_open()) {
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}
	
	// 3. Scrive ASCII trees nel file
	file << "       ###\n";
	file << "      #o###\n";
	file << "    #####o###\n";
	file << "   #o#\\#|#/###\n";
	file << "    ###\\|/#o#\n";
	file << "     # }|{  #\n";
	file << "       }|{\n";
	file << "\n";
	file << "      ^^^^^^^^^^\n";
	file << "     ^^^^^^^^^^^^\n";
	file << "    ^^^^^^^^^^^^^^\n";
	file << "   ^^^^^^^^^^^^^^^^\n";
	file << "  ^^^^^^^^^^^^^^^^^^\n";
	file << "       |  |  |\n";
	file << "       |  |  |\n";
	file << "      ~~~~~~~~\n";
	
	file.close();
	
	// Non serve stampare nulla qui, ci pensa Bureaucrat::executeForm()
}