/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:17:58 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:17:59 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Programme de test pour l'exercice 00.
// Chaque section illustre un point du sujet en lançant ./bureaucrat.

int main()
{
	// === Test 1 : constructeur valide + operator<< ===
	// Sujet : grade entre 1 et 150, affichage "<name>, bureaucrat grade <grade>."
	// Attendu : "Bob, bureaucrat grade 42."
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

	// === Test 2 : grade valide borne minimale (1 = le meilleur) ===
	// Sujet : grade 1 est le plus haut possible.
	// Attendu : "Top, bureaucrat grade 1."
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

	// === Test 3 : grade valide borne maximale (150 = le pire) ===
	// Sujet : grade 150 est le plus bas possible.
	// Attendu : "Bottom, bureaucrat grade 150."
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
	// Sujet : grade < 1 -> GradeTooHighException, catchable via std::exception&
	// Attendu : message d'exception affiche, pas de creation de l'objet
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
	// Sujet : grade > 150 -> GradeTooLowException
	// Attendu : message d'exception affiche
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

	// === Test 6 : incrementGrade (succes) ===
	// Sujet : incrementer un grade 3 donne un grade 2 (numero plus petit = meilleur).
	// Attendu : grade passe de 3 a 2
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

	// === Test 7 : decrementGrade (succes) ===
	// Sujet : decrementer un grade 3 donne un grade 4 (numero plus grand = pire).
	// Attendu : grade passe de 3 a 4
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
	// Sujet : impossible d'incrementer au-dela du grade 1 -> GradeTooHighException
	// Attendu : exception attrapee, grade reste a 1
	std::cout << "\n=== Test 8 : incrementGrade a la borne (grade 1) ===" << std::endl;
	try
	{
		Bureaucrat b("Max", 1);
		std::cout << "Grade avant : " << b.getGrade() << std::endl;
		b.incrementGrade();
		std::cout << "ERREUR : aucune exception levee au grade 1" << std::endl;
		std::cout << "Grade apres : " << b.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 9 : decrementGrade a la borne (grade 150) ===
	// Sujet : impossible de decrementer en dessous du grade 150 -> GradeTooLowException
	// Attendu : exception attrapee, grade reste a 150
	std::cout << "\n=== Test 9 : decrementGrade a la borne (grade 150) ===" << std::endl;
	try
	{
		Bureaucrat b("Min", 150);
		std::cout << "Grade avant : " << b.getGrade() << std::endl;
		b.decrementGrade();
		std::cout << "ERREUR : aucune exception levee au grade 150" << std::endl;
		std::cout << "Grade apres : " << b.getGrade() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 10 : Orthodox Canonical Form (copie + affectation) ===
	// Le sujet demande l'OCF pour Bureaucrat : on verifie copie et affectation.
	// Attendu : copie et affectation conservent nom et grade
	std::cout << "\n=== Test 10 : OCF (constructeur de copie + affectation) ===" << std::endl;
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

	return (0);
}
