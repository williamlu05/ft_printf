 *Este proyecto ha sido creado como parte del currículo de 42 por wlu-bjor*

 # ft_printf 
 
 ## Descripción

Este proyecto consiste en la recreación limitada de la función `printf` como la función `ft_printf` de las librerías estándar de C, añadirla a su propia librería `libftprintf`. Para ello, se ha empleado varias conversiones propios de él, con la posibilidad de emplear varios parámetros para completar esas conversiones. Aquellos son:
>* `%c`: Escribe un único carácter tipo char
>* `%s`: Escribe una cadena de caracteres
>* `%p`: Escribe un puntero tipo (void *), casteado a (unsigned long) para el número de bytes utilizados por mi sistema, representado en hexadecimal
>* `%d`: Imprime un número decimal, base 10
>* `%i`: Imprime un número decimal, base 10, sin la lectura de printf de bases octales o hexadecimales
>* `%u`: Imprime un número positivo, interpretado como unsigned int
>* `%x`: Imprime un número positivo en base hexadecimal, con letras en minúscula
>* `%X`: Imprime un número positivo en base hexadecimal, con letras en mayúscula
>* `%%`: Imprime el carácter '%'

La función retorna la cantidad de bytes escritos en pantalla, y -1 en caso de error. La función falla en caso de alguna llamada a la función write() no funciona, o en caso de leer una conversión sin implementar.

### Elección de algoritmo y estructura de datos
La estructura principal que permite recrear la función printf es el uso de *funciones variádicas*, los cuales son interpretados mediante las funciones `va_arg, va_start, va_end y va_copy`. Aquellos te permiten iterar sobre todos los parámetros que hayan, independientemente de la cantidad.
El resto de algoritmos y estructuras empleadas son elementales.

## Instrucciones
`make` o `make all`: Compila los archivos fuente de la parte obligatoria y genera `libftprintf.a`
- `make clean`: Elimina los archivos objeto (`.o`) generados durante la compilación.
- `make fclean`: Elimina los archivos objeto y el archivo de la librería `libftprintf.a`.
- `make re`: Realiza un `fclean` seguido de un `all` para recompilar todo el proyecto.

Además, aquí tiene un pequeño programa main para poder ver las comparaciones entre la original y la recreación del printf
```
int main(void)// int argc, char **argv
{
    int ret1 = ft_printf("estoy hablando%% con la persona %x: ", 109);
    printf("ft_printf returned: %d\n", ret1);
    int ret2 = printf("estoy hablando%% con la persona %x: ", 109);
    printf("printf returned: %d\n", ret2);
    return (0);
}
```

## Recursos
Se ha utilizado las comparaciones entre la función original `printf`, y las descripciones del manual con `man 3 printf`. El uso de IA ha sido para identificar *casos extremos* y *casos de funcionamiento indefinido*, para poder resolverlas.
