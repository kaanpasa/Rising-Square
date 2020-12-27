

                                            //Kaan Pasa//


#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

float xm=0.0, ym=-3.0;                      // Player's x and y movement
float xen1=0.0, yen1=0.0;                   // X and Y movement of enemy 1
float xen2=0.0, yen2=0.0;                   // X and Y movement of enemy 2
float xen3=0.0, yen3=0.0 ;                  // X and Y movement of enemy 3
float xen4=0.0, yen4=0.0 ;                  // X and Y movement of enemy 4
float speed1=0.15, speed2=0.3,
      speed3=0.14 , speed4=0.10;            // Speeds of enemies
int ceren=0;                                // variable for movement
float point=3;                              // Point for losing game
bool i=false;                               // Indicator for stopping objects

void line(){                                // line function for start and finish
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f(-24.0, 5.8, -5.0);
		glVertex3f( 24.0, 5.8, -5.0);
		glVertex3f( 24.0, 5.7, -5.0);
		glVertex3f(-24.0, 5.7, -5.0);
	glEnd();
}

void player(){                              // Player's function
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f(-0.3+xm, 0.3+ym, -5.0);
		glVertex3f( 0.3+xm, 0.3+ym, -5.0);
		glVertex3f( 0.3+xm,-0.3+ym, -5.0);
		glVertex3f(-0.3+xm,-0.3+ym, -5.0);
	glEnd();
	if(ceren==1 && ym<=5.5){                //Player's movement section
        ym+=0.1;
	}else if(ceren==2 && xm<=4.1){
        xm+=0.1;
	}else if(ceren==3 && ym>-5.5){
        ym-=0.1;
	}else if(ceren==4 && xm>-4){
        xm-=0.1;
	}

	if(ym>=5.5){                            // Collision detection section
        xm=0.0;
        ym=-3.0;
        ceren=0;
        speed1*=1.2;
        speed2*=1.2;
        speed3*=1.2;
        speed4*=1.2;
        point+=1;
	}else if(((xm>=xen1+2.1 && xm<=xen1+3.1) && (ym>=yen1-0.5 && ym<=yen1+0.5)) ||
             ((xm>=xen2+2.0 && xm<=xen2+3.0) && (ym>=yen2+2.2 && ym<=yen2+3.2)) ||
             ((xm>=xen3-2.6 && xm<=xen3-1.6) && (ym>=yen3+1.1 && ym<=yen3+2.1)) ||
             ((xm>=xen4+2.6 && xm<=xen4+3.6) && (ym>=yen4+3.1 && ym<=yen4+4.1)) ){
        xm=0.0;
        ym=-3.0;
        ceren=0;
        speed1*=0.75;
        speed2*=0.75;
        speed3*=0.75;
        speed4*=0.75;
        point-=1;
	}
}

void enemy1(){                              // First enemy's function
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f( 2.3+xen1, 0.3+yen1, -5.0);
		glVertex3f( 2.9+xen1, 0.3+yen1, -5.0);
		glVertex3f( 2.9+xen1,-0.3+yen1, -5.0);
		glVertex3f( 2.3+xen1,-0.3+yen1, -5.0);
	glEnd();
    if(speed1>0 && !i){                     // Section for movement of enemy
        if(xen1<=1.8){
            xen1+=speed1;
        }else
            speed1*=-1;
    }
    if(speed1<0 && !i){
        if(xen1>=-7.0){
            xen1+=speed1;
        }else
            speed1*=-1;
    }
}

void enemy2(){                              // Second enemy's function
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f( 2.8+xen2, 3.0+yen2, -5.0);
		glVertex3f( 2.2+xen2, 3.0+yen2, -5.0);
		glVertex3f( 2.2+xen2, 2.4+yen2, -5.0);
		glVertex3f( 2.8+xen2, 2.4+yen2, -5.0);
	glEnd();
    if(speed2>0 && !i){                     // Section for movement of enemy
        if(xen2<=1.9){
            xen2+=speed2;
        }else
            speed2*=-1;
    }
    if(speed2<0 && !i){
        if(xen2>=-6.8){
            xen2+=speed2;
        }else
            speed2*=-1;
    }
}

void enemy3(){                              // Third enemy's function
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f(-2.4+xen3, 1.3+yen3, -5.0);
		glVertex3f(-1.8+xen3, 1.3+yen3, -5.0);
		glVertex3f(-1.8+xen3, 1.9+yen3, -5.0);
		glVertex3f(-2.4+xen3, 1.9+yen3, -5.0);
	glEnd();
	if(speed3>0 && !i){                     // Section for movement of enemy
        if(yen3<=3.8){
            yen3+=speed3;
        }else
            speed3*=-1;
	}
	if(speed3<0 && !i){
        if(yen3>=-3.5){
            yen3+=speed3;
        }else
            speed3*=-1;
	}
}

