-- Leonardo de Camargo da Silva - 591149 
-- Milena Morares - 592153 

-- 1) Faça o comando SQL que mostre os dados de imível cuja a situação é "Vago"
SELECT imovel.* from imovel imovel
    right join imovel_situacaoimovel sit_imovel on sit_imovel.id_imovel = imovel.id_imovel
    right join situacaoimovel sitimovel on sitimovel.id_situacaoimovel = sit_imovel.id_situacaoimovel
    where sitimovel.descricao = "Vago";

-- 2) Faça o comando SQL que mostre todos os clientes cujo o sobrenome seja "Rodolfo"
-- e que tenha um aluguel maior que R$1520,00, sendo ordenado pela 
-- data de início do aluguel.
SELECT * FROM cliente cliente
    LEFT JOIN aluguel aluguel ON cliente.cpf_cliente = aluguel.cpf_cliente
    WHERE cliente.nome LIKE "% Rodolfo" AND aluguel.valor > 1520 
    ORDER BY aluguel.data_inicio;

-- 3) Faça o comando SQL que mostre os dados do imível cuja o tipo é "Apartamento".
SELECT imovel.* FROM imovel imovel
    right join tipoimovel tipo on imovel.id_tipoimovel = tipo.id_tipoimovel
    where tipo.descricao = "Apartamento";

-- 4) Faça o comando SQL que mostre quem é o dono do menor imóvel em área
-- construída e as informações deste terreno.
SELECT cliente.nome, imovel.id_imovel, imovel.id_tipoimovel, imovel.endereco, MIN(imovel.areaconstruida) as 'area_construida', imovel.qntdcomodo FROM proprietario prop 
    RIGHT JOIN cliente cliente ON prop.cpf_cliente = cliente.cpf_cliente
    LEFT JOIN imovel imovel ON (prop.id_imovel = imovel.id_imovel);

-- 5) Faça o comando SQL que mostre os clientes que além de serem proprietários também alugam imoveis.
SELECT cliente.nome from cliente cliente
    right join aluguel aluguel on aluguel.cpf_cliente = cliente.cpf_cliente
    inner join proprietario prop on prop.cpf_cliente = aluguel.cpf_cliente;

