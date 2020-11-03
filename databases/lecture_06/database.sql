CREATE DATABASE database;
USE database;

CREATE TABLE real_state_situation (
    real_state_situation_id INT PRIMARY KEY AUTO_INCREMENT,
    real_state_desc VARCHAR(50),
    real_state_id INT,

    FOREIGN KEY (real_state_id) REFERENCES real_state(real_state_id)
);

CREATE TABLE real_state (
    real_state INT PRIMARY KEY AUTO_INCREMENT,
    real_state_address VARCHAR(50),
    real_state_buiding_area VARCHAR(20),
    real_state_room_qtd INT
);

CREATE TABLE real_state_owner (
    real_state_owner_id INT PRIMARY KEY AUTO_INCREMENT,
    real_state_id INT,
    client_cpf INT,
    
    FOREIGN KEY (real_state_id) REFERENCES real_state(real_state_id)
    FOREIGN KEY (client_cpf) REFERENCES client(client_cpf);
);

CREATE TABLE client (
    client_cpf INT PRIMARY KEY AUTO_INCREMENT,
    client_name VARCHAR(50),
    client_address VARCHAR(50),
    client_phone_number VARCHAR(50)
);