void enemy4(){                              // Fourth enemy's function
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f( 3.4+xen4, 3.3+yen4, -5.0);
		glVertex3f( 2.8+xen4, 3.3+yen4, -5.0);
		glVertex3f( 2.8+xen4, 3.9+yen4, -5.0);
		glVertex3f( 3.4+xen4, 3.9+yen4, -5.0);
	glEnd();
	if(speed4>0 && !i){                     // Section for movement of enemy
        if(yen4<=1.8){
            yen4+=speed4;
        }else
            speed4*=-1;
	}
	if(speed4<0 && !i){
        if(yen4>=-5.5){
            yen4+=speed4;
        }else
            speed4*=-1;
	}
}

void gameover(){                            // Function for situation of fail
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f(-3.0,-3.0, -4.98);
		glVertex3f( 3.0, 3.0, -4.98);
		glVertex3f( 3.3, 2.7, -4.98);
		glVertex3f(-2.7,-3.3, -4.98);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-3.0, 2.7, -4.98);
		glVertex3f( 3.0,-3.3, -4.98);
		glVertex3f( 3.3,-3.0, -4.98);
		glVertex3f(-2.7, 3.0, -4.98);
	glEnd();
	i=true;
}

void win(){                                 // Function for situation of win
    glColor3f(0.0,1.0,0.0);
    glTranslatef(0.0,0.0,-0.1);
    glBegin(GL_QUADS);
		glVertex3f(-2.0,-2.0, -5.0);
		glVertex3f( 4.0, 3.0, -5.0);
		glVertex3f( 4.3, 2.7, -5.0);
		glVertex3f(-1.7,-2.3, -5.0);
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(-1.7,-2.3, -5.0);
		glVertex3f(-4.0, 0.1, -5.0);
		glVertex3f(-3.7, 0.4, -5.0);
		glVertex3f(-1.7,-1.7, -5.0);
	glEnd();
	i=true;
}

void bar(){                                 // Function for background of Life Bar
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0.0,-1.0,-0.01);
    glBegin(GL_QUADS);
		glVertex3f(-4.0,-3.8, -5.0);
		glVertex3f( 4.0,-3.8, -5.0);
		glVertex3f( 4.0,-4.1, -5.0);
		glVertex3f(-4.0,-4.1, -5.0);
	glEnd();
}

void lifebar(){                             // Function that indicates player's life
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
		glVertex3f(-4.0,-3.8, -4.99);
		glVertex3f( (point-5.0)*8/10,-3.8, -4.99);
		glVertex3f( (point-5.0)*8/10,-4.1, -4.99);
		glVertex3f(-4.0,-4.1, -4.99);
	glEnd();
}

void init()
{
    glClearColor(0.35, 0.55, 0.75, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,480.0/640.0,1.0,500.0);
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

        glTranslatef(0.0,0.0,-10.0);
        line();

        glPushMatrix();
        glTranslatef(0.0,-8.0,0.0);
        line();
        glPopMatrix();

        player();
        enemy1();
        enemy2();
        enemy3();
        enemy4();

        if(point<=0.0){                     //Winning and losing situations
            gameover();
        }else if(point>=10.0){
            win();
        }

        if(point>0){
        bar();
        lifebar();
        }
}


int main(int argc, char* args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_SetVideoMode(480,640,32,SDL_SWSURFACE|SDL_OPENGL);

    int loop=1;
    SDL_Event myevent;
    Uint8* keystate = SDL_GetKeyState(NULL);
    init();
    while (loop==1)
    {
        while (SDL_PollEvent(&myevent))
        {
            switch(myevent.type)
            {
                case SDL_QUIT:
                loop=0;
                break;

                case SDL_KEYDOWN:
                if (myevent.key.keysym.sym==SDLK_UP && !i){
                        ceren=1;
                };
                if (myevent.key.keysym.sym==SDLK_RIGHT && !i){
                        ceren=2;
                };
                if (myevent.key.keysym.sym==SDLK_DOWN && !i){
                        ceren=3;
                };
                if (myevent.key.keysym.sym==SDLK_LEFT && !i){
                        ceren=4;
                };
                break;
            }
        }
        display();
        SDL_GL_SwapBuffers();
    }
    SDL_Quit();
    return 0;
}
