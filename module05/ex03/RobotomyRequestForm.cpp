/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:12:27 by damoncad          #+#    #+#             */
/*   Updated: 2026/01/20 20:26:23 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

// Costruttore: sign grade = 72, exec grade = 45
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    // 1. Verifica prerequisiti
    checkExecution(executor);
    
    // 2. Fa rumore di drilling
    std::cout << "* BZZZZZ * DRRRRRR * WHIRRRRR * BZZZZZZ *" << std::endl;
    
    // 3. Successo al 50%
    // rand() % 2 genera 0 o 1 (50% di probabilità ciascuno)
    if (rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
    }
}