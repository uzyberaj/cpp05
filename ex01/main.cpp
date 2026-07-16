#include "Bureaucrat.hpp"
#include "Form.hpp"

// Programme de test pour l'exercice 01.
// Tests 1-10 : Bureaucrat (ex00). Tests 11-16 : Form et signForm.
// Le correcteur peut tout verifier en lançant ./form.

int main()
{
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

	// === Test 11 : Form constructeur valide + operator<< + getters ===
	// Sujet : nom, etat signe (false a la construction), grades requis.
	// Attributs private : on y accede uniquement via les getters.
	std::cout << "\n=== Test 11 : Form valide + operator<< + getters ===" << std::endl;
	try
	{
		Form contract("28B", 50, 70);
		std::cout << contract << std::endl;
		std::cout << "getName()=" << contract.getName()
			<< ", getIsSigned()=" << (contract.getIsSigned() ? "true" : "false")
			<< ", getGradeToSign()=" << contract.getGradeToSign()
			<< ", getGradeToExecute()=" << contract.getGradeToExecute() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 12 : grades Form invalides au constructeur ===
	// Sujet : grades hors [1, 150] -> GradeTooHighException ou GradeTooLowException.
	std::cout << "\n=== Test 12 : grades Form invalides (0 et 151) ===" << std::endl;
	try
	{
		Form bad("Bad", 0, 50);
		std::cout << "ERREUR : aucune exception levee pour gradeToSign 0" << std::endl;
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "gradeToSign 0 -> Exception : " << e.what() << std::endl;
	}
	try
	{
		Form bad("Bad", 50, 151);
		std::cout << "ERREUR : aucune exception levee pour gradeToExecute 151" << std::endl;
		(void)bad;
	}
	catch (std::exception& e)
	{
		std::cout << "gradeToExecute 151 -> Exception : " << e.what() << std::endl;
	}

	// === Test 13 : beSigned succes ===
	// Sujet : bureaucrate grade 40, form exige 50 -> le bureaucrate est assez haut (40 < 50).
	// Attendu : getIsSigned() passe a true
	std::cout << "\n=== Test 13 : beSigned succes ===" << std::endl;
	try
	{
		Bureaucrat chief("Chief", 40);
		Form form("TaxForm", 50, 70);
		std::cout << "Avant beSigned : " << form << std::endl;
		form.beSigned(chief);
		std::cout << "Apres beSigned : " << form << std::endl;
		std::cout << "getIsSigned() = " << (form.getIsSigned() ? "true" : "false") << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 14 : beSigned echec (grade bureaucrate trop bas) ===
	// Sujet : bureaucrate grade 60, form exige 50 -> grade trop bas -> GradeTooLowException.
	std::cout << "\n=== Test 14 : beSigned echec (grade trop bas) ===" << std::endl;
	try
	{
		Bureaucrat junior("Junior", 60);
		Form form("SecretForm", 50, 70);
		form.beSigned(junior);
		std::cout << "ERREUR : aucune exception levee" << std::endl;
		std::cout << "getIsSigned() = " << (form.getIsSigned() ? "true" : "false") << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	// === Test 15 : signForm succes ===
	// Sujet : message "<bureaucrat> signed <form>"
	std::cout << "\n=== Test 15 : signForm succes ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		Form permis("Permis", 50, 70);
		bob.signForm(permis);
		std::cout << "Etat du formulaire : " << permis << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : aucune exception attendue ici : " << e.what() << std::endl;
	}

	// === Test 16 : signForm echec ===
	// Sujet : message "<bureaucrat> couldn't sign <form> because <reason>."
	std::cout << "\n=== Test 16 : signForm echec ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 140);
		Form dossier("Dossier", 50, 70);
		intern.signForm(dossier);
		std::cout << "Etat du formulaire : " << dossier << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "ERREUR : signForm ne doit pas propager l'exception : " << e.what() << std::endl;
	}

	return (0);
}
