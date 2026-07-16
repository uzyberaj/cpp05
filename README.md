<p align="left">
  <a href="#--------cpp05--">🇬🇧 English</a> |
  <a href="#--------cpp05---1">🇫🇷 Français</a>
</p>

<h1 align="center">
  <br>
  <img src="https://i.ibb.co/MkL14CvZ/logo-cpp-bonus.png" alt="C++ logo" width="150">
  <br>
  cpp05
  <br>
</h1>

<h4 align="center"><em>C++ Module 05 — Repetition and Exceptions: bureaucrats, forms, and administrative chaos.</em></h4>

<p align="center">
  <img src="https://img.shields.io/badge/exercises-4-orange">
  <img src="https://img.shields.io/badge/C%2B%2B-100%25-blue">
  <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-informational">
</p>

<p align="center">
  <a href="./subject.md">Subject</a> |
  <a href="#-project-overview">Overview</a> •
  <a href="#-code-architecture-and-organization">Architecture</a> •
  <a href="#-operating">Operating</a> •
  <a href="#%EF%B8%8F-compiling-and-testing">Compiling</a>
</p>

---

## 📌 **Project overview**

**cpp05** is the fifth C++ module of the 42 Common Core. It introduces **exceptions**, **inheritance**, and **polymorphism** through a satirical bureaucratic system: `Bureaucrat` employees, administrative `Form`s, and `Intern`s who manufacture paperwork.

The project is split into **4 exercises**, each building on the previous one. All code complies with **C++98**.

### 1. Exercise 00 — Bureaucrat ✅

A `Bureaucrat` has a **constant name** and a **grade** from **1** (highest) to **150** (lowest).

* Invalid grades throw `GradeTooHighException` or `GradeTooLowException`
* `incrementGrade()` lowers the grade number (better rank); `decrementGrade()` raises it
* `operator<<` displays: `<name>, bureaucrat grade <grade>.`
* Full **Orthodox Canonical Form** (OCF)

### 2. Exercise 01 — Form ✅

Adds a `Form` class with private attributes:

* Constant name, signed state (`bool`), grades required to sign and execute
* `beSigned(Bureaucrat)` signs the form if the bureaucrat's grade is high enough
* `Bureaucrat::signForm(Form)` calls `beSigned()` and prints success or failure messages

### 3. Exercise 02 — Concrete forms ✅

Renames `Form` to **`AForm`** (abstract base class) and adds three concrete forms:

| Form | Sign grade | Exec grade | Action |
|------|------------|------------|--------|
| `ShrubberyCreationForm` | 145 | 137 | Creates `<target>_shrubbery` with ASCII trees |
| `RobotomyRequestForm` | 72 | 45 | Drilling noise + 50% robotomy success |
| `PresidentialPardonForm` | 25 | 5 | Pardons `<target>` via Zaphod Beeblebrox |

* `AForm::execute(Bureaucrat const&)` checks signature and grade, then calls `executeAction()` in subclasses
* `Bureaucrat::executeForm(AForm const&)` attempts execution with explicit error messages

### 4. Exercise 03 — Intern ✅

The `Intern` class has no name or grade. Its only job is `makeForm(formName, target)`:

* Returns a dynamically allocated `AForm*` (`new`)
* Prints `Intern creates <form>` on success
* Uses a **clean dispatch table** (array of member function pointers), not long `if/else` chains
* Returns `NULL` and prints an error for unknown form names

### Error handling ⚠️

Exceptions derive from `std::exception` and are catchable via `catch (std::exception& e)`:

* Invalid bureaucrat or form grades
* Bureaucrat grade too low to sign or execute
* Unsigned form execution attempt (`FormNotSignedException`)

`signForm()` and `executeForm()` catch exceptions internally and display readable messages instead of crashing.

---

## 📂 **Code architecture and organization**

```
cpp05/
├── ex00/   Bureaucrat
├── ex01/   Bureaucrat + Form
├── ex02/   Bureaucrat + AForm + 3 concrete forms
├── ex03/   ex02 + Intern
├── subject.md
└── evaluation_sheet.md
```

#### 🔹 `Bureaucrat` (ex00 → ex03)

| Method | Description |
|--------|-------------|
| `Bureaucrat(name, grade)` | Constructs a bureaucrat; throws if grade ∉ [1, 150] |
| `getName()` / `getGrade()` | Accessors for constant name and mutable grade |
| `incrementGrade()` / `decrementGrade()` | Changes grade; throws at boundaries (1 and 150) |
| `signForm(AForm&)` | Calls `beSigned()`; prints signed / couldn't sign message (ex01+) |
| `executeForm(AForm const&)` | Calls `execute()`; prints executed / couldn't execute message (ex02+) |
| `operator<<` | Displays `<name>, bureaucrat grade <grade>.` |

