#!/usr/bin/python

# Faça um programa para escrever a contagem regressiva do lançamento de um foguete.
# Para esta contagem, os números devem ser escritos na tela em ordem decrescente, de
# 100 até 0.

import time;

def rocketState(sec):
	state = "[Esperando instruções de lançamento]"
	if  ( sec < 100 and sec > 90 ):  state = "[Ligando Motores principais]";
	elif( sec <= 90 and sec > 80 ):  state = "[Carregamento de oxigênio liquido]";
	elif( sec <= 80 and sec > 70 ):  state = "[Ligando propulsores]";
	elif( sec <= 70 and sec > 60 ):  state = "[Checando variaveis climaticas]";
	elif( sec <= 60 and sec > 50 ):  state = "[Verificando iniciação da contagem regressiva do terminal]";
	elif( sec <= 50 and sec > 40 ):  state = "[Abrindo valvulas de vazamento de oxigênio liquido]";
	elif( sec <= 40 and sec > 30 ):  state = "[Teste de atuador de vetor de propulsão]";
	elif( sec <= 30 and sec > 20 ):  state = "[Verificação de distância]";
	elif( sec <= 20 and sec > 10 ):  state = "[Presurização de tanque de propulsão]";
	elif( sec <= 10 and sec > 5  ):  state = "[Checagem de pirotecnia de braço]";
	elif( sec <= 5  and sec > 0  ):  state = "[Ignição do motor Merlin]";
	elif( sec == 0 ):                state = "[DECOLAGEM]";
	return state;

def timeHandler(sec):
	if( sec > 59 ): print("T menos {}:{:02} minutos\t Estado do lançamento: {}".format((sec // 60), (sec % 60), rocketState(sec) ))
	else: print("T menos {:02} segundos\t Estado do lançamento: {}.".format( (sec % 60), rocketState(sec) ))


print("!!! LANÇAMENTO DO FOGUETE 591149-LS EM 100 SEGUNDOS !!!")
for sec in range(100, 0, -1):
	timeHandler(sec);
	time.sleep(1);
