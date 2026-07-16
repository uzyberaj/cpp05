#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

// Forme concrete : robotomie avec bruit de perceuse, 50% de succes.
// Grades requis : sign 72, exec 45.
class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	const std::string& getTarget() const;

private:
	const std::string	_target;

	virtual void executeAction(Bureaucrat const& executor) const;
};

#endif
