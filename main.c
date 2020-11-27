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
    lenght = strlen(temp_arr);
    for (int k = 0; k < lenght; k++){
        net.octade1 = temp_arr[k] * pow(10, lenght - i-1);
    }
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
    for (int k = 0; k < lenght; k++){
        net.octade2 = temp_arr[k] * pow(10, lenght - k-1);
    }
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
    for (int k = 0; k < lenght; k++){
        net.octade3 = temp_arr[k] * pow(10, lenght - k-1);
    }
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
    for (int k = 0; k < lenght; k++){
        net.octade4 = temp_arr[k] * pow(10, lenght - k-1);
    }
    fgetc(inp);
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
    for (int k = 0; k < lenght; i++){
        mask.octade1 = temp_arr[k] * pow(10, lenght - k-1);
    }
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
    for (int k = 0; k < lenght; k++){
        mask.octade2 = temp_arr[k] * pow(10, lenght - k-1);
    }
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
    for (int k = 0; k < lenght; k++){
        mask.octade3 = temp_arr[k] * pow(10, lenght - k-1);
    }
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
    for (int k = 0; k < lenght; k++){
        mask.octade4 = temp_arr[k] * pow(10, lenght - k-1);
    }
    net.octade1 = net.octade1 & mask.octade1;
    net.octade2 = net.octade2 & mask.octade2;
    net.octade3 = net.octade3 & mask.octade3;
    net.octade4 = net.octade4 & mask.octade4;

}


int main()
{
    char *locale = setlocale(LC_ALL, "");
    FILE * inp = fopen("/home/datsky-prince/CLionProjects/Contest_27.11/input.txt", "rt");
    FILE * out = fopen("/home/datsky-prince/CLionProjects/Contest_27.11/output.txt", "wt");

    int number_of_lines_1 = count_lines(inp);
    int number_of_lines_2 = 0;

    str_skip(inp);
    for (int i = 0; i < number_of_lines_1; ++i){
        str_skip(inp);
    }

    number_of_lines_2 = count_lines(inp);
    IP adress;
    IP mask;






    return 0;
}