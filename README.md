 *Este proyecto ha sido creado como parte del currículo de 42 por wlu-bjor*

 # ft_printf 
 
 ## Descripción

```
int main(void)// int argc, char **argv
{
    int ret1 = ft_printf("estoy hablando%% con la persona %i: ", -1);
    printf("ft_printf returned: %d\n", ret1);
    int ret2 = printf("estoy hablando%% con la persona %i: ", -1);
    printf("printf returned: %d\n", ret2);
    return (0);
}
```