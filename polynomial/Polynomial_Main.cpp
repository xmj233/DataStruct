#include "Polynomial.cpp"

int main() {
    Polynomial Pa, Pb;
    printf("^^Test of CreatePolyn^^\n");
    printf("创建表达式Pa：");
    //2.1,1 4.0,3 -3.12,5 5.3,7 2.5,9
    CreatePolyn(Pa, 5);
    printf("Pa = ");
    PrintPolyn(Pa);
    printf("\n创建表达式Pb：");
    //3.4,2 -3.17,4 4.1,5 1.8,8 -2.5,9 0.5,12
    CreatePolyn(Pb, 6);
    printf("Pb = ");
    PrintPolyn(Pb);

    printf("\n\n^^Test of AddPolyn function.^^\n");
    printf("Pa = Pa + Pb = ");
    AddPolyn(Pa, Pb);
    PrintPolyn(Pa);

    printf("\n\n^^Test of SubtractPolyn function.^^\n");
    printf("创建表达式Pa：");
    CreatePolyn(Pa, 5);
    printf("Pa = ");
    PrintPolyn(Pa);
    printf("\n创建表达式Pb：");
    CreatePolyn(Pb, 6);
    printf("pb = ");
    PrintPolyn(Pb);
    printf("\nPa = Pa - Pb = ");
    SubtractPolyn(Pa, Pb);
    PrintPolyn(Pa);

    printf("\n\n^^Test of MulitplyPolyn function.^^\n");
    printf("创建表达式Pa：");
    //2.1,1 4.0,3 -3.12,5 5.3,7 2.5,9
    CreatePolyn(Pa, 5);
    printf("Pa = ");
    PrintPolyn(Pa);
    printf("\n创建表达式Pb：");
    //3.4,2 -3.17,4 4.1,5 1.8,8 -2.5,9 0.5,12
    CreatePolyn(Pb, 6);
    printf("Pb = ");
    PrintPolyn(Pb);
    printf("\nPa = Pa * Pb = ");
    MuLitiplyPolyn(Pa, Pb);
    PrintPolyn(Pa);
    printf("\n%d\n", Pa.len);
}