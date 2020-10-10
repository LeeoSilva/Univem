-- 1) Crie um banco de dados no MySQL com o nome FATURAMENTO
DROP DATABASE IF EXISTS FATURAMENTO;
CREATE DATABASE FATURAMENTO;
USE FATURAMENTO;

 -- 2) Crie os comandos SQL para criação das tabelas do Modelo Lógico no banco de dados FATURAMENTO

CREATE TABLE cliente(
    CODIGO_CLIENTE INT(11) PRIMARY KEY AUTO_INCREMENT,
    NOME VARCHAR(50) NOT NULL,
    ENDERECO VARCHAR(50),
    CIDADE VARCHAR(40)
);

CREATE TABLE fornecedor(
    CNPJ_FORNECEDOR CHAR(14),
    RAZAO_SOCIAL VARCHAR(50) NOT NULL,
    ENDERECO VARCHAR(50) NOT NULL,
    CIDADE VARCHAR(40) NOT NULL,
    CONSTRAINT CNPJ_FORNECEDOR PRIMARY KEY(CNPJ_FORNECEDOR)
);

CREATE TABLE nota(
    NUMERO_NOTA INT(11) PRIMARY KEY AUTO_INCREMENT,
    DATA DATE NOT NULL,
    TIPO_PAGTO VARCHAR(10) NOT NULL,
    CODIGO_CLIENTE INT(11),
    CONSTRAINT FK_CODIGO_CLIENTE FOREIGN KEY (CODIGO_CLIENTE) 
    REFERENCES cliente(CODIGO_CLIENTE)
);

CREATE TABLE produto(
    CODIGO_PRODUTO INT(11) PRIMARY KEY AUTO_INCREMENT,
    DESCRICAO VARCHAR(30) NOT NULL,
    ESTOQUE INT(11) NOT NULL,
    VALOR FLOAT NOT NULL,
    CNPJ_FORNECEDOR CHAR(14),
    CONSTRAINT FK_CNPJ_FORNECEDOR FOREIGN KEY (CNPJ_FORNECEDOR) 
    REFERENCES fornecedor(CNPJ_FORNECEDOR)
);

CREATE TABLE item(
    NUMERO_NOTA INT(11),
    CODIGO_PRODUTO INT(11),
    QTDE INT(11) NOT NULL,
    CONSTRAINT FK_NUMERO_NOTA FOREIGN KEY (NUMERO_NOTA) 
    REFERENCES nota(NUMERO_NOTA),
    CONSTRAINT FK_CODIGO_PRODUTO
    FOREIGN KEY (CODIGO_PRODUTO) REFERENCES produto(CODIGO_PRODUTO)
);
 
 -- 3) Insira os seguintes registros.

INSERT INTO fornecedor(CNPJ_FORNECEDOR, RAZAO_SOCIAL, ENDERECO, CIDADE)
    VALUES(17624092000185, 'Alpha Soluções em Informática', 'Rua 9 de Julho, 738', 'Marília'),
        (27385372000136, 'ADABAS S/A', 'Rua 9 de Julho, 829', 'Marília'),
        (47132482000112, 'MicroSystem Informática', 'Av. da Saudade, 98', 'Bauru'),
        (56021482000112, 'J.W. Sistemas', 'Rua Paes Leme, 172', 'Marília');

INSERT INTO cliente(CODIGO_CLIENTE, NOME, ENDERECO, CIDADE)
    VALUES (1, 'Francisco Santos', 'Rua XV de Novembro, 16', NULL),
        (2, 'Claudete Pereira', NULL, NULL),
        (3, 'José Souza', NULL, NULL),
        (4, 'Sônia Santos Oliveira', NULL, 'Bauru'),
        (5, 'Leonardo de Camargo da Silva', 'Rua Sérgio Aurélio da Paz, 113', 'Marília'),
        (6, 'Milena Moraes da Silva', 'Rua Romildo Marconato, 103', 'Marília');

INSERT INTO produto(CODIGO_PRODUTO, DESCRICAO, ESTOQUE, VALOR, CNPJ_FORNECEDOR)
    VALUES(100, 'Micro Pentium IV', 14, 850, 56021482000112),
        (200, 'Impressora EPSON', 8, 280, 27385372000136),
        (300, 'Scanner Genius', 9, 190, NULL),
        (400, 'Disquete 3M', 30, 10, 17624092000185); 

INSERT INTO nota(NUMERO_NOTA, DATA, TIPO_PAGTO, CODIGO_CLIENTE)
    VALUES(1001, '2002-05-18', 'A Vista', 2),
        (1002, '2002-05-18', 'A Vista', NULL),
        (1003, '2002-05-19', 'A Prazo', 4),
        (1004, '2002-05-20', 'A Vista', 3);

INSERT INTO item(NUMERO_NOTA, CODIGO_PRODUTO, QTDE)
    VALUES(1001, 100, 1),
        (1001, 400, 5),
        (1002, 200, 1),
        (1003, 300, 1),
        (1004, 200, 2),
        (1004, 300, 1);

-- 4) Crie a tabela de Tipo de Produto e relacione com a tabela produto.
CREATE TABLE tipo_produto(
    ID_TIPO_PRODUTO INT PRIMARY KEY AUTO_INCREMENT,
    DESCRICAO VARCHAR(40) NOT NULL
);

ALTER TABLE produto
ADD ID_TIPO_PRODUTO INT;

ALTER TABLE produto
ADD CONSTRAINT FK_ID_TIPO_PRODUTO
FOREIGN KEY (ID_TIPO_PRODUTO) REFERENCES tipo_produto(ID_TIPO_PRODUTO);

 -- 5) Altere a quantidade do produto Scanner Genius para 7
UPDATE produto SET ESTOQUE = 7 WHERE DESCRICAO='Scanner Genius';

 -- 6) Exclua o cliente Francisco Santos
DELETE FROM cliente WHERE NOME = 'Francisco Santos';

 -- 7) Apresente os dados dos produtos cujo o estoque é maior que 200.
SELECT * FROM produto WHERE ESTOQUE > 200;
    
 -- 8) Apresente a quantidade de fornecedor agrupados por cidade.
SELECT count(CNPJ_FORNECEDOR) AS QTDE_FORNECEDOR FROM fornecedor GROUP BY CIDADE;

 -- 9) Apresente a soma de estoque dos produtos. 
SELECT sum(ESTOQUE) AS SOMA_ESTOQUE from produto;

 -- 10) Apresente o número da nota e o nome do cliente vinculado a esta nota.
SELECT nota.NUMERO_NOTA, cliente.NOME FROM nota nota 
    INNER JOIN cliente cliente ON (nota.CODIGO_CLIENTE = cliente.CODIGO_CLIENTE);
