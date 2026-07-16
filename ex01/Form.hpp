/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:18:26 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:18:27 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

// Classe Form : un formulaire administratif a signer et executer.
// Attributs tous private (le sujet l'exige explicitement).
class Form
{
public:
	// Exceptions pour les grades hors limites [1, 150] (memes regles que Bureaucrat).
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	// --- Orthodox Canonical Form ---
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	// --- Getters (un par attribut) ---
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Tente de faire signer le formulaire par le bureaucrate.
	// Grade du bureaucrate <= grade requis -> signe, sinon throw GradeTooLowException.
	void beSigned(const Bureaucrat& bureaucrat);

private:
	const std::string	_name;
	bool				_isSigned;			// false a la construction
	const int			_gradeToSign;
	const int			_gradeToExecute;

	void checkGrade(int grade) const;
};

// Affiche toutes les infos du formulaire.
std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
