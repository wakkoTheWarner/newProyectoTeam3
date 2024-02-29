/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#ifndef NEWPROYECTOTEAM3_STUDENTS_H
#define NEWPROYECTOTEAM3_STUDENTS_H


#include <string>

class Student {
public:
    Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail);

    int getNum() const;

    void setNum(int num);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getId() const;

    void setId(const std::string &id);

    const std::string &getRegistrationStatus() const;

    void setRegistrationStatus(const std::string &registrationStatus);

    const std::string &getLevel() const;

    void setLevel(const std::string &level);

    const std::string &getCredits() const;

    void setCredits(const std::string &credits);

    const std::string &getMidterm() const;

    void setMidterm(const std::string &midterm);

    const std::string &getFinal() const;

    void setFinal(const std::string &final);

    const std::string &getGradeDetail() const;

    void setGradeDetail(const std::string &gradeDetail);

private:
    int num;
    std::string name;
    std::string studentId;
    std::string registrationStatus;
    std::string level;
    std::string credits;
    std::string midterm;
    std::string final;
    std::string gradeDetail;
};


#endif //NEWPROYECTOTEAM3_STUDENTS_H
