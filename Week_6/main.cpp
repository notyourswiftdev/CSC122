#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ctime>

class Person {
public:
    Person(std::string name, std::string ssn, std::string birthdate)
        : name_(name), ssn_(ssn), birthdate_(birthdate) {}

    virtual std::string category() const = 0; // pure virtual function

    std::string name() const { return name_; }
    std::string ssn() const { return ssn_; }
    std::string birthdate() const { return birthdate_; }

    void set_name(std::string name) { name_ = name; }
    void set_ssn(std::string ssn) { ssn_ = ssn; }
    void set_birthdate(std::string birthdate) { birthdate_ = birthdate; }

private:
    std::string name_;
    std::string ssn_;
    std::string birthdate_;
};

class Laborer : public Person {
public:
    Laborer(std::string name, std::string ssn, std::string birthdate,
            std::string job, std::string employee_id, double hourly_salary, double hours_worked)
        : Person(name, ssn, birthdate), job_(job), employee_id_(employee_id),
        hourly_salary_(hourly_salary), hours_worked_(hours_worked) {}

    virtual std::string category() const override { return "Laborer"; }

    std::string job() const { return job_; }
    std::string employee_id() const { return employee_id_; }
    double hourly_salary() const { return hourly_salary_; }
    double hours_worked() const { return hours_worked_; }

    void set_job(std::string job) { job_ = job; }
    void set_employee_id(std::string employee_id) { employee_id_ = employee_id; }
    void set_hourly_salary(double hourly_salary) { hourly_salary_ = hourly_salary; }
    void set_hours_worked(double hours_worked) { hours_worked_ = hours_worked; }

private:
    std::string job_;
    std::string employee_id_;
    double hourly_salary_;
    double hours_worked_;
};

class Manager : public Person {
public:
    Manager(std::string name, std::string ssn, std::string birthdate, std::string department, std::string employee_id, double salary)
        : Person(name, ssn, birthdate), department_(department), employee_id_(employee_id), salary_(salary) {}

    virtual std::string category() const override { return "Manager"; }

    std::string department() const { return department_; }
    std::string employee_id() const { return employee_id_; }
    double salary() const { return salary_; }

    void set_department(std::string department) { department_ = department; }
    void set_employee_id(std::string employee_id) { employee_id_ = employee_id; }
    void set_salary(double salary) { salary_ = salary; }

private:
    std::string department_;
    std::string employee_id_;
    double salary_;
};

class Owner : public Person {
public:
    Owner(std::string name, std::string ssn, std::string birthdate, double percent_ownership, std::string ownership_start_date)
        : Person(name, ssn, birthdate), percent_ownership_(percent_ownership), ownership_start_date_(ownership_start_date) {}

    virtual std::string category() const override { return "Owner"; }

    double percent_ownership() const { return percent_ownership_; }
    std::string ownership_start_date() const { return ownership_start_date_; }

    void set_percent_ownership(double percent_ownership) { percent_ownership_ = percent_ownership; }
    void set_ownership_start_date(std::string ownership_start_date) { ownership_start_date_ = ownership_start_date; }

private:
    double percent_ownership_;
    std::string ownership_start_date_;
};

// function to display vector of persons
void display_persons(const std::vector<Person*>& persons) {
    std::cout << std::left << std::setw(15) << "Category"
              << std::setw(15) << "Name"
              << std::setw(15) << "SSN"
              << std::setw(15) << "Birthdate"
              << std::setw(15) << "Extra Info" << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    for (const auto& person : persons) {
        std::cout << std::setw(15) << person->category()
                  << std::setw(15) << person->name()
                  << std::setw(15) << person->ssn()
                  << std::setw(15) << person->birthdate();
        if (person->category() == "Laborer") {
            Laborer* laborer = dynamic_cast<Laborer*>(person);
            std::cout << std::setw(15) << laborer->job()
                      << std::setw(15) << laborer->employee_id()
                      << std::setw(15) << laborer->hourly_salary()
                      << std::setw(15) << laborer->hours_worked();
        } else if (person->category() == "Manager") {
            Manager* manager = dynamic_cast<Manager*>(person);
            std::cout << std::setw(15) << manager->department()
                      << std::setw(15) << manager->employee_id()
                      << std::setw(15) << manager->salary();
        } else if (person->category() == "Owner") {
            Owner* owner = dynamic_cast<Owner*>(person);
            std::cout << std::setw(15) << owner->percent_ownership()
                      << std::setw(15) << owner->ownership_start_date();
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<Person*> persons;

    while (true) {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Add laborer" << std::endl;
        std::cout << "2. Add manager" << std::endl;
        std::cout << "3. Add owner" << std::endl;
        std::cout << "4. Display all" << std::endl;
        std::cout << "5. Quit" << std::endl;

        int option;
        std::cin >> option;

        if (option == 1) {
            std::string name, ssn, birthdate, job, employee_id;
            double hourly_salary, hours_worked;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter SSN: ";
            std::cin >> ssn;
            std::cout << "Enter birthdate (YYYY-MM-DD): ";
            std::cin >> birthdate;
            std::cout << "Enter job: ";
            std::cin >> job;
            std::cout << "Enter employee ID: ";
            std::cin >> employee_id;
            std::cout << "Enter hourly salary: ";
            std::cin >> hourly_salary;
            std::cout << "Enter hours worked: ";
            std::cin >> hours_worked;

            Laborer* laborer = new Laborer(name, ssn, birthdate, job, employee_id, hourly_salary, hours_worked);
            persons.push_back(laborer);
        } else if (option == 2) {
            std::string name, ssn, birthdate, department, employee_id;
            double salary;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter SSN: ";
            std::cin >> ssn;
            std::cout << "Enter birthdate (YYYY-MM-DD): ";
            std::cin >> birthdate;
            std::cout << "Enter department: ";
            std::cin >> department;
            std::cout << "Enter employee ID: ";
            std::cin >> employee_id;
            std::cout << "Enter salary: ";
            std::cin >> salary;

            Manager* manager = new Manager(name, ssn, birthdate, department, employee_id, salary);
            persons.push_back(manager);
        } else if (option == 3) {
            std::string name, ssn, birthdate, ownership_start_date;
            double percent_ownership;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter SSN: ";
            std::cin >> ssn;
            std::cout << "Enter birthdate (YYYY-MM-DD): ";
            std::cin >> birthdate;
            std::cout << "Enter percent ownership: ";
            std::cin >> percent_ownership;
            std::cout << "Enter ownership start date (YYYY-MM-DD): ";
            std::cin >> ownership_start_date;

            Owner* owner = new Owner(name, ssn, birthdate, percent_ownership, ownership_start_date);
            persons.push_back(owner);
        } else if (option == 4) {
            display_persons(persons);
        } else if (option == 5) {
            break;
        } else {
            std::cout << "Invalid option. Try again." << std::endl;
        }
    }

    // free memory
    for (const auto& person : persons) {
        delete person;
    }

    return 0;
}