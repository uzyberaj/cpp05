/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:19:54 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:19:55 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>

// Programme de test pour l'exercice 03.
// Tests 1-23 : ex02. Tests 24-28 : classe Intern et makeForm().
// Le correcteur peut tout verifier en lançant ./intern.

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// === Test 1 : constructeur valide + operator<< ===
	std::cout << "=== Test 1 : constructeur valide + operator<< ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 2 : grade valide borne minimale (1) ===
	std::cout << "\n=== Test 2 : grade valide borne minimale (1) ===" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		std::cout << "getName() = " << top.getName() << ", getGrade() = " << top.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 3 : grade valide borne maximale (150) ===
	std::cout << "\n=== Test 3 : grade valide borne maximale (150) ===" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 4 : grade invalide au constructeur (0) ===
	std::cout << "\n=== Test 4 : grade invalide au constructeur (0) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << "ERREUR : aucune exception levee pour le grade 0" << std::endl;
		(void)invalid;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 5 : grade invalide au constructeur (151) ===
	std::cout << "\n=== Test 5 : grade invalide au constructeur (151) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << "ERREUR : aucune exception levee pour le grade 151" << std::endl;
		(void)invalid;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 6 : incrementGrade (succes, 3 -> 2) ===
	std::cout << "\n=== Test 6 : incrementGrade (succes, 3 -> 2) ===" << std::endl;
	try
	{
		Bureaucrat b("Alice", 3);
		std::cout << "Avant increment : " << b << std::endl;
		b.incrementGrade();
		std::cout << "Apres increment : " << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 7 : decrementGrade (succes, 3 -> 4) ===
	std::cout << "\n=== Test 7 : decrementGrade (succes, 3 -> 4) ===" << std::endl;
	try
	{
		Bureaucrat b("Charlie", 3);
		std::cout << "Avant decrement : " << b << std::endl;
		b.decrementGrade();
		std::cout << "Apres decrement : " << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 8 : incrementGrade a la borne (grade 1) ===
	std::cout << "\n=== Test 8 : incrementGrade a la borne (grade 1) ===" << std::endl;
	try
	{
		Bureaucrat b("Max", 1);
		std::cout << "Grade avant : " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "ERREUR : aucune exception levee au grade 1" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 9 : decrementGrade a la borne (grade 150) ===
	std::cout << "\n=== Test 9 : decrementGrade a la borne (grade 150) ===" << std::endl;
	try
	{
		Bureaucrat b("Min", 150);
		std::cout << "Grade avant : " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << "ERREUR : aucune exception levee au grade 150" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 10 : OCF Bureaucrat ===
	std::cout << "\n=== Test 10 : OCF Bureaucrat (copie + affectation) ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copie(original);
		std::cout << "Original : " << original << std::endl;
		std::cout << "Copie    : " << copie << std::endl;
		Bureaucrat autre("Autre", 99);
		autre = original;
		std::cout << "Apres affectation, autre : " << autre << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 11 : AForm via forme concrete + operator<< + getters ===
	// Sujet ex02 : AForm est abstraite, on teste via ShrubberyCreationForm("home").
	std::cout << "\n=== Test 11 : AForm + operator<< + getters (ShrubberyCreationForm) ===" << std::endl;
	try
	{
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		std::cout << "getName()=" << shrub.getName()
			<< ", getIsSigned()=" << (shrub.getIsSigned() ? "true" : "false")
			<< ", getGradeToSign()=" << shrub.getGradeToSign()
			<< ", getGradeToExecute()=" << shrub.getGradeToExecute()
			<< ", target=" << shrub.getTarget() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 12 : grades des formes concretes (valeurs du sujet) ===
	// Sujet : Shrubbery 145/137, Robotomy 72/45, Presidential 25/5.
	std::cout << "\n=== Test 12 : grades des formes concretes ===" << std::endl;
	try
	{
		ShrubberyCreationForm s("a");
		RobotomyRequestForm r("b");
		PresidentialPardonForm p("c");
		std::cout << "Shrubbery  : sign=" << s.getGradeToSign()
			<< " exec=" << s.getGradeToExecute() << " (attendu 145/137)" << std::endl;
		std::cout << "Robotomy   : sign=" << r.getGradeToSign()
			<< " exec=" << r.getGradeToExecute() << " (attendu 72/45)" << std::endl;
		std::cout << "Presidential: sign=" << p.getGradeToSign()
			<< " exec=" << p.getGradeToExecute() << " (attendu 25/5)" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 13 : beSigned succes ===
	// PresidentialPardon exige sign 25, bureaucrate grade 20 -> OK.
	std::cout << "\n=== Test 13 : beSigned succes ===" << std::endl;
	try
	{
		Bureaucrat chief("Chief", 20);
		PresidentialPardonForm form("Arthur");
		std::cout << "Avant beSigned : " << form << std::endl;
		form.beSigned(chief);
		std::cout << "Apres beSigned : " << form << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 14 : beSigned echec ===
	// Bureaucrate grade 30, form exige sign 25 -> trop bas.
	std::cout << "\n=== Test 14 : beSigned echec (grade trop bas) ===" << std::endl;
	try
	{
		Bureaucrat junior("Junior", 30);
		PresidentialPardonForm form("Ford");
		form.beSigned(junior);
		std::cout << "ERREUR : aucune exception levee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 15 : signForm succes ===
	std::cout << "\n=== Test 15 : signForm succes ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		PresidentialPardonForm permis("Marvin");
		bob.signForm(permis);
		std::cout << "Etat du formulaire : " << permis << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 16 : signForm echec ===
	std::cout << "\n=== Test 16 : signForm echec ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 140);
		PresidentialPardonForm dossier("Trillian");
		intern.signForm(dossier);
		std::cout << "Etat du formulaire : " << dossier << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : signForm ne doit pas propager l'exception : " << e.what() << std::endl;
	}

	// === Test 17 : ShrubberyCreationForm ===
	// Sujet : cree le fichier <target>_shrubbery avec des arbres ASCII.
	std::cout << "\n=== Test 17 : ShrubberyCreationForm (fichier home_shrubbery) ===" << std::endl;
	try
	{
		Bureaucrat gardener("Gardener", 1);
		ShrubberyCreationForm shrub("home");
		gardener.signForm(shrub);
		shrub.execute(gardener);
		std::ifstream file("home_shrubbery");
		if (file.is_open())
		{
			std::cout << "Fichier home_shrubbery cree avec succes." << std::endl;
			file.close();
		}
		else
			std::cout << "ERREUR : fichier home_shrubbery introuvable" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 18 : RobotomyRequestForm ===
	// Sujet : bruit de perceuse + succes ou echec (~50%).
	std::cout << "\n=== Test 18 : RobotomyRequestForm (bruit + resultat aleatoire) ===" << std::endl;
	try
	{
		Bureaucrat surgeon("Surgeon", 1);
		RobotomyRequestForm robotomy("Bender");
		surgeon.signForm(robotomy);
		robotomy.execute(surgeon);
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 19 : PresidentialPardonForm ===
	// Sujet : "<target> has been pardoned by Zaphod Beeblebrox."
	std::cout << "\n=== Test 19 : PresidentialPardonForm (message de pardon) ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Zaphod");
		president.signForm(pardon);
		pardon.execute(president);
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 20 : execute forme non signee ===
	// Sujet : forme non signee -> exception FormNotSignedException.
	std::cout << "\n=== Test 20 : execute forme non signee ===" << std::endl;
	try
	{
		Bureaucrat b("Executor", 1);
		ShrubberyCreationForm unsignedForm("garden");
		unsignedForm.execute(b);
		std::cout << "ERREUR : aucune exception levee pour forme non signee" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 21 : execute grade insuffisant ===
	// Shrubbery exec 137 : bureaucrate grade 140 -> GradeTooLowException.
	std::cout << "\n=== Test 21 : execute grade insuffisant ===" << std::endl;
	try
	{
		Bureaucrat weak("Weak", 140);
		ShrubberyCreationForm form("park");
		weak.signForm(form);
		form.execute(weak);
		std::cout << "ERREUR : aucune exception levee pour grade insuffisant" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 22 : executeForm succes ===
	// Sujet : "<bureaucrat> executed <form>"
	std::cout << "\n=== Test 22 : executeForm succes ===" << std::endl;
	try
	{
		Bureaucrat exec("Exec", 1);
		PresidentialPardonForm form("Slartibartfast");
		exec.signForm(form);
		exec.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 23 : executeForm echec ===
	// Robotomy exec 45 : bureaucrate grade 50 signe OK mais execute echoue.
	std::cout << "\n=== Test 23 : executeForm echec ===" << std::endl;
	try
	{
		Bureaucrat rookie("Rookie", 50);
		RobotomyRequestForm form("Bender");
		rookie.signForm(form);
		rookie.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : executeForm ne doit pas propager l'exception : " << e.what() << std::endl;
	}

	// === Test 24 : makeForm robotomy request ===
	// Sujet : affiche "Intern creates <form>" et retourne un AForm* valide.
	std::cout << "\n=== Test 24 : makeForm robotomy request ===" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("robotomy request", "Target1");
		if (form)
		{
			std::cout << "Formulaire cree : " << *form << std::endl;
			delete form;
		}
		else
			std::cout << "ERREUR : makeForm a retourne NULL" << std::endl;
	}

	// === Test 25 : makeForm shrubbery creation ===
	std::cout << "\n=== Test 25 : makeForm shrubbery creation ===" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("shrubbery creation", "office");
		if (form)
		{
			std::cout << "Formulaire cree : " << *form << std::endl;
			delete form;
		}
		else
			std::cout << "ERREUR : makeForm a retourne NULL" << std::endl;
	}

	// === Test 26 : makeForm presidential pardon ===
	std::cout << "\n=== Test 26 : makeForm presidential pardon ===" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("presidential pardon", "Arthur");
		if (form)
		{
			std::cout << "Formulaire cree : " << *form << std::endl;
			delete form;
		}
		else
			std::cout << "ERREUR : makeForm a retourne NULL" << std::endl;
	}

	// === Test 27 : makeForm nom inconnu ===
	// Sujet : message d'erreur explicite + retour NULL.
	std::cout << "\n=== Test 27 : makeForm nom inconnu ===" << std::endl;
	{
		Intern intern;
		AForm* form = intern.makeForm("coffee request", "Mug");
		if (form)
		{
			std::cout << "ERREUR : makeForm aurait du retourner NULL" << std::endl;
			delete form;
		}
		else
			std::cout << "makeForm a bien retourne NULL pour un nom inconnu." << std::endl;
	}

	// === Test 28 : exemple exact du sujet ===
	// makeForm("robotomy request", "Bender") -> RobotomyRequestForm.
	std::cout << "\n=== Test 28 : exemple du sujet (robotomy request, Bender) ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << "Type attendu Robotomy Request : " << rrf->getName() << std::endl;
			delete rrf;
		}
		else
			std::cout << "ERREUR : makeForm a retourne NULL" << std::endl;
	}

	return (0);
}
