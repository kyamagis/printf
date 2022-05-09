int ft_printf(const char *format, ...)
{
    valist  arg1;
    valist  arg2;
    size_t  done;

    done = ft_printlen(format, arg1)
    if (done >= INT_MAX)
    {
        va_end(arg1);
        va_end(arg2);
        return (-1);
    }
    ft_vprint(format, arg2);
    va_end(arg1);
    va_end(arg2);
    return (done);
}

int main(void)
{
    char *s;
    s = (char *)malloc(sizeof(char) * (INT_MAX + 1));
    ft_printf("\nretu"), printf("%s",memset(s, '1',INT_MAX));
}