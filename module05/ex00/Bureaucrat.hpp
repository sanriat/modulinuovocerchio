
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>


class Bureaucrat
{
    public:
        //eccezioni
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        //getters
        const std::string& getName() const;
        int getGrade() const;

        //grade modification
        void incrementGrade();
        void decrementGrade();

    private:
        const std::string _name;
        int _grade;

        //helper
        void checkGrade(int grade) const; //validate grade or throw
};

//insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif