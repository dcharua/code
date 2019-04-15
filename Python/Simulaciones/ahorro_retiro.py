#Calculo de ededes
edad_retiro = 65
edad_actual = 27
vida_laboral = edad_retiro - edad_actual
#https://www.google.com/search?q=promedio+de+vida+en+mexico&oq=promedio+de+vida+en+mexico&aqs=chrome..69i57j69i60l4j69i61.5202j0j1&sourceid=chrome&ie=UTF-8
promedio_vida = 77
vida_retiro = promedio_vida - edad_retiro

#Gastos
gastos_anuales_transporte = 10000
gastos_anuales_diversion = 20000
gastos_anuales_alimentacion = 30000 
gastos_anuales_imprevistos= 5000
gastos_anuales_educacion = 100000
gastos_anuales_renta = 100000
gastos_anuales_seguro = 16000 
hijos = 2
promdio_gastos_anuales_educacion = (16 * hijos * gastos_anuales_educacion) / vida_laboral

#Calculo de gastos anuales totales
gastos_anuales_fijos = gastos_anuales_transporte + gastos_anuales_diversion + gastos_anuales_alimentacion + gastos_anuales_imprevistos + gastos_anuales_educacion + gastos_anuales_renta + gastos_anuales_seguro
gastos_mensuales_fijos = gastos_anuales_fijos /12

#Calculo de monto a ahorro
ahorro_pension_total = gastos_anuales_fijos * vida_retiro 
ahorro_pension_anual = ahorro_pension_total / vida_laboral

#Calculo del salario 
salario_anual = gastos_anuales_fijos + promdio_gastos_anuales_educacion + ahorro_pension_anual
salario_mensual = salario_anual / 12

print('Con mi edad actual %d, y gastos mensuales promedio de %d, mas la educacion de %d hijos, si me quiero retirar a la edad de retiro oficial %d, y espero vivir la vida promedio del mexicano %d, debe tener un salario mensual de %d' %(edad_actual,  gastos_mensuales_fijos, hijos, edad_retiro, promedio_vida, salario_mensual))


