#include <stdio.h>
/**
 * main - origin point
 * Description: Print lowercase alphabets
 * Return: (0) (Success)
 */
int main(void)
{
int n = 97;

while (n <= 122)
{
putchar(n);
n++;
}
putchar('\n');
return (0);
}
