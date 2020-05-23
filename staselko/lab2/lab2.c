//1 Ввод параметров планеты
//2G_1
//(масса, радиус орбиты,
//скорость движения)
//2 Ввод аналогичных параметров планеты 2G_2.
//3 Ввод аналогичных параметров планеты 2G_3.
//4 Расчет продолжительности года на каждой из трех 3-х планет.
//5 Рассчитать, на каком расстоянии друг от друга будут
//находиться планеты для заданного времени t, прошедшего с
//момента появления звездолета в системе.
//6 Определить силу попарного гравитационного взаимодействия
//3-х планет в заданное время t.
//7 Выход из программы.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//declaration object "planet"
struct planet {
  int weight;
  int radius;
  int speed;
};
//adding functions for calculation tasks by template 
void yearDuration(struct planet parm);
void distanceBetweenPlanets(struct planet parm_1,struct planet parm_2,struct planet parm_3, int time);
void gravitationForce(struct planet parm_1,struct planet parm_2,struct planet parm_3, int time);

int main() {

  struct planet E2G_1,E2G_2,E2G_3;
  int time;
// adding objects
  printf("Введите массу для 1й планеты : ");
  scanf("%d", &E2G_1.weight);
  printf("Введите радиус орбиты для 1й планеты : ");
  scanf("%d", &E2G_1.radius);
  printf("Введите скорость для 1й планеты : ");
  scanf("%d", &E2G_1.speed);
  yearDuration(E2G_1);

  printf("Введите массу для 2й планеты : ");
  scanf("%d", &E2G_2.weight);
  printf("Введите радиус орбиты для 2й планеты : ");
  scanf("%d", &E2G_2.radius);
  printf("Введите скорость для 2й планеты : ");
  scanf("%d", &E2G_2.speed);
  yearDuration(E2G_2);

  printf("Введите массу для 3й планеты : ");
  scanf("%d", &E2G_3.weight);
  printf("Введите радиус орбиты для 3й планеты : ");
  scanf("%d", &E2G_3.radius);
  printf("Введите скорость для 3й планеты : ");
  scanf("%d", &E2G_3.speed);
  yearDuration(E2G_3);

  printf("Укажите прошедшее время: ");
  scanf("%d", &time);
  distanceBetweenPlanets(E2G_1, E2G_2, E2G_3, time);
  gravitationForce(E2G_1, E2G_2, E2G_3, time);



}

// functions realisation

void yearDuration(struct planet parm) {
    float yearDuration = ((2*3.14)*parm.radius/parm.speed)/8760;
    printf("Длительность года : \n");
    printf("%f \n", yearDuration);
}

void distanceBetweenPlanets(struct planet parm_1, struct planet parm_2, struct planet parm_3, int time) {
    float distanceBetweenFirstAndSecond = (parm_1.speed - parm_2.speed) * time;
    if (distanceBetweenFirstAndSecond < 0) {
        distanceBetweenFirstAndSecond = distanceBetweenFirstAndSecond*(-1);
    }

    float distanceBetweenFirstAndThird = (parm_1.speed - parm_3.speed) * time;
    if (distanceBetweenFirstAndThird < 0) {
        distanceBetweenFirstAndThird = distanceBetweenFirstAndThird*(-1);
    }

    float distanceBetweenSecondAndThird = (parm_2.speed - parm_3.speed) * time;
    if (distanceBetweenSecondAndThird < 0) {
        distanceBetweenSecondAndThird = distanceBetweenSecondAndThird*(-1);
    }

    printf("Между первой и второй: %f киллометров\n Между первой и третьей: %f киллометров\n Между второй и третьей: %f киллометров\n\n", distanceBetweenFirstAndSecond, distanceBetweenFirstAndThird, distanceBetweenSecondAndThird);

}

void gravitationForce(struct planet parm_1,struct planet parm_2,struct planet parm_3, int time) {
    float distanceBetweenFirstAndSecond = (parm_1.speed - parm_2.speed) * time;
    if (distanceBetweenFirstAndSecond < 0) {
        distanceBetweenFirstAndSecond = distanceBetweenFirstAndSecond*(-1);
    }

    float distanceBetweenFirstAndThird = (parm_1.speed - parm_3.speed) * time;
    if (distanceBetweenFirstAndThird < 0) {
        distanceBetweenFirstAndThird = distanceBetweenFirstAndThird*(-1);
    }

    float distanceBetweenSecondAndThird = (parm_2.speed - parm_3.speed) * time;
    if (distanceBetweenSecondAndThird < 0) {
        distanceBetweenSecondAndThird = distanceBetweenSecondAndThird*(-1);
    }

    float forceBetweenFirstAndSecond = 6.64*(parm_1.weight * parm_2.weight)/ (distanceBetweenFirstAndSecond * distanceBetweenFirstAndSecond);
    float forceBetweenFirstAndThird = 6.64*(parm_1.weight * parm_3.weight)/ (distanceBetweenFirstAndThird * distanceBetweenFirstAndThird);
    float forceBetweenSecondAndThird = 6.64*(parm_1.weight * parm_3.weight)/ (distanceBetweenSecondAndThird * distanceBetweenSecondAndThird);

    printf("Между первой и второй: %f Ньютон\n Между первой и третьей: %f Ньютон\n Между второй и третьей: %f Ньютон\n", forceBetweenFirstAndSecond, forceBetweenFirstAndThird, forceBetweenSecondAndThird);

}

