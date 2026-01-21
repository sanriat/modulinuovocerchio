#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    
    public:
        // Costruttore: prende solo il target
        // Chiama il costruttore di AForm passando nome, gradeToSign=145, gradeToExecute=137
        ShrubberyCreationForm(const std::string& target);
        
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        // Override del metodo virtuale puro di AForm
        // 'const' perché non modifica lo stato dell'oggetto
        void execute(Bureaucrat const & executor) const;
};

#endif