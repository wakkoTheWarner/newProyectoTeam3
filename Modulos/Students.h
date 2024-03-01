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

#ifndef NEWPROYECTOTEAM3_STUDENTS_H
#define NEWPROYECTOTEAM3_STUDENTS_H


#include <string>

class Student {
public:
    // Constructor de la clase Student. Inicializa todos los atributos con los valores proporcionados.
    Student(int num, const std::string& name, std::string& studentId, const std::string& registrationStatus, const std::string& level, const std::string& credits, const std::string& midterm, const std::string& final, const std::string& gradeDetail);

    // Devuelve el número del estudiante.
    int getNum() const;

    // Establece el número del estudiante.
    void setNum(int num);

    // Devuelve el nombre del estudiante.
    const std::string &getName() const;

    // Establece el nombre del estudiante.
    void setName(const std::string &name);

    // Devuelve la identificación del estudiante.
    const std::string &getId() const;

    // Establece la identificación del estudiante.
    void setId(const std::string &id);

    // Devuelve el estado de registro del estudiante.
    const std::string &getRegistrationStatus() const;

    // Establece el estado de registro del estudiante.
    void setRegistrationStatus(const std::string &registrationStatus);

    // Devuelve el nivel del estudiante.
    const std::string &getLevel() const;

    // Establece el nivel del estudiante.
    void setLevel(const std::string &level);

    // Devuelve los créditos del estudiante.
    const std::string &getCredits() const;

    // Establece los créditos del estudiante.
    void setCredits(const std::string &credits);

    // Devuelve la calificación de mitad de período del estudiante.
    const std::string &getMidterm() const;

    // Establece la calificación de mitad de período del estudiante.
    void setMidterm(const std::string &midterm);

    // Devuelve la calificación final del estudiante.
    const std::string &getFinal() const;

    // Establece la calificación final del estudiante.
    void setFinal(const std::string &final);

    // Devuelve los detalles de la calificación del estudiante.
    const std::string &getGradeDetail() const;

    // Establece los detalles de la calificación del estudiante.
    void setGradeDetail(const std::string &gradeDetail);

private:
    // Número del estudiante.
    int num;
    // Nombre del estudiante.
    std::string name;
    // Identificación del estudiante.
    std::string studentId;
    // Estado de registro del estudiante.
    std::string registrationStatus;
    // Nivel del estudiante.
    std::string level;
    // Créditos del estudiante.
    std::string credits;
    // Calificación de mitad de período del estudiante.
    std::string midterm;
    // Calificación final del estudiante.
    std::string final;
    // Detalles de la calificación del estudiante.
    std::string gradeDetail;
};


#endif //NEWPROYECTOTEAM3_STUDENTS_H
