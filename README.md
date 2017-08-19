# pinglang
Esoteric programming language based on brainfuck and Pingu language

El lenguaje está compuesto por 8 instrucciones:
    
    * NOOT NEET: Incrementa el puntero.
    * NOOT NUTE: Decrementa el puntero.
    * NOOT NIT: Incrementa el byte apuntado.
    * NEET NEET: Decrementa el byte apuntado.
    * NEET NUTE: Imprime por pantalla el byte apuntado en formato ascii.
    * NEET NIT: Entrada en formato ASCII del byte apuntado.
    * NIT NIT: Si el valor del byte apuntado es 0, entonces avanza a la instrucción inmediatamente posterior al siguiente NIT NOOT.
    * NUTE NIT: Si el byte apuntado no es 0, retrocede a la instrucción inmediatamente posterior al anterior NIT NIT.

Ejemplo Hola:

NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT
NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT

NIT NIT
NOOT NEET NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT
NOOT NEET NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT
NOOT NEET NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT NOOT NIT
NOOT NEET NOOT NIT NOOT NIT NOOT NIT
NOOT NEET NOOT NIT
NOOT NUTE NOOT NUTE NOOT NUTE NOOT NUTE NOOT NUTE
NEET NEET
NUTE NIT

NOOT NEET NOOT NIT NOOT NIT NEET NUTE
NOOT NEET NOOT NEET NOOT NIT NEET NUTE
NEET NEET NEET NEET NEET NEET NEET NUTE
NOOT NUTE NEET NEET NEET NEET NEET NEET NEET NUTE
NOOT NEET NOOT NEET NOOT NEET NEET NUTE
