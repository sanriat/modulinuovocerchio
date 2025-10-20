/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:41:03 by damoncad          #+#    #+#             */
/*   Updated: 2025/10/20 20:06:21 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "GradeTooHighException: grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "GradeTooLowException: grade is too low";
}

Bureaucrat::Bureaucrat () : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat (const std::string& name, int grade) : _name(name), _grade(grade) {
    checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

//GETTERS
const std::string& Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

//GRADE MODIFICATION
void Bureaucrat::incrementGrade() {
    checkGrade(_grade - 1);
    _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    checkGrade(_grade + 1);
    _grade += 1;
}

//HELPER
void Bureaucrat::checkGrade(int grade) const {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

//operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
