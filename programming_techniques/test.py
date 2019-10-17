eletro = dict()
cond = True


while True:
    eletro['Eletronic'] = input('Eletrodoméstico: ')
    eletro['Potencia'] = input('Potencia do Dispositivo: ')
    eletro['duraçao'] = int(input('Horas Diárias de Uso: '))
    confirma = input('Deseja Continuar a listagem ? [S/N]: ')
    confirma = confirma.upper()

    dias = int(input('Qtd de dias a serem avaliados: '))
    print('Dispositivos na Casa:',eletro['Eletronic'])
    print(sum(eletro['Potencia'])*eletro['duraçao']*dias)
    break