#### 🔹 `Form` / `AForm` (ex01 / ex02+)

| Method | Description |
|--------|-------------|
| `beSigned(Bureaucrat const&)` | Signs if bureaucrat grade ≤ required sign grade; else throws |
| `execute(Bureaucrat const&)` | Checks signed + exec grade, then calls `executeAction()` (ex02+) |
| `getName()` / `getIsSigned()` / `getGradeToSign()` / `getGradeToExecute()` | Getters for private attributes |
| `executeAction()` | Pure virtual method implemented in concrete subclasses (ex02+) |
| `operator<<` | Displays name, signed state, and required grades |

#### 🔹 Concrete forms (ex02+)

| Class | Constructor | `executeAction()` |
|-------|-------------|-------------------|
| `ShrubberyCreationForm` | `ShrubberyCreationForm(target)` | Writes ASCII trees to `<target>_shrubbery` |
| `RobotomyRequestForm` | `RobotomyRequestForm(target)` | Drilling noise + random success/failure message |
| `PresidentialPardonForm` | `PresidentialPardonForm(target)` | Prints Zaphod Beeblebrox pardon message |

#### 🔹 `Intern` (ex03)

| Method | Description |
|--------|-------------|
| `makeForm(formName, target)` | Looks up `formName` in dispatch table; creates matching `AForm*` with `new` |
| `createShrubbery()` / `createRobotomy()` / `createPresidential()` | Private factory methods called via member function pointers |

**Known form names in `makeForm()`:**

* `"shrubbery creation"`
* `"robotomy request"`
* `"presidential pardon"`

#### 🔹 Exception classes

| Exception | Thrown when |
|-----------|-------------|
| `GradeTooHighException` | Grade < 1 (invalid construction or increment at grade 1) |
| `GradeTooLowException` | Grade > 150, or bureaucrat grade too low to sign/execute |
| `FormNotSignedException` | `execute()` called on an unsigned form |

Exception classes do **not** require OCF (as stated in the subject).

---

## 🏛 **Operating**

### 🔸 **The grade system (key trap)**

Grades are **inverted** compared to a school grade:

* **1** = highest rank (best bureaucrat)
* **150** = lowest rank (worst bureaucrat)

Therefore:

* `incrementGrade()` → grade number **decreases** (e.g. 3 → 2)
* A bureaucrat with grade **40** can sign a form requiring grade **50** (40 ≤ 50)
* A bureaucrat with grade **60** **cannot** sign a form requiring grade **50** (60 > 50)

### 🔸 **Exceptions in C++**

Unlike C error codes, C++ uses **exceptions** to handle exceptional cases:

```cpp
try
{
    Bureaucrat bob("Bob", 0); // throws GradeTooHighException
}
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

Custom exceptions inherit from `std::exception` and override `what()`.

### 🔸 **Orthodox Canonical Form (OCF)**

Every non-interface class must implement:

```cpp
ClassName();                              // Default constructor
ClassName(const ClassName& other);        // Copy constructor
ClassName& operator=(const ClassName&);   // Copy assignment
~ClassName();                             // Destructor
```

`const` members (e.g. `_name`) cannot be reassigned in `operator=` — only mutable members are copied.

### 🔸 **Inheritance and polymorphism (ex02+)**

`AForm` is an **abstract base class** with a pure virtual `executeAction()`. Concrete forms inherit from `AForm` and override this method.

`AForm::execute()` implements the **Template Method** pattern:

1. Check form is signed
2. Check executor grade is sufficient
3. Call `executeAction()` in the subclass

Because of polymorphism, `executeForm(AForm const&)` works on any concrete form through a base-class reference.

### 🔸 **Dynamic allocation (ex03)**

`Intern::makeForm()` returns `AForm*` allocated with `new`. The caller is responsible for `delete` to avoid memory leaks.

### 🔸 **Dispatch table (ex03)**

Instead of:

```cpp
if (name == "robotomy request") ...
else if (name == "shrubbery creation") ...
```

The project uses an array of `{ name, member_function_pointer }` pairs for clean, extensible dispatch.

---

## ⚙️ **Compiling and testing**

Each exercise is **independent** and has its own `Makefile`. Compile and run from the exercise directory.

### 🔧 Compiling

| Exercise | Binary | Command |
|----------|--------|---------|
| ex00 | `bureaucrat` | `cd ex00 && make` |
| ex01 | `form` | `cd ex01 && make` |
| ex02 | `forms` | `cd ex02 && make` |
| ex03 | `intern` | `cd ex03 && make` |

```bash
make        # compile
make re     # full rebuild
make fclean # remove binary, objects, and runtime files (*_shrubbery)
```

Compiler flags: `c++ -Wall -Wextra -Werror -std=c++98`

---

### ▶️ Use and execution

- #### ✅ Exercise 00 — `./bureaucrat`

  ```bash
  cd ex00 && make && ./bureaucrat
  ```

  Tests cover: valid/invalid grades, increment/decrement, exceptions, `operator<<`, OCF.

- #### ✅ Exercise 01 — `./form`

  ```bash
  cd ex01 && make && ./form
  ```

  Tests cover: all ex00 cases + `Form` creation, `beSigned()`, `signForm()` success and failure.

- #### ✅ Exercise 02 — `./forms`

  ```bash
  cd ex02 && make && ./forms
  ```

  Tests cover: ex00/ex01 behaviour + concrete forms, `execute()`, `executeForm()`, file creation (`home_shrubbery`).

  * Shrubbery creates a file in the working directory — removed by `make fclean`

- #### ✅ Exercise 03 — `./intern`

  ```bash
  cd ex03 && make && ./intern
  ```

  Tests cover: all previous cases + `Intern::makeForm()` for each form type, unknown form error, subject example (`"robotomy request"`, `"Bender"`).

  * Check memory leaks (macOS): `leaks -atExit -- ./intern`

#### Example — subject snippet (ex03)

```cpp
Intern  someRandomIntern;
AForm*  rrf;

rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// Output: Intern creates robotomy request
delete rrf;
```

---

<h1 align="center">
  <br>
  <img src="https://i.ibb.co/MkL14CvZ/logo-cpp-bonus.png" alt="logo C++" width="150">
  <br>
  cpp05
  <br>
</h1>

<h4 align="center"><em>Module C++ 05 — Répétition et exceptions : bureaucrates, formulaires et chaos administratif.</em></h4>

<p align="center">
  <img src="https://img.shields.io/badge/exercices-4-orange">
  <img src="https://img.shields.io/badge/C%2B%2B-100%25-blue">
  <img src="https://img.shields.io/badge/Note-100%2F100-brightgreen">
  <img src="https://img.shields.io/badge/standard-C%2B%2B98-informational">
</p>

<p align="center">
  <a href="./subject.md">Sujet</a> |
  <a href="#-aperçu-du-projet">Aperçu</a> •
  <a href="#-architecture-et-organisation-du-code">Architecture</a> •
  <a href="#-fonctionnement">Fonctionnement</a> •
  <a href="#%EF%B8%8F-compilation-et-tests">Compilation</a>
</p>

---

## 📌 **Aperçu du projet**

**cpp05** est le cinquième module C++ du Common Core de 42. Il introduit les **exceptions**, l'**héritage** et le **polymorphisme** à travers un système bureaucratique satirique : des `Bureaucrat`, des `Form` administratifs, et des `Intern` qui fabriquent la paperasse.

Le projet est découpé en **4 exercices**, chacun s'appuyant sur le précédent. Tout le code respecte le standard **C++98**.

### 1. Exercice 00 — Bureaucrat ✅

Un `Bureaucrat` possède un **nom constant** et un **grade** de **1** (le meilleur) à **150** (le pire).

* Les grades invalides lèvent `GradeTooHighException` ou `GradeTooLowException`
* `incrementGrade()` diminue le numéro de grade (meilleur rang) ; `decrementGrade()` l'augmente
* `operator<<` affiche : `<name>, bureaucrat grade <grade>.`
* **Orthodox Canonical Form** (OCF) complète

### 2. Exercice 01 — Form ✅

Ajoute une classe `Form` avec des attributs privés :

* Nom constant, état signé (`bool`), grades requis pour signer et exécuter
* `beSigned(Bureaucrat)` signe si le grade du bureaucrate est suffisant
* `Bureaucrat::signForm(Form)` appelle `beSigned()` et affiche un message de succès ou d'échec

### 3. Exercice 02 — Formes concrètes ✅

Renomme `Form` en **`AForm`** (classe de base abstraite) et ajoute trois formes concrètes :

| Forme | Grade sign | Grade exec | Action |
|-------|------------|------------|--------|
| `ShrubberyCreationForm` | 145 | 137 | Crée `<target>_shrubbery` avec des arbres ASCII |
| `RobotomyRequestForm` | 72 | 45 | Bruit de perceuse + 50 % de succès |
| `PresidentialPardonForm` | 25 | 5 | Pardonne `<target>` via Zaphod Beeblebrox |

* `AForm::execute(Bureaucrat const&)` vérifie la signature et le grade, puis appelle `executeAction()` dans les sous-classes
* `Bureaucrat::executeForm(AForm const&)` tente l'exécution avec des messages d'erreur explicites

### 4. Exercice 03 — Intern ✅

La classe `Intern` n'a ni nom ni grade. Son seul rôle est `makeForm(formName, target)` :

* Retourne un `AForm*` alloué dynamiquement (`new`)
* Affiche `Intern creates <form>` en cas de succès
* Utilise un **tableau de dispatch propre** (pointeurs de fonctions membres), pas de longues chaînes `if/else`
* Retourne `NULL` et affiche une erreur pour les noms inconnus

### Gestion des erreurs ⚠️

Les exceptions héritent de `std::exception` et sont attrapables via `catch (std::exception& e)` :

* Grades invalides (bureaucrate ou formulaire)
* Grade du bureaucrate trop bas pour signer ou exécuter
* Tentative d'exécution d'un formulaire non signé (`FormNotSignedException`)

`signForm()` et `executeForm()` attrapent les exceptions en interne et affichent des messages lisibles au lieu de crasher.

---

## 📂 **Architecture et organisation du code**

```
cpp05/
├── ex00/   Bureaucrat
├── ex01/   Bureaucrat + Form
├── ex02/   Bureaucrat + AForm + 3 formes concrètes
├── ex03/   ex02 + Intern
├── subject.md
└── evaluation_sheet.md
```

#### 🔹 `Bureaucrat` (ex00 → ex03)

| Méthode | Description |
|---------|-------------|
| `Bureaucrat(name, grade)` | Construit un bureaucrate ; throw si grade ∉ [1, 150] |
| `getName()` / `getGrade()` | Accesseurs pour le nom constant et le grade modifiable |
| `incrementGrade()` / `decrementGrade()` | Modifie le grade ; throw aux bornes (1 et 150) |
| `signForm(AForm&)` | Appelle `beSigned()` ; affiche signed / couldn't sign (ex01+) |
| `executeForm(AForm const&)` | Appelle `execute()` ; affiche executed / couldn't execute (ex02+) |
| `operator<<` | Affiche `<name>, bureaucrat grade <grade>.` |

#### 🔹 `Form` / `AForm` (ex01 / ex02+)

| Méthode | Description |
|---------|-------------|
| `beSigned(Bureaucrat const&)` | Signe si grade bureaucrate ≤ grade requis ; sinon throw |
| `execute(Bureaucrat const&)` | Vérifie signature + grade exec, puis appelle `executeAction()` (ex02+) |
| `getName()` / `getIsSigned()` / `getGradeToSign()` / `getGradeToExecute()` | Getters pour attributs privés |
| `executeAction()` | Méthode pure virtuelle implémentée dans les sous-classes (ex02+) |
| `operator<<` | Affiche nom, état signé et grades requis |

#### 🔹 Formes concrètes (ex02+)

| Classe | Constructeur | `executeAction()` |
|--------|--------------|-------------------|
| `ShrubberyCreationForm` | `ShrubberyCreationForm(target)` | Écrit des arbres ASCII dans `<target>_shrubbery` |
| `RobotomyRequestForm` | `RobotomyRequestForm(target)` | Bruit de perceuse + message succès/échec aléatoire |
| `PresidentialPardonForm` | `PresidentialPardonForm(target)` | Affiche le message de pardon de Zaphod Beeblebrox |

#### 🔹 `Intern` (ex03)

| Méthode | Description |
|---------|-------------|
| `makeForm(formName, target)` | Cherche `formName` dans le tableau de dispatch ; crée le `AForm*` avec `new` |
| `createShrubbery()` / `createRobotomy()` / `createPresidential()` | Méthodes factory privées appelées via pointeurs de fonctions membres |

**Noms de formulaires reconnus par `makeForm()` :**

* `"shrubbery creation"`
* `"robotomy request"`
* `"presidential pardon"`

#### 🔹 Classes d'exception

| Exception | Levée quand |
|-----------|-------------|
| `GradeTooHighException` | Grade < 1 (construction invalide ou increment au grade 1) |
| `GradeTooLowException` | Grade > 150, ou grade bureaucrate trop bas pour signer/exécuter |
| `FormNotSignedException` | `execute()` appelé sur un formulaire non signé |

Les classes d'exception n'ont **pas** besoin de l'OCF (comme indiqué dans le sujet).

---

## 🏛 **Fonctionnement**

### 🔸 **Le système de grades (piège du sujet)**

Les grades sont **inversés** par rapport à une note scolaire :

* **1** = rang le plus élevé (meilleur bureaucrate)
* **150** = rang le plus bas (pire bureaucrate)

Donc :

* `incrementGrade()` → le numéro de grade **diminue** (ex. 3 → 2)
* Un bureaucrate grade **40** peut signer un formulaire exigeant le grade **50** (40 ≤ 50)
* Un bureaucrate grade **60** **ne peut pas** signer un formulaire exigeant le grade **50** (60 > 50)

### 🔸 **Les exceptions en C++**

Contrairement aux codes d'erreur en C, le C++ utilise des **exceptions** pour les cas exceptionnels :

```cpp
try
{
    Bureaucrat bob("Bob", 0); // throw GradeTooHighException
}
catch (std::exception& e)
{
    std::cout << e.what() << std::endl;
}
```

Les exceptions personnalisées héritent de `std::exception` et redéfinissent `what()`.

### 🔸 **Orthodox Canonical Form (OCF)**

Chaque classe non-interface doit implémenter :

```cpp
ClassName();                              // Constructeur par défaut
ClassName(const ClassName& other);        // Constructeur de copie
ClassName& operator=(const ClassName&);   // Opérateur d'affectation
~ClassName();                             // Destructeur
```

Les membres `const` (ex. `_name`) ne peuvent pas être réassignés dans `operator=` — seuls les membres modifiables sont copiés.

### 🔸 **Héritage et polymorphisme (ex02+)**

`AForm` est une **classe de base abstraite** avec une `executeAction()` pure virtuelle. Les formes concrètes héritent de `AForm` et redéfinissent cette méthode.

`AForm::execute()` implémente le pattern **Template Method** :

1. Vérifier que le formulaire est signé
2. Vérifier que le grade de l'exécuteur est suffisant
3. Appeler `executeAction()` dans la sous-classe

Grâce au polymorphisme, `executeForm(AForm const&)` fonctionne sur toute forme concrète via une référence de classe de base.

### 🔸 **Allocation dynamique (ex03)**

`Intern::makeForm()` retourne un `AForm*` alloué avec `new`. L'appelant doit faire `delete` pour éviter les fuites mémoire.

### 🔸 **Tableau de dispatch (ex03)**

Au lieu de :

```cpp
if (name == "robotomy request") ...
else if (name == "shrubbery creation") ...
```

Le projet utilise un tableau de paires `{ nom, pointeur_fonction_membre }` pour un dispatch propre et extensible.

---

## ⚙️ **Compilation et tests**

Chaque exercice est **indépendant** et possède son propre `Makefile`. Compiler et exécuter depuis le dossier de l'exercice.

### 🔧 Compilation

| Exercice | Binaire | Commande |
|----------|---------|----------|
| ex00 | `bureaucrat` | `cd ex00 && make` |
| ex01 | `form` | `cd ex01 && make` |
| ex02 | `forms` | `cd ex02 && make` |
| ex03 | `intern` | `cd ex03 && make` |

```bash
make        # compiler
make re     # recompilation complète
make fclean # supprime binaire, objets et fichiers runtime (*_shrubbery)
```

Flags : `c++ -Wall -Wextra -Werror -std=c++98`

---

### ▶️ Utilisation et exécution

- #### ✅ Exercice 00 — `./bureaucrat`

  ```bash
  cd ex00 && make && ./bureaucrat
  ```

  Tests : grades valides/invalides, increment/decrement, exceptions, `operator<<`, OCF.

- #### ✅ Exercice 01 — `./form`

  ```bash
  cd ex01 && make && ./form
  ```

  Tests : tout ex00 + création `Form`, `beSigned()`, `signForm()` succès et échec.

- #### ✅ Exercice 02 — `./forms`

  ```bash
  cd ex02 && make && ./forms
  ```

  Tests : comportements ex00/ex01 + formes concrètes, `execute()`, `executeForm()`, création de fichier (`home_shrubbery`).

  * Shrubbery crée un fichier dans le répertoire courant — supprimé par `make fclean`

- #### ✅ Exercice 03 — `./intern`

  ```bash
  cd ex03 && make && ./intern
  ```

  Tests : tous les cas précédents + `Intern::makeForm()` pour chaque type, erreur nom inconnu, exemple du sujet (`"robotomy request"`, `"Bender"`).

  * Vérifier les fuites mémoire (macOS) : `leaks -atExit -- ./intern`

#### Exemple — extrait du sujet (ex03)

```cpp
Intern  someRandomIntern;
AForm*  rrf;

rrf = someRandomIntern.makeForm("robotomy request", "Bender");
// Sortie : Intern creates robotomy request
delete rrf;
```
