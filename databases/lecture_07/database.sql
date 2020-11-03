CREATE DATABASE database;
USE database;

create table Cidade (
    Id_Cidade int not null,
    Descricao varchar(50) not null,
    constraint PK_Cidade Primary Key (Id_Cidade)
);

create table Cliente(
    Codigo_Cliente int not null,
    Nome varchar(40) not null,
    Email varchar(50),
    Id_Cidade int null,
    Constraint PK_Cliente Primary Key(Codigo_Cliente),
    Constraint FK_Cliente_Cidade Foreign Key (Id_Cidade)
    References Cidade (Id_Cidade)
);

create table Vendedor(
    Codigo_Vendedor int not null,
    Nome varchar(40) not null,
    Comissao float not null,
    Constraint PK_Vendedor Primary Key(Codigo_Vendedor)
);

create table VendedorCidade(
    Codigo_Vendedor int not null,
    Id_Cidade int not null,
    Constraint PK_VendedorCidade Primary Key (Codigo_Vendedor, Id_Cidade)
);

create table Agenda(
    Id_Agenda int not null,
    Data Date not null,
    Codigo_Cliente int not null,
    Codigo_Vendedor int not null,
    Descricao varchar(50),
    Constraint PK_Agenda Primary Key(Id_Agenda),
    Constraint FK_Agenda_Cliente Foreign Key (Codigo_Cliente)
    References Cliente (Codigo_Cliente),
    Constraint FK_Agenda_Vendedor Foreign Key (Codigo_Vendedor)
    References Vendedor (Codigo_Vendedor)
);


alter table VendedorCidade
add constraint FK_VendedorCidade_Vendedor 
Foreign Key (Codigo_Vendedor)
References Vendedor (Codigo_Vendedor);

alter table VendedorCidade
add constraint FK_VendedorCidade_Cidade 
Foreign Key (Id_Cidade)
References Cidade (Id_Cidade);


select * from cidade;


insert into CIDADE (ID_CIDADE, DESCRICAO)
values (1, 'Bauru');
insert into CIDADE (ID_CIDADE, DESCRICAO)
values (2, 'Marília');
insert into CIDADE (ID_CIDADE, DESCRICAO)
values (3, 'Vera Cruz');
insert into CIDADE (ID_CIDADE, DESCRICAO)
values (4, 'Garça');
insert into CIDADE (ID_CIDADE, DESCRICAO)
values (5, 'Tupã');
insert into CIDADE (ID_CIDADE, DESCRICAO)
values (6, 'Pompéia');
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (1, 'Kamikaze Sports', null, 2);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (2, 'Loja de Esportes Record', null, 1);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (3, 'Karinas Sport', null, 4);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (4, 'Paraguay Shop', null, null);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (5, 'Sempre Barato', null, 3);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (6, 'Wind Shop', null, 1);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (7, 'RJS Representações', null, 6);
insert into CLIENTE (CODIGO_CLIENTE, NOME, EMAIL, ID_CIDADE)
values (8, 'BAD Vendas', null, null);
insert into VENDEDOR (CODIGO_VENDEDOR, NOME, COMISSAO)
values (1, 'Ronaldo', 15);
insert into VENDEDOR (CODIGO_VENDEDOR, NOME, COMISSAO)
values (2, 'Neymar', 23);
insert into VENDEDOR (CODIGO_VENDEDOR, NOME, COMISSAO)
values (3, 'Lucas', 10);
insert into VENDEDOR (CODIGO_VENDEDOR, NOME, COMISSAO)
values (4, 'Kléber', 8);
insert into VENDEDOR (CODIGO_VENDEDOR, NOME, COMISSAO)
values (5, 'Rogério', 19);
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (1, '2011-12-03', 3, 5, 'Prospecção');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (2, '2011-03-13', 6, 2, 'Pós-Venda');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (3, '2011-03-27', 6, 5, 'Prospecção');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (4, '2011-10-03', 1, 3, 'Prospecção');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (5, '2011-03-18', 5, 1, 'Pós-Venda');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (6, '2011-03-27', 4, 5, 'Suporte');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (7, '2011-05-03', 2, 2, 'Prospecção');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (8, '2011-03-20', 7, 4, 'Pós-Venda');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (9, '2011-03-19', 1, 3, 'Pós-Venda');
insert into AGENDA (ID_AGENDA, DATA, CODIGO_CLIENTE, CODIGO_VENDEDOR, DESCRICAO)
values (10, '2011-03-12', 5, 1, 'Suporte');
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (1, 3);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (2, 1);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (2, 5);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (3, 2);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (4, 6);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (5, 1);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (5, 2);
insert into VENDEDORCIDADE (CODIGO_VENDEDOR, ID_CIDADE)
values (5, 5);

# --------------------------- RESULTADOS

# 1
SELECT * FROM cliente;

# 2
SELECT data, descricao FROM agenda;

# 3
SELECT * FROM vendedor WHERE comissao BETWEEN 15 AND 20;

# 4
SELECT * FROM agenda WHERE descricao IN ("Prospeccao", "Pos-Venda");

# 5
SELECT * FROM cliente WHERE id_cidade IS NOT NULL;

# 6
SELECT * FROM cliente WHERE nome LIKE "%shop%";

# 7
SELECT COUNT(codigo_cliente) AS Count_Cod_Cliente, descricao FROM agenda GROUP BY descricao;

# 8
SELECT id_cidade, COUNT(codigo_cliente) AS Count_Cod_Cliente FROM cliente GROUP BY id_cidade;

# 9
SELECT id_cidade, COUNT(*) AS Count_Clientes FROM cliente GROUP BY id_Cidade HAVING id_Cidade IS NOT NULL;

# ------------------------ MAIS EXERCICIOS

# 1
SELECT Codigo_Cliente, COUNT(Codigo_Cliente) AS Count_Visitas FROM agenda GROUP BY Codigo_Cliente HAVING Count_Visitas > 1;

# 2
SELECT * FROM cliente CLI JOIN cidade CDD ON (CLI.Id_Cidade = CDD.Id_Cidade) WHERE CDD.Descricao != "Marilia";

# 3
SELECT CLI.Nome AS Nome_Cliente, VDD.Nome AS Nome_Vendedor FROM agenda AGD 
JOIN cliente CLI ON (AGD.Codigo_Cliente = CLI.Codigo_Cliente)
JOIN vendedor VDD ON (AGD.Codigo_Vendedor = VDD.Codigo_Vendedor)
WHERE VDD.Nome IN ("Neymar","Ronaldo");

# 4
SELECT CDD.Descricao AS Cidade, COUNT(VDD.Nome) AS Count_Vendedores FROM vendedorCidade VDC 
JOIN vendedor VDD ON (VDC.Codigo_Vendedor = VDD.Codigo_Vendedor) 
JOIN cidade CDD ON (CDD.Id_Cidade = VDC.Id_Cidade)
GROUP BY CDD.Descricao;
