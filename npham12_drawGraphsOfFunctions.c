/* Draw graphs of functions
 Billy Pham*/

/*This program will draw (rather rough) graphs of functions. The function being graphed and the region of the graph to be displayed will be hardcoded into the program, but in such a way that the program can easily be modified and recompiled to graph different functions and display different sized regions of the graph
 */
#include<stdio.h>
#include<string.h>
#include<math.h>
#define X_SEMIRANGE 3
#define Y_SEMIRANGE 2

/*prototype*/
void blankGraph(char temp[][X_SEMIRANGE*20+1]);
void setGraph(char temp[][X_SEMIRANGE*20+1]);
double function(double x);
int get_round(double k);
char graph[Y_SEMIRANGE*20 +1][X_SEMIRANGE*20+1];

int r, c;

 /* calling main function*/
int main()
{
	setGraph(graph);
	/* print out the completed graph*/
	for(r = 0; r < Y_SEMIRANGE*20 + 1; r++)
	{
		for(c = 0; c < X_SEMIRANGE*20 + 1; c++)
		 	printf("%c",graph[r][c]);
		printf("\n");
	}	 	 	 
	return 0;
} 

 /* calling draw_graph function*/
void blankGraph(char temp[][X_SEMIRANGE*20+1])
{
	/*reset data in array temp to 0*/
	memset(temp,' ', (Y_SEMIRANGE*20+1)*(X_SEMIRANGE*20 +1));
	for(r = 0; r < (Y_SEMIRANGE*20)+1; r++)
	{
		/* create a graph*/
		for(c = 0; c < (X_SEMIRANGE*20)+1;  c++)
		{
			/* calling method set 0 at all index in graph*/
			if (r == (Y_SEMIRANGE*10))
			 	temp[r][c] = '-';			
			if (c == (X_SEMIRANGE*10))
				temp[r][c] = '|';	
		}
	}
}

/* calling function f*/
double function(double x)
{
	double fx;
	fx = x*x;
	return fx;
}

/* calling round method*/
int get_round(double k)
{
   int t;                                             
	if (k >= 0)				
		t =(int)(k + 0.51);
	else
		t =(int)(k - 0.51);
}

/* insert graph */
void setGraph(char temp[][X_SEMIRANGE*20+1])
{
	double x, y;
	blankGraph(temp);
	/* get value from f(x) and fill in blank graph*/
	for(x = -X_SEMIRANGE; x < (X_SEMIRANGE*20+1)/(double)20; x += 0.1)
	{
		y = function(x);
		int i,j;
		/*round value of x and y*/
		j = get_round(y*10);
		i = get_round(x*10);
		/*plug points "o" at value of "x" and "y" on the graph*/
		if(  -Y_SEMIRANGE*10 <= j && j <= Y_SEMIRANGE*10)
			temp[Y_SEMIRANGE*10 - j][X_SEMIRANGE*10 + i] = 'o';
	}
}
