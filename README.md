# Tapia Nicolas Rojas Aymara Guzman Maria Delgado Fernando TareaN3


# Tarea 3: Simulacion de una alarma domestica a través de una interfaz gráfica y eventos
## Integrantes
- Fernando Delgado
- Maria Guzman
- Aymara Rojas
- Nicolás Tapia

## Archivos que componen el proyecto
* El archivo de entrada "config.txt"
* El archivo .pro
* Los archivos .jpg para representar la imagen de la alarma en la interfaz
* Los encabezados y clases "Central" "Door" "DoorView" "House" "Housewindow" "Magnetic_Sensor" "MagneticSensorView" "Sensor" "Window" "WindowView" (tanto con .cpp y .h)
* El archivo "main.cpp"
* El archivo ui "Housewindow"

## Requerimientos
1) Tener instalado Qt creator

## Como compilar
1) Dirigirse al directorio en donde está guardado el proyecto 
2) Abrir archivo .pro de la stage a revisar
3) En Qt creator, modificar "run" del proyecto en pestaña "projects" con tal de que utilice "config.txt" para ejecutarse, por lo que en el apartado "Command line arguments" escribir "config.txt".
4) Para el uso de las imagenes en la Stage4, en Qt creator ir a "run" del projecto en pestaña "projects" y modificar "working directory" a la carpeta donde se hayan guardado los archivos de este github, con tal de acceder correctamente a los .jpg en el código.

## Ejecucción 
* En Qt creator, buildear y correr el programa

## Consideraciones
* Se ha utilizado una branch para cada stage, esta branch es solo de introducción.
* Se ha utilizado en la stage4 el uso de imagenes para representar la alarma; donde se tiene una para cuando esta prendida y sonando, prendida y callada, y cuando esta silenciada correspondiente a cuando esta apagada la seguridad. Para ello se debe tener los archivos .jpg en la carpeta donde esta todo el código y clases.


## Documentacion realizada y diagrama de clases
* La app utilizada para realizar el diagrama de clases no lográ generar el plano general uniendo cada diagrama, en vez de ello solo genera un diagrama para cada clase especifica del proyecto;
* Se adjunta un link a ella dentro del archivo .pdf de documentación, dado que utiliza muchos archivos y es un tanto dificil de visualizar correctamente en este github.
