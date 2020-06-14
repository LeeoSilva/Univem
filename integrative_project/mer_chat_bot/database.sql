/* 
    @author LeeoSilva <leeosilva0909@gmail.com> 
 */

DROP DATABASE IF EXISTS chatbot;
CREATE DATABASE chatbot;
USE chatbot;

CREATE TABLE logradouro (
    logradouro_id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(255) NOT NULL,
    email VARCHAR(255),
    celular VARCHAR(255)
);

CREATE TABLE agente (
    agente_id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    funcao VARCHAR(255) NOT NULL,
    status VARCHAR(255) NOT NULL,
    logradouro_id INT(10) NOT NULL,
    FOREIGN KEY (logradouro_id) REFERENCES logradouro(logradouro_id) ON DELETE CASCADE
);

CREATE TABLE comprador (
    comprador_id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    comprador_cpf_cnpj VARCHAR(255) NOT NULL,
    comprador_endereco VARCHAR(255) NOT NULL,
    logradouro_id INT(10) NOT NULL,
    FOREIGN KEY (logradouro_id) REFERENCES logradouro(logradouro_id) ON DELETE CASCADE
);

CREATE TABLE cliente (
    cliente_id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    empresa VARCHAR(255) NOT NULL,
    logradouro_id INT(10) NOT NULL,
    FOREIGN KEY (logradouro_id) REFERENCES logradouro(logradouro_id) ON DELETE CASCADE
);

CREATE TABLE relatorios (
    relatorio_id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    relatorio LONGTEXT NOT NULL
);

