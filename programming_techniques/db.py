#/usr/bin/python3

# Leonardo Silva - 591149

def getPercentage(x, y): return x / y * 100;

if __name__ == "__main__":
    n = int(input("Numero de dispositivos: "))

    eletro = list({} for i in range(n)) # Creates an empty list of dictionaries

    for i in range(n):
        eletro[i]['nome'] = input('Nome do eletrodomestico: ')
        eletro[i]['potencia'] = int(input('Potencia do eletrodomestico: '))
        eletro[i]['tempoAtivo'] = int(input('Tempo Ativo em horas: '))

    dias = int(input("Informe o numero de dias: "))

    somaPotencia = ([sum(eletro[i]['potencia'] for i in range(n))])[0] # :(
    somaTempo = ([sum(eletro[i]['tempoAtivo'] for i in range(n))])[0] # :(
    consumo_total = somaPotencia * somaTempo * dias

    print("Consumo total: {} kW".format(consumo_total))
    for i in range(n):
        individual_cost = float(eletro[i]['potencia'] * eletro[i]['tempoAtivo'])
        print("{}: {:.2f}%".format(eletro[i]['nome'], getPercentage(individual_cost, consumo_total)))


      
