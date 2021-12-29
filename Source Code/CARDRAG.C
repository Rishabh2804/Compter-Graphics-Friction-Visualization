#include "GRAPH.H"

const double Kf = 0.1;	  // Coefficient of kinetic friction
const double g = 9.80665; // Acceleration due to gravity

void car(int, int, int, int);
void road(int, int);
void night();
void dust(int);
void myinfo();
void project_info();

int main()
{
	int gd = DETECT, gm, x, x0;
	const double a = Kf * g; // Resultant retardation
	double dx, v, v0, v_avg, t, T;
	char *msg;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	project_info();
	
	printf("\n\t\t\t\tWelcome!\n\n");
	printf("This following screen is a visualisation of a moving car ");
	printf("coming to rest\ndue to frictional force of rough road\n\n");
	printf("Real - time details of instantaneous velocity of car and ");
	printf("average speed are also displayed.\n\n");
	printf("The coefficient of friction of road is set to 0.1\n");
	
	v0 = 35;
	printf("Enter initial speed of car (v0) : ");
	scanf("%lf", &v0);

	// Initial x-coordinate of car.
	x0 = getmaxx();

	// As the car moves in right to left direction,
	// the x-coordinate decreases. Hence, the initial x-coordinate is set to
	// the rightmost x-coordinate of the screen.
	x = x0;

	// T is the total time taken by friction to bring the car to rest.
	// It is calculated by solving the equation:
	// 		0 = v0 - a * T      (-ve sign for retardation)
	t = 0;
	T = v0 / a;

	v = v0;
	v_avg = v0;

	for (t = 0; t < T + 2; t++)
	{
		cleardevice();

		car(x, 0, LIGHTCYAN, YELLOW);
		road(0, YELLOW);
		night();

		if (t >= T - 5)
			dust(x);

		// x-coordinate of car changes by dx units,
		// where dx can be obtained by derivative of following equation:
		//    x = v0 * t - 1/2 * a * t * t
		//    dx/dt = v0 - a * t
		//    dx = v0 - a * t   (dt = 1)

		dx = v0 - a * t;
		x -= dx;
		v = (dx < 0) ? 0 : dx;
		v_avg = (dx < 0) ? v_avg : (x0 - x) / t;

		sprintf(msg, "Inst. velocity = %lf,    Avg. velocity  =  %lf", v, v_avg);
		setcolor(LIGHTRED);
		outtextxy(10, 400, msg);

		if (kbhit())
		{
			break;
		}

		delay(50);
	}

	delay(100);
	credit();

	getch();
	closegraph();
	return 0;
}

void credit()
{
	setcolor(LIGHTGREEN);
	rec(40, 30, 300, 80, YELLOW);
	settextstyle(0, 0, 1);
	outtextxy(50, 35, "CREATED BY: ");

	settextstyle(0, 0, 1);
	outtextxy(150, 50, "Gaurav, Rishabh");
}

void project_info()
{
	setcolor(YELLOW);
	rec(40, 400, 610, 450, YELLOW);
	settextstyle(0, 0, 2);
	outtextxy(60, 416, "PROJECT :");
	settextstyle(7, 0, 2);
	outtextxy(210, 410, "\"CAR STOPPING DUE TO FRICTION\"");
}

void road(int i, int COLOR)
{
	for (i = 0; i < getmaxx(); i += 3)
	{
		int sy = 390, ey = 388;
		if (i % 2 != 0)
		{
			sy = 388, ey = 390;
		}

		lineDDA(i, sy, i + 3, ey, COLOR);
	}
}

void dust(int i)
{
	int k;
	for (k = 0; k < 80; ++k)
		putpixel(i + 100 + random(280), getmaxy() - 100 + random(10), BROWN);
}

void night()
{
	int x = getmaxx() - 80, y = 80, x1, y1, i;
	int r = 35;

	setcolor(DARKGRAY);

	arc(x, y, 115, 335, r);
	arc(x + 15, y - 15, 153, 296, r);

	for (i = 0; i <= 50; i++)
	{
		x1 = rand() % getmaxx();
		y1 = rand() % 380;
		putpixel(x1, y1, 15);
	}

	floodfill(x - 10, y + 10, DARKGRAY);
}

void car(int x, int y, int BODY_COLOR, int TYRE_COLOR)
{
	// BODY
	lineDDA(40 + x, 370 + y, 90 + x, 370 + y, BODY_COLOR);
	lineDDA(40 + x, 340 + y, 40 + x, 370 + y, BODY_COLOR);
	lineDDA(130 + x, 370 + y, 220 + x, 370 + y, BODY_COLOR);
	lineDDA(260 + x, 370 + y, 320 + x, 370 + y, BODY_COLOR);
	lineDDA(320 + x, 330 + y, 320 + x, 370 + y, BODY_COLOR);

	lineDDA(85 + x, 325 + y, 40 + x, 340 + y, BODY_COLOR);
	lineDDA(85 + x, 325 + y, 130 + x, 280 + y, BODY_COLOR);
	lineDDA(130 + x, 280 + y, 240 + x, 280 + y, BODY_COLOR);
	lineDDA(240 + x, 280 + y, 270 + x, 310 + y, BODY_COLOR);
	lineDDA(270 + x, 310 + y, 320 + x, 330 + y, BODY_COLOR);

	// WINDOWS
	lineDDA(192 + x, 292 + y, 192 + x, 327 + y, BODY_COLOR);
	lineDDA(192 + x, 327 + y, 267 + x, 327 + y, BODY_COLOR);
	lineDDA(232 + x, 292 + y, 267 + x, 327 + y, BODY_COLOR);
	lineDDA(192 + x, 292 + y, 232 + x, 292 + y, BODY_COLOR);

	lineDDA(102 + x, 327 + y, 182 + x, 327 + y, BODY_COLOR);
	lineDDA(102 + x, 327 + y, 137 + x, 292 + y, BODY_COLOR);
	lineDDA(137 + x, 292 + y, 182 + x, 292 + y, BODY_COLOR);
	lineDDA(182 + x, 292 + y, 182 + x, 327 + y, BODY_COLOR);

	// WHEELS
	setcolor(BODY_COLOR);
	arc(110 + x, 370 + y, 0, 180, 21);
	arc(240 + x, 370 + y, 0, 180, 21);

	circleMid(110 + x, 370 + y, 17, TYRE_COLOR);
	circleBres(110 + x, 370 + y, 2, TYRE_COLOR);

	circleMid(240 + x, 370 + y, 17, TYRE_COLOR);
	circleBres(240 + x, 370 + y, 2, TYRE_COLOR);
}
