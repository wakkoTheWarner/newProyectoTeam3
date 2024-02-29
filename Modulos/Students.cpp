/**
 * Objetivo:
 * Precondiciones:
 * Postcondiciones:
 * Autor:
 * Fecha de finalización:
 **/

#include "Students.h"

Student::Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail)
        : num(num), name(name), studentId(studentId), registrationStatus(registrationStatus), level(level), credits(credits), midterm(midterm), final(final), gradeDetail(gradeDetail) {}

int Student::getNum() const {
    return num;
}

void Student::setNum(int num) {
    Student::num = num;
}

const std::string &Student::getName() const {
    return name;
}

void Student::setName(const std::string &name) {
    Student::name = name;
}

const std::string &Student::getId() const {
    return studentId;
}

void Student::setId(const std::string &id) {
    Student::studentId = id;
}

const std::string &Student::getRegistrationStatus() const {
    return registrationStatus;
}

void Student::setRegistrationStatus(const std::string &registrationStatus) {
    Student::registrationStatus = registrationStatus;
}

const std::string &Student::getLevel() const {
    return level;
}

void Student::setLevel(const std::string &level) {
    Student::level = level;
}

const std::string &Student::getCredits() const {
    return credits;
}

void Student::setCredits(const std::string &credits) {
    Student::credits = credits;
}

const std::string &Student::getMidterm() const {
    return midterm;
}

void Student::setMidterm(const std::string &midterm) {
    Student::midterm = midterm;
}

const std::string &Student::getFinal() const {
    return final;
}

void Student::setFinal(const std::string &final) {
    Student::final = final;
}

const std::string &Student::getGradeDetail() const {
    return gradeDetail;
}

void Student::setGradeDetail(const std::string &gradeDetail) {
    Student::gradeDetail = gradeDetail;
}
