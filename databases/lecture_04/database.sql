CREATE DATABASE database;
USE database;

CREATE TABLE title_type (
    title_type_id INT PRIMARY KEY AUTO_INCREMENT,
    title_type_desc VARCHAR(45) NOT NULL
);

CREATE TABLE genre (
    genre_id INT PRIMARY KEY AUTO_INCREMENT,
    genre_desc VARCHAR(45) NOT NULL
);

CREATE TABLE subscriber (
    subscriber_id INT PRIMARY KEY AUTO_INCREMENT,
    subscriber_cpf VARCHAR(9) NOT NULL,
    subscriber_name VARCHAR(45) NOT NULL
);

CREATE TABLE watch_info (
    watch_info_id INT PRIMARY KEY AUTO_INCREMENT,
    title_id INT,
    account_id INT,
    created_at DATETIME NOT NULL

    FOREIGN KEY (title_id) REFERENCES titulo(title_id),
    FOREIGN KEY (account_id) REFERENCES conta(account_id) 
);

CREATE TABLE episode (
    episode_id INT PRIMARY KEY AUTO_INCREMENT,
    episode_name VARCHAR(45) NOT NULL,
    episode_epilogue VARCHAR(45) NOT NULL,
    id_title INT
);

CREATE TABLE credit_card (
    credit_card_id INT PRIMARY KEY AUTO_INCREMENT,
    credit_card_number VARCHAR(16) NOT NULL,
    credit_card_security_number VARCHAR(3) NOT NULL,
    credit_card_due_date VARCHAR(4) NOT NULL,
    credit_card_holder VARCHAR(45) NOT NULL,
    subscriber_id INT, 

    FOREIGN KEY (subscriber_id) REFERENCES subscriber(subscriber_id)
);

CREATE TABLE account (
    account_id INT PRIMARY KEY AUTO_INCREMENT,
    account_name VARCHAR(45) NOT NULL,
    children_account CHAR(1),
    subscriber_id INT NOT NULL, 

    FOREIGN KEY (subscriber_id) REFERENCES subscriber(subscriber_id)
);

CREATE TABLE title (
    title_id INT PRIMARY KEY AUTO_INCREMENT,
    title_name VARCHAR(45) NOT NULL,
    title_epilogue VARCHAR(200),
    title_author VARCHAR(45) NOT NULL,
    genre_id INT,
    title_type_id INT,

    FOREIGN KEY (genre_id) REFERENCES genre(genre_id),
    FOREIGN KEY (title_type_id) REFERENCES title_type(title_type_id)
);

