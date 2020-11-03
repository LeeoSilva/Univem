CREATE DATABASE database;
USE database;

CREATE TABLE baby (
    baby_id INT PRIMARY KEY AUTO_INCREMENT,
    baby_name VARCHAR(50) NOT NULL,
    baby_birth DATE NOT NULL,
    baby_birth_weight VARCHAR(4) NOT NULL,
    baby_height VARCHAR(5) NOT NULL
);

CREATE TABLE mother (
    mother_id INT PRIMARY KEY AUTO_INCREMENT,
    mother_name VARCHAR(50) NOT NULL,
    mother_address VARCHAR(100) NOT NULL,
    mother_birth DATE NOT NULL,
    mother_phone_number VARCHAR(20)
);

CREATE TABLE doctor (
    doctor_crm INT PRIMARY KEY AUTO_INCREMENT,
    doctor_name VARCHAR(50) NOT NULL,
    doctor_specialty VARCHAR(50) NOT NULL,
    doctor_phone_number VARCHAR(20)
);

CREATE TABLE births (
    id_birth INT PRIMARY KEY AUTO_INCREMENT,
    id_baby INT NOT NULL,
    id_mother NOT NULL,
    doctor_crm INT NOT NULL,

    FOREIGN KEY (id_baby) REFERENCES baby(baby_id),  
    FOREIGN KEY (id_mother) REFERENCES mother(mother_id),
    FOREIGN KEY (doctor_crm) REFERENCES doctor(doctor_crm)  
);

