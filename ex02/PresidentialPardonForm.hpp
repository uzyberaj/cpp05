#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

// Forme concrete : pardon presidentiel par Zaphod Beeblebrox.
// Grades requis : sign 25, exec 5.
class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	const std::string& getTarget() const;

private:
	const std::string	_target;

	virtual void executeAction(Bureaucrat const& executor) const;
};

#endif
