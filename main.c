/* Считывается число строк, с помощью fgets пропускается одна строка,
 * Создаются две структуры данных, одна предназначена для введенной маски, вторая для адреса компа
 * Производится побитовая конъюнкция
 * Результат побитовой коньюнкции записывается в массив с сепараторами по одной цифре и в каждой строке ищется подстрока с таким адресом сети
 * Для адреса сети находится соответствующий интерфейс, создаётся исключение для несуществующего адреса сети. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define SIZE 100

typedef struct{
    int octade1,
        octade2,
        octade3,
        octade4;
}IP;

void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)  /* записываем знак */
        n = -n;          /* делаем n положительным числом */
    i = 0;
    do {       /* генерируем цифры в обратном порядке */
        s[i++] = n % 10 + '0';   /* берем следующую цифру */
    } while ((n /= 10) > 0);     /* удаляем */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int pow(int x, int y) {
    int temp = x;
    if (y == 0)
        return 1;
    else {
        while (y != 1) {
            x = x * temp;
            y--;
        }
        return x;
    }
}

int count_lines(FILE * inp){
    char arr_number_of_lines[SIZE] = {0};
    int dig_num_of_lines           =  0;
    char cur                       =  0;

    for (int i = 0; i < SIZE; ++i){
        cur = fgetc(inp);
        if ('\n' == cur || '\0' == cur)
            break;
        arr_number_of_lines[i] = cur;
    }
    strcat(arr_number_of_lines, "\0");
    int lenght = strlen(arr_number_of_lines);
    for (int i = 0; i < lenght; i++){
        if ('\0' == arr_number_of_lines[i])
            break;
        else{
            dig_num_of_lines += (arr_number_of_lines[i] - 48) * pow(10, lenght - i-1);
        }
    }
    return dig_num_of_lines;
}

void str_skip(FILE * inp){
    int arr[1000]= {0};
    fgets(arr, 1000, inp);
}
char * converter(int number){
    char arr[3] = {0};
    int units = 0;
    int dozens = 0;
    int hundreds = 0;
    units = number % 100;
    dozens = number % 10;
}

char* enter_ip(FILE* inp, IP net, IP mask){
    char cur         =  0;
    char temp_arr[4] = {0};
    char res_arr[15] = {0};
    int  i           =  0;
    int  lenght      =  0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    net.octade1 = atoi(temp_arr[0]);
    for (int k = 0; k < 4; k++)
    {
        temp_arr[k] = 0;
    }
    i = 0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    net.octade2 = atoi(temp_arr[0]);
    for (int k = 0; k < 4; k++)
    {
        temp_arr[k] = 0;
    }
    i = 0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    net.octade3 = atoi(temp_arr[0]);
    for (int k = 0; k < 4; k++)
    {
        temp_arr[k] = 0;
    }
    i = 0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    net.octade4 = atoi(temp_arr[0]);
    fgetc(inp);
    i=0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    mask.octade1 = atoi(temp_arr[0]);
    for (int k = 0; k < 4; k++)
    {
        temp_arr[k] = 0;
    }
    i = 0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    lenght = strlen(temp_arr);
    mask.octade2 = atoi(temp_arr[0]);
    for (int k = 0; k < 4; k++)
    {
        temp_arr[k] = 0;
    }
    i = 0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    mask.octade3 = atoi(temp_arr[0]);
    for (int k = 0; k < 4; k++)
    {
        temp_arr[k] = 0;
    }
    i = 0;
    while (1){
        cur = fgetc(inp);
        if ('.' != cur)
        {
            temp_arr[i] = cur;
        }
        else
            break;
    }
    lenght = strlen(temp_arr);
    mask.octade4 = atoi(temp_arr[0]);
    net.octade1 = net.octade1 & mask.octade1;
    net.octade2 = net.octade2 & mask.octade2;
    net.octade3 = net.octade3 & mask.octade3;
    net.octade4 = net.octade4 & mask.octade4;
    char arr1[3] = {0};
    char arr2[3] = {0};
    char arr3[3] = {0};
    char arr4[3] = {0};
    itoa(net.octade1, arr1);
    itoa(net.octade2, arr2);
    itoa(net.octade3, arr3);
    itoa(net.octade4, arr4);
    strcat(res_arr, arr1);
    strcat(res_arr, ".");
    strcat(res_arr, arr2);
    strcat(res_arr, ".");
    strcat(res_arr, arr3);
    strcat(res_arr, ".");
    strcat(res_arr, arr4);
    return res_arr[0];

}


int main()
{
    char *locale = setlocale(LC_ALL, "");
    FILE * inp = fopen("/home/datsky-prince/CLionProjects/Contest_27.11/input.txt", "rt");
    FILE * out = fopen("/home/datsky-prince/CLionProjects/Contest_27.11/output.txt", "wt");

    int number_of_lines_1 = count_lines(inp);
    int number_of_lines_2 = 0;
    char* result_of_conjunction = NULL;

    str_skip(inp);
    for (int i = 0; i < number_of_lines_1+2; ++i){
        str_skip(inp);
    }

    number_of_lines_2 = count_lines(inp);
    IP adress;
    IP mask;

    result_of_conjunction = enter_ip(inp, adress, mask);





    return 0;
}