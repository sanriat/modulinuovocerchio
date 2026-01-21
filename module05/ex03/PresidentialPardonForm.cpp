/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:12:54 by damoncad          #+#    #+#             */
/*   Updated: 2026/01/20 20:28:27 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Costruttore: sign grade = 25, exec grade = 5 (molto difficile!)
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    // 1. Verifica prerequisiti (form firmato + executor grade <= 5)
    checkExecution(executor);
    
    // 2. Annuncia il perdono presidenziale
    // Zaphod Beeblebrox è un personaggio della "Guida galattica per autostoppisti"
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}