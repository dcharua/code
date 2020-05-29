# Tarea 1. SQL Avanzado

---

##### Integrantes:
1. *Daniel Charua Garcia* - *A01017419* - *CSF*
2. *[Poner aquí Nombre y Apellidos del integrante 2]* - *[Poner aquí su Matrícula]* - *[Poner aquí su campus]*
3. *[Poner aquí Nombre y Apellidos del integrante 3]* - *[Poner aquí su Matrícula]* - *[Poner aquí su campus]*
4. *[Poner aquí Nombre y Apellidos del integrante 4]* - *[Poner aquí su Matrícula]* - *[Poner aquí su campus]*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El equipo tiene la libertad de elegir las tecnologías de desarrollo a utilizar en la tarea, sin embargo, debe tener presente que la solución final se deberá ejecutar en una plataforma en la nube. Puede ser  [Google Cloud Platform](https://cloud.google.com/?hl=es), [Azure](https://azure.microsoft.com/en-us/), AWS [AWS](https://aws.amazon.com/es/free/) u otra.
* El equipo tiene la libertad de utilizar el DBMS de su preferencia.
* La arquitectura de la solución deberá estar separada claramente por capas (*frontend*, *backend*, datos y almacenamiento).
* Todo el código, *scripts* y la documentación de la tarea debe alojarse en este repositorio de GitHub, siguiendo la estructura que aparece a continuación.

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz de toda la tarea
    - README.md			# Archivo con la información general de la tarea (este archivo)
    - frontend			# Carpeta con la solución del frontend (Web app)
    - backend			# Carpeta con la solución del backend en caso de ser necesario (CMS o API)
    - scripts		        # Carpeta con los scripts necesarios para generar la base de datos, cargar datos y ejecutar las consultas
    - database			# Carpeta con el diagrama Entidad-Relación Extendido y los archivos CSV de datos necesarios para generar la bases de datos

```

### 1.3 Documentación de la tarea

Como parte de la entrega de la tarea, se debe incluir la siguiente información:

* Diagrama del *Modelo Entidad-Relación Extendido*.
* *Scripts* para generar la base de datos, cargar datos y ejecutar consultas.
* Archivos CSV con los datos a cargar en al base de datos.
* Guía de configuración, instalación y despliegue de la aplicación en la plataforma en la nube  seleccionada.
* El código debe estar documentado siguiendo los estándares definidos para el lenguaje de programación seleccionado.

## 2. Solución

A continuación aparecen descritos los diferentes elementos que forman parte de la solución de la tarea.

### 2.1 Modelo de la *base de datos* 

*[Incluya aquí el Diagrama Entidad-Relación Extendido y explique las jerarquías modeladas así como las restricciones existentes*

### 2.2 Arquitectura de la solución

*[Incluya aquí un diagrama donde se aprecie la arquitectura de la solución propuesta, así como la interacción entre los diferentes componentes de la misma.]*

### 2.3 Frontend

El Frontend fue desarrollado con el framework [Flask](https://flask.palletsprojects.com/en/1.1.x/), se decidio usar esta opción ya que de manera muy sencilla se puede conectar a MySQL, generar las consultas y pasarlo al front  


#### 2.3.1 Lenguaje de programación
Flask se programa en [Python](https://www.python.org/) para la parte del back, las rutas y la configuración de la aplicación  y se usa HTML, CSS para las vistas web

#### 2.3.2 Instalación
Para correr la aplicación se debe clonar este repo y, acceder a la carpeta, crear un ambiente virtual y installar los requirimentos de flask con los sigueintes comandos:

```
cd frontend
python3 -m venv venv 
source venv/bin/activate
pip install requirements.txt 
```

Posteriormente se debe correr la aplicación con el comando 
```
python app.py
```
#### 2.3.3 Librerías de funciones o dependencias
- [FlaskAPI](https://www.flaskapi.org/)
- [FlaskSQL](https://flask-mysql.readthedocs.io/en/latest/)



