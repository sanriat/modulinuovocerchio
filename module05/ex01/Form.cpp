/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:30:05 by damoncad          #+#    #+#             */
/*   Updated: 2025/10/31 19:51:46 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
        if (gradeToSign < 1 || gradeToExecute < 1)
            throw GradeTooHighException();
        if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName()
       << "| signed: " << (form.isSigned() ? "Yes" : "No")
       << "| grade to Sign: " << form.getGradeToSign()
       << "| grade to Execute: " << form.getGradeToExecute();
    return os;
}
