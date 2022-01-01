# Source Code
<!-- Font size for the entire README -->
<font size = "3"> 

This folder contains the entire source code of this project.

Contents of the directory are listed below :- 

<details> <summary> <a href=https://github.com/Rishabh2804/Compter-Graphics-Friction-Visualization/blob/main/Source%20Code/README.md> &nbsp;README.md</a>
</summary> 

What are you trying to do, bud 🤨🤔?<br>

This is the very file you are currently reading!! 😂😂


</details>

<details> <summary><a href=https://github.com/Rishabh2804/Compter-Graphics-Friction-Visualization/blob/main/Source%20Code/GRAPH.H> &nbsp;GRAPH.H </a></summary> 

   This file contains the definitions of the user - functions used to draw the fundamental graphics.

   The definitions and definitions are as follows :-

  - <b>void lineDDA(int x1, int y1, int x2, int y2, int COLOR)</b>   
  
	    Draws a line of specified COLOR from (x1, y1) to (x2, y2) using DDA line drawing algorithm.

  - <b>void lineBres(int x1, int y1, int x2, int y2, int COLOR)</b>
  
	    Draws a line of specified COLOR from (x1, y1) to (x2, y2) using Bresenham line drawing algorithm.

  - <b>void circleMid(int xc, int yc, int r, int COLOR)</b> 
    
	    Draws a circle of radius r centered at (xc, yc) using Midpoint algorithm.

  - <b>void circleBres(int xc, int yc, int r, int COLOR)</b>

	    Draws a circle of radius r centered at (xc, yc) using Bresenham algorithm.

</details>

<details> <summary> <a href=https://github.com/Rishabh2804/Compter-Graphics-Friction-Visualization/blob/main/Source%20Code/CARDRAG.C> &nbsp;CARDRAG.C</a> </summary>

  This file contains the actual driver code of the visualization.
  
  The utility functions declared and defined are as follows :-

  - <b>void car(int x, int y, int BODY_COLOUR, int TYRE_COLOUR) </b>

	    Draws a car onto the view-port with specified peramaters:- 
      - x, y : The respective rear and base coordinates of the car's body.
      - BODY_COLOUR : The colour of the car's body.
      - TYRE_COLOUR : The colour of the car's tyres.
      
  - <b>void road(int height , int COLOR)</b>

	    Draws a rough gravel path at specified height and of specified COLOR.

  - <b>void night()</b>
  
	    Draws a complete night view with sky full of stars and an adorable moon.
      
  - <b>void dust()</b>
  
	    Visualizes the effect of dust-particles at time of stopping.
    
  - <b>void myinfo()</b>
  
	    Introduces the creator of the Project (Of Course ME!).

  - <b>void project info()</b>

	    Introduces the Project Name in a beautiful way!
    







