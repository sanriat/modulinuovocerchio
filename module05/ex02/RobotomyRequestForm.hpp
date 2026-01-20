#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>  // Per rand()
# include <ctime>    // Per time() (seed del random)

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    
    public:
        // Grade richiesti: sign 72, exec 45
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;
};

#endif