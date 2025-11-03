#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
            const char* what() const throw() { return "Form grade is too high"; };
        };
        class GradeTooLowException : public std::exception {
            const char* what() const throw() { return "Form grade is too low"; };
        };
   };

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
