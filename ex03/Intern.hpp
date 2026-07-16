/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 16:19:50 by ulyssezyber       #+#    #+#             */
/*   Updated: 2026/07/16 16:19:51 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

// Classe Intern : pas de nom, pas de grade. Il fabrique des formulaires via makeForm().
// Le sujet exige un dispatch propre (tableau de pointeurs de fonctions membres).
class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	// Cree un AForm* selon le nom, ou retourne NULL si le nom est inconnu.
	AForm* makeForm(std::string const& formName, std::string const& target) const;

private:
	// Une fonction par forme concrete : appelee via le tableau de dispatch.
	AForm* createShrubbery(std::string const& target) const;
	AForm* createRobotomy(std::string const& target) const;
	AForm* createPresidential(std::string const& target) const;
};

#endif
