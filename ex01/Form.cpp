/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:18:19 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:18:20 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// --- Messages des exceptions ---
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

// --- Orthodox Canonical Form ---

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	checkGrade(_gradeToSign);
	checkGrade(_gradeToExecute);
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		// _name et les grades sont const : seul _isSigned peut changer.
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

// --- Getters ---

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// --- Validation des grades ---

void Form::checkGrade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	if (grade > 150)
		throw Form::GradeTooLowException();
}

// --- beSigned ---
// Grade 1 > grade 2 : le bureaucrate doit avoir un grade <= grade requis.
// Ex: form exige 50, bureaucrate grade 40 -> OK. Grade 60 -> trop bas -> exception.

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

// --- operator<< ---
// Affiche nom, etat de signature, et les deux grades requis.

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName() << ", form "
		<< (form.getIsSigned() ? "signed" : "not signed")
		<< ", grade required to sign " << form.getGradeToSign()
		<< ", grade required to execute " << form.getGradeToExecute() << ".";
	return (out);
}
