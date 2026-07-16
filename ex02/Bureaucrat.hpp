/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:18:49 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:18:50 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;

// Classe Bureaucrat : un employé administratif avec un nom fixe et un grade.
// Le sujet demande un grade de 1 (le meilleur) à 150 (le pire).
class Bureaucrat
{
public:
	// --- Exceptions internes ---
	// Le sujet dit qu'elles n'ont pas besoin de l'OCF, mais doivent
	// hériter de std::exception pour être catchables avec catch (std::exception&).
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

	// --- Orthodox Canonical Form (obligatoire sauf pour les exceptions) ---
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// --- Getters (le sujet demande getName et getGrade) ---
	const std::string& getName() const;
	int getGrade() const;

	// increment = grade plus petit = meilleur bureaucrate (ex: 3 -> 2)
	// decrement = grade plus grand = bureaucrate moins bon (ex: 2 -> 3)
	void incrementGrade();
	void decrementGrade();

	// Tente de signer un formulaire via AForm::beSigned().
	void signForm(AForm& form);

	// Tente d'executer un formulaire via AForm::execute().
	void executeForm(AForm const& form) const;

private:
	const std::string	_name;	// const : le nom ne change jamais après construction
	int					_grade;	// pas const car increment/decrement le modifient

	// Fonction utilitaire pour valider le grade (utilisée par le constructeur
	// et par increment/decrement pour éviter de dupliquer la logique).
	void checkGrade(int grade) const;
};

// operator<< surcharge : affiche "<name>, bureaucrat grade <grade>."
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
