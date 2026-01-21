#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);

		// Metodo virtuale puro - rende AForm classe astratta
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
			const char* what() const throw();
		};

	protected:
		// Metodo helper per le classi derivate
		void checkExecution(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif