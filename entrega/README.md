# TpSemaforos-7559
Trabajo Práctico Especial: Semaforos de la materia 75.59 - Técnicas de Programación Concurrentes
Nicolás Longo - 98271

En la carpeta informe se encuentra todo lo relativo al informe (incluidos los diagramas y los ejemplos de ejecuciones, con sus respectivos logfiles)
En la carpeta TpSemaforos se puede acceder al código y desde ahí compilar, probar, etc.

# Documentación

## Comandos para compilar el programa:

```cmake .```

```make```

### Comandos para correr el programa:

```./tpSemaforos CANT_PIZZAS```

Donde CANT_PIZZAS es el número de pizzas a fabricar

Si se quiere ejecutar el chequeo de memoria con valgrind:

```valgrind --leak-check=full --show-leak-kinds=all ./tpSemaforos```


### Comandos para verificación del estado de los semaforos:

Con este comando los listamos:

```ipcs```

Con este comando podemos borrarlo, utilizando el semid:

```ipcrm -s ****```


### Overleaf project for Latex
https://www.overleaf.com/project/5ee525ce85830c0001899693