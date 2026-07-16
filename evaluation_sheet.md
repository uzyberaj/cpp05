# Scale for Project CPP Module 05

## Introduction

You should evaluate **1 student** in this team.

### Please comply with the following rules

- Remain polite, courteous, respectful, and constructive throughout
the evaluation process. The well-being of the community depends on
it.
- Identify with the student or group whose work is evaluated the
possible dysfunctions in their project. Take the time to discuss and
debate the problems that may have been identified.
- You must consider that there might be some differences in how your
peers might have understood the project's instructions and the scope
of its functionalities. Always keep an open mind and grade them as
honestly as possible. The pedagogy is useful only if the peer
evaluation is done seriously.

## Guidelines

- Only grade the work that was turned in the Git repository of the
evaluated student or group.
- Double-check that the Git repository belongs to the student(s).
Ensure that the project is the one expected. Also, check that
`git clone` is used in an empty folder.
- Check carefully that no malicious aliases were used to fool you and
make you evaluate something that is not the content of the official
repository.
- To avoid any surprises and, if applicable, review together any
scripts used to facilitate the grading (testing or automation).
- If you have not completed the assignment you are going to evaluate,
read the entire subject before starting the evaluation.
- Use the available flags to report:
  - Empty repository
  - Non-functioning program
  - Norm error
  - Cheating
  - Any other blocking issue

> In these cases, the evaluation process ends and the final grade is
> **0** (or **-42** in case of cheating). Except for cheating, students
> are strongly encouraged to review the submitted work together to
> identify mistakes.

- Never edit any file except the configuration file (if it exists). If
you need to edit a file, explain why and ensure both parties agree.
- Verify the absence of memory leaks. Any heap allocation must be
freed before program termination. You may use tools such as `leaks`,
`valgrind`, or `e_fence`.

## Attachments

- `subject.pdf`

---

# Preliminary Tests

> **If cheating is suspected, stop the evaluation immediately and use
> the "Cheat" flag.**

## Prerequisites

The code must:

- Compile with `c++`
- Use the flags `-Wall -Wextra -Werror`
- Respect the **C++98** standard (no C++11 or later features)

### Do **not** grade the exercise if:

- A non-template function is implemented in a header file.
- The Makefile does not use the required flags or does not compile
with `c++`.

### Flag as **Forbidden Function** if any of the following are used:

- C functions (`*alloc`, `*printf`, `free`)
- Any forbidden function
- `using namespace <ns_name>`
- `friend`
- External libraries
- Features newer than C++98

- [ ] Yes
- [ ] No

---

# Ex00: Mommy, when I grow up, I want to be a bureaucrat!

> A `main()` with sufficient tests is required. Otherwise, **do not
> grade**.

> Every non-interface class must follow the Orthodox Canonical Form.

## Bureaucrat

- [ ] Makefile uses the required flags.

- [ ] `Bureaucrat` class exists.

- [ ] Constant name.

- [ ] Grade ranges from **1 (highest)** to **150 (lowest)**.

- [ ] Exceptions are thrown for invalid grades.

- [ ] Accessors exist.

- [ ] Grade increment/decrement functions exist.

- [ ] Exceptions are thrown when appropriate.

- [ ] Exceptions derive from `std::exception`.

- [ ] `operator<<` is overloaded.

- [ ] Yes

- [ ] No

---

# Ex01: Form up, maggots!

> A `main()` with sufficient tests is required.

> Every non-interface class must follow the Orthodox Canonical Form.

## Form

- [ ] Makefile uses the required flags.

- [ ] `Form` class exists.

- [ ] Has:
  - Constant name
  - Signed state (`bool`)
  - Constant grade required to sign
  - Constant grade required to execute

- [ ] All attributes are **private**.

- [ ] Grade constraints are respected.

- [ ] Accessors exist.

- [ ] `operator<<` is overloaded.

- [ ] `Form::beSigned()` behaves correctly.

- [ ] `Bureaucrat::signForm()` behaves correctly.

- [ ] Yes

- [ ] No

---

# Ex02: No, you need form 28B, not 28C...

> A `main()` with sufficient tests is required.

> Every non-interface class must follow the Orthodox Canonical Form.

## Forms that actually do something

- [ ] Makefile uses the required flags.

- [ ] Concrete forms match the subject.

- [ ] Constructor takes only the target.

- [ ] `Form::execute(Bureaucrat const&)` behaves correctly.

- [ ] Execution architecture is valid:
  - Pure virtual execute in subclasses **or**
  - Common checks in base class followed by subclass action.

- [ ] `Bureaucrat::executeForm()` behaves correctly.

- [ ] Yes

- [ ] No

---

# Ex03: At least this beats coffee-making

> A `main()` with sufficient tests is required.

> Every non-interface class must follow the Orthodox Canonical Form.

## Intern

- [ ] Makefile uses the required flags.

- [ ] `Intern` class exists.

- [ ] `makeForm()` behaves correctly.

- [ ] Yes

- [ ] No

## Good dispatching

The `makeForm()` function should use an **array of pointers to member
functions** (or an equivalent clean dispatch mechanism).

If it relies on long `if / else if / else` chains or another unclean
implementation, mark this section as incorrect.

- [ ] Yes
- [ ] No