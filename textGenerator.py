# No es necesario ejecutar este archivo. Este archivo se utilizó para generar datos de prueba para el programa principal.

import random
from faker import Faker

# Create a Faker instance and set the locale to 'es_ES' for Spanish names
fake = Faker('es_ES')

# Possible course names, CRNs, and durations
course_names = ["NEURAL NETWORKS - COMP 1234 0", "ARTIFICIAL INTELLIGENCE - COMP 5678 0", "DATA STRUCTURES - COMP 9012 0", "ALGORITHMS - COMP 3456 0", "OPERATING SYSTEMS - COMP 7890 0",
                "DATABASE SYSTEMS - COMP 2345 0", "SOFTWARE ENGINEERING - COMP 6789 0", "COMPUTER NETWORKS - COMP 1234 0", "WEB DEVELOPMENT - COMP 5678 0", "MOBILE DEVELOPMENT - COMP 9012 0"]
months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]

# Function to generate a random course information string
def generate_course_info():
    course_name = random.choice(course_names)
    crn = str(random.randint(10000, 99999))
    start_month = random.choice(months)
    end_month = months[(months.index(start_month) + 4) % 12]
    year = str(random.randint(2024, 2030))
    return f"Course Information\n{course_name}\nCRN:\t{crn}\nDuration:\t22 {start_month}, {year} - 18 {end_month}, {year}\nStatus:\tOpen\n"

# Function to generate a random student string
def generate_student_info(student_number):
    student_name = fake.name()
    student_id = f"Z{str(random.randint(10000000, 99999999))}"
    return f"{student_number}\t{student_name}\t{student_id}\t** Registered **\tUNDERGRADUATE\t3.000\tEnter\tEnter\tAvailable"

# Ask the user for the number of students
num_students = int(input("Enter the number of students (1-100): "))

# Generate the course information string and the student strings
course_info = generate_course_info()
student_info = "\n".join(generate_student_info(i) for i in range(1, num_students + 1))

# Write these strings to a .txt file
with open("Resources/Data/ejemploDatos_TEST.txt", "w") as f:
    f.write(course_info)
    f.write("\nEnrollment Counts\n\tMaximum\tActual\tRemaining\nEnrollment:\t29\t11\t18\nCross List: \t0\t0\t0\n")
    f.write("\nSummary Class List\nRecord\nNumber\tStudent Name\tID\tReg Status\tLevel\tCredits\tMidterm\tFinal\tGrade Detail\n")
    f.write(student_info)