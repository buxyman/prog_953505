//Task 2.1.23
/*Торговое предприятие планирует открыть интернет-магазин
по продаже фруктов. Вам заказывают разработку программного
модуля на С, который должен выполнять следующие функции:
1 Заказ мандаринов (кг).
2 Заказ персиков (кг).
3 Заказ винограда (кг).
4 Корзина (вывод сведений о количестве заказанных фруктов и
их стоимости).
5 Расчет стоимости заказа (сведения о стоимости каждого вида
фруктов, скидках на данный заказ, затратах на доставку, общей
стоимости заказа).
6 Обратная связь
(название магазина, номер лицензии,
контактная информация).
7 Выход из программы.
*/

#include <iostream>
#include <math.h>
float generalMass = 0, generalCost = 0, peachMass = 0, peachCost = 0, mandarinMass = 0, mandarinCost = 0, grapeMass = 0, grapeCost = 0;

void GeneralMassCost(float cost, float mass)
{
	float midcost = 0, midcost1 = 0;
	if (cost > 99 && mass > 20)
	{
		printf_s("\nTotal weight: %f", mass);
		printf_s("\nDelivery cost =$10 plus $2 for each kg of overweight");
		midcost = 10 + (mass - 20) * 2;
		printf_s("\nYour sum: %f", midcost);
		printf_s("\nYou have a 10 percent discount\n");
		midcost1 = cost - (10 * cost) / 100;
		printf_s("\nYour total sum: %f", midcost1);
	}
	else if (cost > 99)
	{
		printf_s("\nTotal weight: %f", mass);
		printf_s("\nYou have a 10 percent discount\n");
		midcost = cost - (10 * cost) / 100;
		printf_s("\nYour total sum: %f", midcost);
	}
	else if (mass < 5)
	{
		printf_s("\nTotal weight: %f", mass);
		printf_s("\nDelivery cost= $1");
		cost += 1;
		printf_s("\nYour total sum: %f", cost);
	}
	else if (mass > 4 && mass < 21)
	{
		printf_s("\nTotal weight: %f", mass);
		printf_s("\nDelivery cost= $3");
		cost += 3;
		printf_s("\nYour total sum: %f", cost);
	}
	else if (mass > 20)
	{
		printf_s("\nTotal weight: %f", mass);
		printf_s("\nDelivery cost =$10 plus $2 for each kg of overweight");
		midcost = 10 + (mass - 20) * 2;
		printf_s("\nYour total sum: %f", midcost);
	}
}

void Basket(float cost1, float mass1, float cost2, float mass2, float cost3, float mass3)
{
	printf_s("\nBASKET:\n Mandarins (weight= %f, cost= %f)", mass1, cost1);
	printf_s("\n Peaches (weight= %f, cost= %f)", mass2, cost2);
	printf_s("\n Grapes (weight= %f, cost= %f)", mass3, cost3);
}

float Cost(float value, float mass)
{
	float cost = value * mass;
	return cost;
}

int Menu(int o)
{
	o = 0;
	printf_s("Please choose:\n 1.Order mandarins\n 2.Order peaches\n 3.Order grapes\n 4.Basket\n 5.Calculation of order value\n 6.Feedback\n 7.Exit\n \nchoice:  ");
	scanf_s("%d", &o);
	if (o > 7)
	{
		printf_s("\nWrong input, try again\n\n");
		return Menu(o);
	}
	return o;
}

int Choice()
{
	int choice = 0;
	printf_s("\nWant to continue ordering? \n1.Yes 2.No\n");
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		return Menu(choice);
	}
	else if (choice == 2)
	{
		choice = 0;
		printf_s("\n Would you like to count a total sum or go back to menu?\n 1.Count 2.Menu\n ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			generalCost = mandarinCost + peachCost + grapeCost;
			generalMass = mandarinMass + peachMass + grapeMass;
			GeneralMassCost(generalCost, generalMass);
		}
		else if (choice == 2)
		{
			return Menu(choice);
		}
		else if (choice != 1 && choice != 2)
		{
			printf_s("\nWrong input, try again\n\n");
			Choice();
		}
	}
	else if (choice != 1 && choice != 2)
	{
		printf_s("\nWrong input, try again\n\n");
		Choice();
	}
}

void main(void)
{
	int choice = 0, choice1;
startAgain:
	switch (Menu(choice))
	{
	case 1:
		printf_s("\nPLease enter the weight of mandarins (in kg): ");
		scanf_s("%f", &mandarinMass);
		mandarinCost = Cost(1.14, mandarinMass);
		Choice();
		break;
	case 2:
		printf_s("\nPLease enter the weight of peaches (in kg): ");
		scanf_s("%f", &peachMass);
		peachCost = Cost(1, peachMass);
		Choice();
		break;
	case 3:
		printf_s("\nPLease enter the weight of grapes (in kg): ");
		scanf_s("%f", &grapeMass);
		grapeCost = Cost(1.28, grapeMass);
		Choice();
		break;
	case 4:
		choice1 = 0;
		Basket(mandarinCost, mandarinMass, peachCost, peachMass, grapeCost, grapeMass);
		Choice();
		break;
	case 5:
		generalCost = mandarinCost + peachCost + grapeCost;
		generalMass = mandarinMass + peachMass + grapeMass;
		GeneralMassCost(generalCost, generalMass);
		Choice();
		break;
	case 6:
		printf_s("\n Shop name: eFruit\n License number: XXXXXXXX-XXXXXXX-XXXXXX\n Contact info: eFruitFeedback@gmail.com\n");
		printf_s("\n Go back to menu? \n1.Yes 2.No\n");
		scanf_s("%d", &choice1);
		if (choice1 == 1)
		{
			goto startAgain;
		}
		break;
	}

endOfOrder: printf_s("\nTHANK YOU FOR CHOOSING eFRUIT");
}
