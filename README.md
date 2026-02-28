# 🏥 Hospital Management & Research System

A robust C++ application designed to simulate the management of a hospital and its research institute. This project demonstrates high-level Object-Oriented Programming (OOP) principles, memory management, and modern C++ practices.

## 🌟 Key Features

### Hospital Operations
* **Department Management:** Organize the hospital into specialized departments (e.g., Neurology, ER).
* **Staff Management:** Manage a diverse workforce including Doctors, Nurses, and Maintenance staff.
* **Patient Care:** Handle patient admissions, assign caregivers, and track visits.
* **Surgeries:** Schedule and manage surgeries with specific requirements (fasting, room allocation).

### Research Center
* **Academic Research:** Manage a Research Center linked to the hospital.
* **Publication Tracking:** Researchers can publish and store articles.
* **The "Doctor-Researcher":** A unique entity that functions as both a medical doctor and an academic researcher, solving the C++ "Diamond Inheritance" problem.

## 🛠️ Technical Highlights

This project showcases several advanced C++ concepts:

* **OOP Fundamentals:** Encapsulation, Inheritance, and Polymorphism.
* **Advanced Inheritance:** Implementation of **Virtual Inheritance** to resolve the Diamond Problem (`Person` -> `Doctor`/`Researcher` -> `DoctorResearcher`).
* **STL Integration:** Extensive use of `std::vector` and `std::string` to replace legacy C-style arrays and manual memory management (`char*`).
* **Memory Management:** implementation of Move Semantics (Move Constructors & Assignment Operators) for performance, alongside RAII principles.
* **RTTI:** Usage of `dynamic_cast` for runtime type identification (e.g., checking if a caregiver is a Surgeon).
* **Operator Overloading:** Custom I/O operators (`<<`, `>>`) for all entities.

## 📂 Class Structure

* **`Person`**: Base abstract class for all humans in the system.
* **`Worker`**: Inherits from Person. Base for all employees.
* **`Patient`**: Inherits from Person. Represents a patient in a department.
* **`Doctor` / `Researcher`**: Virtual inheritance from `Worker`.
* **`DoctorResearcher`**: Inherits from both `Doctor` and `Researcher`.
* **`Department`**: Manages a list of patients and assigned doctors.
* **`Hospital`**: The main controller class (Singleton-like behavior) managing all departments.
* **`ResearchCenter`**: Manages researchers and their articles.

## 🚀 Getting Started

### Prerequisites
* A C++ Compiler (GCC, Clang, or MSVC) supporting C++11 or higher.

### Compilation
You can compile the project using g++:

```bash
g++ -o hospital_system main.cpp Hospital.cpp Person.cpp Worker.cpp Doctor.cpp Nurse.cpp Researcher.cpp DoctorResearcher.cpp Article.cpp Department.cpp ResearchCenter.cpp Visit.cpp Surgery.cpp Date.cpp -std=c++14
