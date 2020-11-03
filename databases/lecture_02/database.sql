CREATE DATABASE database;
USE database;

CREATE TABLE pacient(
    pacient_id INT PRIMARY KEY AUTO_INCREMENT,
    pacient_name VARCHAR(255) NOT NULL
);

CREATE TABLE room (
    room_id INT PRIMARY KEY AUTO_INCREMENT,
    room_desc VARCHAR(255) NOT NULL,
    room_qtd INT NOT NULL
);

CREATE TABLE doctor (
    doctor_id INT PRIMARY KEY AUTO_INCREMENT,
    doctor_name VARCHAR(255) NOT NULL,
    doctor_phone_number VARCHAR(32) NOT NULL
);

CREATE TABLE student (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    student_name VARCHAR(255) NOT NULL,
    student_phone_number VARCHAR(32) NOT NULL,
    student_admission_year INT NOT NULL,
    created_at DATE NOT NULL
);

CREATE TABLE subject (
    subject_id INT PRIMARY KEY AUTO_INCREMENT,
    subject_name VARCHAR(255) NOT NULL
);

CREATE TABLE course (
    course_id INT PRIMARY KEY AUTO_INCREMENT,
    course_name VARCHAR(255) NOT NULL
);

CREATE TABLE employee (
    employee_id INT PRIMARY KEY AUTO_INCREMENT,
    employee_name VARCHAR(255) NOT NULL,
    employee_hours INT NOT NULL
);

CREATE TABLE department (
    department_id INT PRIMARY KEY AUTO_INCREMENT,
    department_name INT NOT NULL
);

CREATE TABLE manager (
    manager_id INT PRIMARY KEY AUTO_INCREMENT,
    manager_name VARCHAR(255) NOT NULL
);

CREATE TABLE project (
    project_id INT PRIMARY KEY AUTO_INCREMENT,
    project_name VARCHAR(255) NOT NULL,
    created_at DATE NOT NULL
);

