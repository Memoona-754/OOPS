//CT 166            MEMOONA 
#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string name;
    int age;
    string institute;

public:
    // Setters
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setInstitute(string i) {
        institute = i;
    }

    // Getters
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getInstitute() {
        return institute;
    }
};
class HumanitiesTeacher : public Teacher {
private:
    string department;
    string courseName;
    string designation;

public:
    HumanitiesTeacher() {
        department = "Humanities";
    }

    void setCourseName(string c) {
        courseName = c;
    }

    void setDesignation(string d) {
        designation = d;
    }

    string getDepartment() {
        return department;
    }

    string getCourseName() {
        return courseName;
    }

    string getDesignation() {
        return designation;
    }
};
class ScienceTeacher : public Teacher {
private:
    string department;
    string courseName;
    string designation;

public:
    ScienceTeacher() {
        department = "Science";
    }

    void setCourseName(string c) {
        courseName = c;
    }

    void setDesignation(string d) {
        designation = d;
    }

    string getDepartment() {
        return department;
    }

    string getCourseName() {
        return courseName;
    }

    string getDesignation() {
        return designation;
    }
};
class MathsTeacher : public Teacher {
private:
    string department;
    string courseName;
    string designation;

public:
    MathsTeacher() {
        department = "Maths";
    }

    void setCourseName(string c) {
        courseName = c;
    }

    void setDesignation(string d) {
        designation = d;
    }

    string getDepartment() {
        return department;
    }

    string getCourseName() {
        return courseName;
    }

    string getDesignation() {
        return designation;
    }
};
int main() {
    HumanitiesTeacher ht;
    ScienceTeacher st;
    MathsTeacher mt;

    // Humanities Teacher
    ht.setName("Ali");
    ht.setAge(40);
    ht.setInstitute("NED University");
    ht.setCourseName("History");
    ht.setDesignation("Lecturer");

    // Science Teacher
    st.setName("Sara");
    st.setAge(35);
    st.setInstitute("NED University");
    st.setCourseName("Physics");
    st.setDesignation("Assistant Professor");

    // Maths Teacher
    mt.setName("Ahmed");
    mt.setAge(45);
    mt.setInstitute("NED University");
    mt.setCourseName("Calculus");
    mt.setDesignation("Professor");

    // Display Output
    cout << "\n--- Humanities Teacher ---\n";
    cout << "Name: " << ht.getName() << endl;
    cout << "Age: " << ht.getAge() << endl;
    cout << "Institute: " << ht.getInstitute() << endl;
    cout << "Department: " << ht.getDepartment() << endl;
    cout << "Course: " << ht.getCourseName() << endl;
    cout << "Designation: " << ht.getDesignation() << endl;

    cout << "\n--- Science Teacher ---\n";
    cout << "Name: " << st.getName() << endl;
    cout << "Age: " << st.getAge() << endl;
    cout << "Institute: " << st.getInstitute() << endl;
    cout << "Department: " << st.getDepartment() << endl;
    cout << "Course: " << st.getCourseName() << endl;
    cout << "Designation: " << st.getDesignation() << endl;

    cout << "\n--- Maths Teacher ---\n";
    cout << "Name: " << mt.getName() << endl;
    cout << "Age: " << mt.getAge() << endl;
    cout << "Institute: " << mt.getInstitute() << endl;
    cout << "Department: " << mt.getDepartment() << endl;
    cout << "Course: " << mt.getCourseName() << endl;
    cout << "Designation: " << mt.getDesignation() << endl;

    return 0;
}










