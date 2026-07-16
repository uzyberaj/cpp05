#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Type : pointeur vers une fonction membre qui cree un AForm* a partir d'une target.
typedef AForm* (Intern::*CreateFormFunc)(std::string const& target) const;

// Entree du tableau de dispatch : nom du formulaire + fonction a appeler.
struct FormEntry
{
	const char*		name;
	CreateFormFunc	func;
};

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::createShrubbery(std::string const& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createRobotomy(std::string const& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createPresidential(std::string const& target) const
{
	return (new PresidentialPardonForm(target));
}

// makeForm : parcourt le tableau de noms/fonctions au lieu d'un long if/else.
AForm* Intern::makeForm(std::string const& formName, std::string const& target) const
{
	static const FormEntry forms[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};
	static const size_t formCount = sizeof(forms) / sizeof(forms[0]);

	for (size_t i = 0; i < formCount; ++i)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*forms[i].func)(target));
		}
	}

	std::cout << "Error: form \"" << formName << "\" does not exist." << std::endl;
	return (NULL);
}
