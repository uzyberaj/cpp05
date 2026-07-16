#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		// _target est const : on ne peut pas le reassigner apres construction.
		(void)other;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

// Cree le fichier <target>_shrubbery avec des arbres ASCII.
void ShrubberyCreationForm::executeAction(Bureaucrat const& executor) const
{
	(void)executor;
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		return ;

	file << "       _-_" << std::endl;
	file << "    /~~   ~~\\" << std::endl;
	file << " /~~         ~~\\" << std::endl;
	file << "{               }" << std::endl;
	file << " \\  _-     -_  /" << std::endl;
	file << "   ~  \\\\ //  ~" << std::endl;
	file << "       _-_" << std::endl;
	file << "     /~   ~\\" << std::endl;
	file << " _-~         ~-_" << std::endl;
	file << "{               }" << std::endl;
	file << "  \\  _-   -_  /" << std::endl;
	file << "    ~  \\\\ // ~" << std::endl;
	file.close();
}
