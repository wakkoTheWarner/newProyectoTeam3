/**
 * Objetivo: Esta clase Student se utiliza para representar a un estudiante con varios atributos como número, nombre, identificación del
 *           estudiante, estado de registro, nivel, créditos, calificación de mitad de período, calificación final y detalles de la calificación.
 *           Proporciona métodos para obtener y establecer estos atributos.
 *
 * Precondiciones: Para el constructor de `Student`, todos los parámetros proporcionados deben ser válidos y no nulos.
 *                 Para los métodos `set`, los valores proporcionados deben ser válidos y no nulos.
 *
 * Postcondiciones: Después de la construcción, se crea un objeto `Student` con los atributos proporcionados.
 *                  Los métodos `get` devuelven el valor actual del atributo correspondiente.
 *                  Los métodos `set` actualizan el valor del atributo correspondiente.
 *
 * Descripción de argumentos:
 *                 num: Un entero que representa el número del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getNum y setNum.
 *                 name: Una cadena que representa el nombre del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getName y setName.
 *                 studentId: Una cadena que representa la ID del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getId y setId.
 *                 registrationStatus: Una cadena que representa el estado de registro del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getRegistrationStatus y setRegistrationStatus.
 *                 level: Una cadena que representa el nivel del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getLevel y setLevel.
 *                 credits: Una cadena que representa los créditos del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getCredits y setCredits.
 *                 midterm: Una cadena que representa la calificación de mitad de período del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getMidterm y setMidterm.
 *                 final: Una cadena que representa la calificación final del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getFinal y setFinal.
 *                 gradeDetail: Una cadena que representa los detalles de la calificación del estudiante. Este es tanto un parámetro para el constructor como el sujeto de los métodos getGradeDetail y setGradeDetail.
 *
 * Autor: Eduardo A. Sosa Torres
 * Fecha de finalización: 28-02-2024
 **/

#include "Students.h"

Student::Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail)
        : num(num), name(name), studentId(studentId), registrationStatus(registrationStatus), level(level), credits(credits), midterm(midterm), final(final), gradeDetail(gradeDetail) {
    // Constructor de la clase Student. Inicializa todos los atributos con los valores proporcionados.
}

int Student::getNum() const {
    // Devuelve el número del estudiante.
    return num;
}

void Student::setNum(int num) {
    // Establece el número del estudiante.
    Student::num = num;
}

const std::string &Student::getName() const {
    // Devuelve el nombre del estudiante.
    return name;
}

void Student::setName(const std::string &name) {
    // Establece el nombre del estudiante.
    Student::name = name;
}

const std::string &Student::getId() const {
    // Devuelve la identificación del estudiante.
    return studentId;
}

void Student::setId(const std::string &id) {
    // Establece la identificación del estudiante.
    Student::studentId = id;
}

const std::string &Student::getRegistrationStatus() const {
    // Devuelve el estado de registro del estudiante.
    return registrationStatus;
}

void Student::setRegistrationStatus(const std::string &registrationStatus) {
    // Establece el estado de registro del estudiante.
    Student::registrationStatus = registrationStatus;
}

const std::string &Student::getLevel() const {
    // Devuelve el nivel del estudiante.
    return level;
}

void Student::setLevel(const std::string &level) {
    // Establece el nivel del estudiante.
    Student::level = level;
}

const std::string &Student::getCredits() const {
    // Devuelve los créditos del estudiante.
    return credits;
}

void Student::setCredits(const std::string &credits) {
    // Establece los créditos del estudiante.
    Student::credits = credits;
}

const std::string &Student::getMidterm() const {
    // Devuelve la calificación de mitad de período del estudiante.
    return midterm;
}

void Student::setMidterm(const std::string &midterm) {
    // Establece la calificación de mitad de período del estudiante.
    Student::midterm = midterm;
}

const std::string &Student::getFinal() const {
    // Devuelve la calificación final del estudiante.
    return final;
}

void Student::setFinal(const std::string &final) {
    // Establece la calificación final del estudiante.
    Student::final = final;
}

const std::string &Student::getGradeDetail() const {
    // Devuelve los detalles de la calificación del estudiante.
    return gradeDetail;
}

void Student::setGradeDetail(const std::string &gradeDetail) {
    // Establece los detalles de la calificación del estudiante.
    Student::gradeDetail = gradeDetail;
}
