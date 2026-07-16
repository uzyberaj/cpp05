/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:19:38 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:19:39 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// --- Messages des exceptions ---
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high (must be >= 1).";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low (must be <= 150).";
}

// --- Orthodox Canonical Form ---

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

// Le constructeur valide le grade : hors de [1, 150] -> throw.
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	checkGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		// _name est const : on ne peut pas le réassigner.
		// On copie seulement le grade (comportement classique en C++98).
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

// --- Getters ---

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

// --- Validation du grade ---

void Bureaucrat::checkGrade(int grade) const
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// --- increment / decrement ---
// Piège du sujet : "increment" = numéro plus petit = grade MEILLEUR.

void Bureaucrat::incrementGrade()
{
	checkGrade(_grade - 1);
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	checkGrade(_grade + 1);
	_grade++;
}

// --- signForm ---
// Appelle beSigned() : succes -> "<bureaucrat> signed <form>"
// echec -> "<bureaucrat> couldn't sign <form> because <reason>."

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

// --- executeForm ---
// Succes : "<bureaucrat> executed <form>"
// Echec : "<bureaucrat> couldn't execute <form> because <reason>."

void Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
			<< " because " << e.what() << "." << std::endl;
	}
}

// --- operator<< ---
// Format exact du sujet : "<name>, bureaucrat grade <grade>."

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}
