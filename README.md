# CPP05 - Exception Handling and Form Processing

This project explores exception handling in C++ through the implementation of a bureaucratic form system. It covers custom exceptions, inheritance, abstract classes, and polymorphism.

## Project Structure

### ex00 - Bureaucrat
Basic implementation of a `Bureaucrat` class with grade validation.
- Grade range: 1 (highest) to 150 (lowest)
- Custom exceptions: `GradeTooHighException` and `GradeTooLowException`
- Grade increment/decrement with exception handling

**Compilation:**
```bash
cd ex00 && make
```

### ex01 - Form
Introduction of a `Form` class that requires bureaucrat signatures.
- Forms have sign and execution grade requirements
- Bureaucrats can sign forms if their grade is sufficient
- Exception handling for grade requirements

**Compilation:**
```bash
cd ex01 && make
```

### ex02 - Concrete Forms
Implementation of specific form types using inheritance:
- **ShrubberyCreationForm**: Creates ASCII trees in files (sign: 145, exec: 137)
- **RobotomyRequestForm**: 50% chance robotomy success (sign: 72, exec: 45)
- **PresidentialPardonForm**: Presidential pardon (sign: 25, exec: 5)

Abstract base class `AForm` with concrete implementations.

**Compilation:**
```bash
cd ex02 && make
```

### ex03 - Intern
Implementation of an `Intern` class that can create forms by name.
- Factory pattern for form creation
- Dynamic form instantiation based on string input

**Compilation:**
```bash
cd ex03 && make
```

## Key Concepts Covered

- **Exception Handling**: Custom exception classes and proper exception propagation
- **Abstract Classes**: Pure virtual functions and abstract base classes
- **Polymorphism**: Virtual functions and runtime polymorphism
- **RAII**: Resource management through constructors and destructors
- **Orthodox Canonical Form**: Copy constructor, assignment operator, destructor
- **Factory Pattern**: Dynamic object creation (ex03)

## Usage Example

```cpp
try {
    Bureaucrat bob("Bob", 1);
    ShrubberyCreationForm form("home");
    
    bob.signForm(form);
    bob.executeForm(form);
} catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
}
```

## Author
Henna Parveen