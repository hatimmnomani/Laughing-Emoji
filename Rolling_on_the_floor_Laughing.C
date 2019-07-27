/*
Hatim Nomani AU17B1018
Assignment 2- Emoji
*/
#include<math.h>
#include <conio.h>
#include<stdlib.h>
#include<graphics.h>
#include <stdio.h>
void dda(float xi,float yi,float xf,float yf,int c);
void bf4(int x,int y,int bcolor,int ncolor);
void ff4(int x,int y,int ocolor,int ncolor){
      if(getpixel(x,y)==ocolor){
	putpixel(x,y,ncolor);
	ff4(x+1,y,ocolor,ncolor);
	ff4(x-1,y,ocolor,ncolor);
	ff4(x,y+1,ocolor,ncolor);
	ff4(x,y-1,ocolor,ncolor);
	//delay(10);
      }
      else{
	return;
      }
}
void c1(int x,int y,int r,int c){
	int xnext,ynext,p,xm,ym,xd,yd;
	//printf("Enter the center for the circle ");
	//scanf("%d %d",&x,&y);
	//printf("Enter the radius for the circle ");
	//scanf("%d",&r);
	p=3-2*r;
	ynext=r;
	//c2(r);
	//xnext=0;
	xm=getmaxx();
	ym=getmaxy();
	//line(0,ym/2,xm,ym/2);
	//line(xm/2,0,xm/2,ym);
	xd=xm/2+x;
	yd=ym/2+y;
	//putpixel(x+xm/2,y+ym/2,RED);
	for(xnext=0;xnext<=ynext;xnext++){
		putpixel((xnext)+xd,(ynext)+yd,c);
		putpixel((ynext)+xd,(xnext)+yd,c);
		putpixel((-xnext)+xd,(ynext)+yd,c);
		putpixel((xnext)+xd,(-ynext)+yd,c);
		putpixel((-xnext)+xd,(-ynext)+yd,c);
		putpixel((-ynext)+xd,(-xnext)+yd,c);
		putpixel((-ynext)+xd,(xnext)+yd,c);
		putpixel((ynext)+xd,(-xnext)+yd,c);
		//delay(10);
		if(p>0){
			p=p-4*ynext+4*xnext+10;
			ynext--;
		}
		else{
			p=p+4*xnext+6;
		}
	}
	//getch();
	//floodfill(x+xm,y+ym,14);
	//fillellipse( x+xm, y+xm,r,5);
}
void c3(int x,int y,int r,int c,int a,int b,int m){
	int xnext,ynext,p,xm,ym,xd,yd;
	//printf("Enter the center for the circle ");
	//scanf("%d %d",&x,&y);
	//printf("Enter the radius for the circle ");
	//scanf("%d",&r);
	p=3-2*r;
	ynext=r;
	//c2(r);
	//xnext=0;
	xm=getmaxx();
	ym=getmaxy();
	//line(0,ym/2,xm,ym/2);
	//line(xm/2,0,xm/2,ym);
	xd=xm/2+x;
	yd=ym/2+y;
       //	putpixel(x+xm/2,y+ym/2,RED);
	for(xnext=0;xnext<=ynext;xnext++){
		if (m==0){
		putpixel(((xnext)+xd)*a,((ynext)+yd)*b,c);
		}else if(m==1){
		putpixel(((ynext)+xd)*a,((xnext)+yd)*b,c);
		}
		//putpixel((-xnext)+xd,(ynext)+yd,c);
		//putpixel((xnext)+xd,(-ynext)+yd,c);
		//putpixel((-xnext)+xd,(-ynext)+yd,c);
		//putpixel((-ynext)+xd,(-xnext)+yd,c);
		//putpixel((-ynext)+xd,(xnext)+yd,c);
		//putpixel((ynext)+xd,(-xnext)+yd,c);
		//delay(10);
		if(p>0){
			p=p-4*ynext+4*xnext+10;
			ynext--;
		}
		else{
			p=p+4*xnext+6;
		}
	}
	//getch();
	//floodfill(x+xm,y+ym,14);
	//fillellipse( x+xm, y+xm,r,5);
}
//LEFT TEAR (algorithm)
void dew(int x, int y){
	c1(x-1-getmaxx()/2,y+5-getmaxy()/2,3,11);
	dda(x,y,x+2,y+5,11);
	dda(x,y,x-4,y+5,11);
	putpixel(x-1-getmaxx()/2,y+5-getmaxy()/2,RED);
	bf4(x-1,y+5,1,11);
}
//RIGHT TEAR (algorithm)
void dew2(int x, int y){
	c1(x+6-getmaxx()/2,y-2-getmaxy()/2,3,11);
	dda(x,y,x+6,y+1,11);
	dda(x,y,x+6,y-5,11);
	putpixel(x+6,y-2,RED);
	bf4(x+6,y-2,1,11);
	dda(x,y,x+5,y-3,11);
	//dda(x,y,x+5,y+2,9);
}
//LEFT TEAR (inbuilt)
void idew(int x, int y){
	setcolor(11);
	//c1(x-1-getmaxx()/2,y+5-getmaxy()/2,3,9);
	 ellipse(x-1,y+5,0,360,3,3);
	line(x,y,x+2,y+5);
	line(x,y,x-4,y+5);
	//putpixel(x-1-getmaxx()/2,y+5-getmaxy()/2,RED);
	bf4(x-1,y+5,1,9);
}
//RIGHT TEAR (inbuilt)
void idew2(int x, int y){
	setcolor(11);
	//c1(x+6-getmaxx()/2,y-2-getmaxy()/2,3,9);
	ellipse(x+6,y-2,0,360,3,3);
	line(x,y,x+6,y+1);
	line(x,y,x+6,y-5);
	//putpixel(x+6,y-2,RED);
	bf4(x+6,y-2,1,9);
	line(x,y,x+5,y-3);
	//dda(x,y,x+5,y+2,9);
}
void drop(int x,int y){
      //setcolor(CYAN);
      dda(x+6,y-5,x+13,y-8,0);
      dda(x+6,y-5,x+8,y-13,0);
      dda(x+1,y,x+13,y-8,0);
      dda(x+1,y,x+8,y-13,0);
      /*Lines to color*/
      dda(x+2,y-1,x+13,y-8,0);
      dda(x+2,y-1,x+8,y-13,0);
      dda(x+3,y-3,x+13,y-8,0);
      dda(x+3,y-3,x+8,y-13,0);
      dda(x+4,y-3,x+13,y-8,0);
      dda(x+4,y-3,x+8,y-13,0);

      dda(x-5,y+7,x-14,y+12,0);
      dda(x-5,y+7,x-9,y+19,0);
      dda(x-2,y+4,x-14,y+12,0);
      dda(x-2,y+4,x-9,y+19,0);
      /*lines to color*/
      dda(x-3,y+5,x-14,y+12,0);
      dda(x-3,y+5,x-9,y+19,0);
      dda(x-4,y+6,x-14,y+12,0);
      dda(x-4,y+6,x-9,y+19,0);

      dew(x-9,y+19);
      //putpixel(x+13,y-8,RED);
      dew2(x+13,y-8);
      //ff4(x-4,y+6,getpixel(x-4,y+6),0);
      //c3(x-14-getmaxx()/2,y+14-getmaxy()/2,5,CYAN,1,1,1);
}
void drop2(int x,int y){
      //setcolor(CYAN);
      setcolor(0);
      /*RIGHT EYE*/
      line(x+6,y-5,x+13,y-8);
      line(x+6,y-5,x+8,y-13);
      line(x+1,y,x+13,y-8);
      line(x+1,y,x+8,y-13);
      /*Lines to color*/
      line(x+2,y-1,x+13,y-8);
      line(x+2,y-1,x+8,y-13);
      line(x+3,y-3,x+13,y-8);
      line(x+3,y-3,x+8,y-13);
      line(x+4,y-3,x+13,y-8);
      line(x+4,y-3,x+8,y-13);
      /*LEFT EYE*/
      line(x-5,y+7,x-14,y+12);
      line(x-5,y+7,x-9,y+19);
      line(x-2,y+4,x-14,y+12);
      line(x-2,y+4,x-9,y+19);
      /*lines to color*/
      line(x-3,y+5,x-14,y+12);
      line(x-3,y+5,x-9,y+19);
      line(x-4,y+6,x-14,y+12);
      line(x-4,y+6,x-9,y+19);

      idew(x-9,y+19);
      idew2(x+13,y-8);
}
void c2(int x,int y,int r){
	int xnext,ynext,p,xm,ym,xd,yd;
	p=3-2*r;
	ynext=r;
	xm=getmaxx();
	ym=getmaxy();
	xd=xm/2+x;
	yd=ym/2+y;
	putpixel(x+xm/2,y+ym/2,RED);
	for(xnext=0;xnext<=ynext;xnext++){
		putpixel((xnext)+xd,(ynext)+yd,0);
		putpixel((ynext)+xd,(xnext)+yd,0);
		putpixel((-xnext)+xd,(ynext)+yd,0);
		putpixel((ynext)+xd,(-xnext)+yd,0);

		if(p>0){

			p=p-4*ynext+4*xnext+10;
			ynext--;
		}
		else{
			p=p+4*xnext+6;
		}
		if(xnext==ynext){
			setcolor(0);
			//printf("HII");
			dda(-xnext+xd,ynext+yd,xnext+xd,-ynext+yd,0);
			ff4(xd+1,yd,getpixel(xd+1,yd),0);
			dda(-xnext+xd+1,ynext+yd,xnext+xd,-ynext+yd+1,15);
			dda(-xnext+xd+1,ynext+yd,-xnext+xd+3,ynext+yd+2,15);
			dda(xnext+xd+2,-ynext+yd+3,xnext+xd,-ynext+yd+1,15);
			dda(xnext+xd+2,-ynext+yd+3,-xnext+xd+3,ynext+yd+2,15);
			//putpixel(-xnext+xd+3,ynext+yd,RED);
			ff4(-xnext+xd+3,ynext+yd,getpixel(-xnext+xd+3,ynext+yd),15);
			putpixel(xnext+xd,ynext+yd,RED);
			//c3(xnext+xd,ynext+yd,4,RED,-1,-1,1);
			setcolor(12);
			ellipse(xnext+xd,ynext+yd,45,225,7,7);
			setcolor(WHITE);
			ff4(xnext+xd,ynext+yd-2,getpixel(xnext+xd,ynext+yd-2),12);
		}
	}


	//setcolor(15);
       //ff4();
       //getch();
	//floodfill(x+xm,y+ym,14);
	//fillellipse( x+xm, y+xm,r,5);
}
void ff8(int x,int y,int ocolor,int ncolor){
      if(getpixel(x,y)==ocolor){
	putpixel(x,y,ncolor);
	ff8(x+1,y,ocolor,ncolor);
	ff8(x-1,y,ocolor,ncolor);
	ff8(x,y+1,ocolor,ncolor);
	ff8(x,y-1,ocolor,ncolor);
	ff8(x-1,y-1,ocolor,ncolor);
	ff8(x+1,y-1,ocolor,ncolor);
	ff8(x+1,y+1,ocolor,ncolor);
	ff8(x-1,y+1,ocolor,ncolor);
	//delay(10);
      }
      else{
	return;
      }
}

void dda(float xi,float yi,float xf,float yf,int c){
	int x,i;
	float dy,dx,p;
	float xc,yc;
	dy=(yf-yi);
	dx=(xf-xi);

	/*
	Saving the maximum of the two differentials.
	*/

	if(abs(dy)>=abs(dx)){
		p=abs(dy);
	}else{
		p=abs(dx);
	}

	xc=(dx/p);
	yc=(dy/p);
	x = ((xc)*10);
	xc = (float)x/10;
	x = ((yc)*10);
	yc=(float)x/10;
	for(i=0;i<=p;i++){
		if(xi>0&&yi>0){   // rounding according to x and y values depending on positive negative

			putpixel(((int)(xi+0.5)),((int)(yi+0.5)),c);
		} else if(xi>0&&yi<0){
			putpixel(((int)(xi+0.5)),((int)(yi-0.5)),c);
		} else if (xi<0&&yi>0){
			putpixel(((int)(xi-0.5)),((int)(yi+0.5)),c);
		} else{
			putpixel(((int)(xi-0.5)),((int)(yi-0.5)),c);
		}

		xi=xi+xc;
		yi=yi+yc;
	}

}
void bf4(int x,int y,int bcolor,int ncolor){
      if(getpixel(x,y)!=bcolor&&getpixel(x,y)!=ncolor){
	putpixel(x,y,ncolor);
	bf4(x+1,y,bcolor,ncolor);
	bf4(x-1,y,bcolor,ncolor);
	bf4(x,y+1,bcolor,ncolor);
	bf4(x,y-1,bcolor,ncolor);
	//delay(10);
      }
}
void bf8(int x,int y,int ocolor,int ncolor){
      if(getpixel(x,y)!=ocolor&&getpixel(x,y)!=ncolor){
	putpixel(x,y,ncolor);
	bf8(x+1,y,ocolor,ncolor);
	bf8(x-1,y,ocolor,ncolor);
	bf8(x,y+1,ocolor,ncolor);
	bf8(x,y-1,ocolor,ncolor);
	bf8(x-1,y-1,ocolor,ncolor);
	bf8(x+1,y-1,ocolor,ncolor);
	bf8(x+1,y+1,ocolor,ncolor);
	bf8(x-1,y+1,ocolor,ncolor);
	//delay(10);
      }
      else{
	return;
      }
}
void algo(){
	int xz,yz,x,y,x1,x2,xm,ym;
	clrscr();
	printf("\n\t\tDrawing Emoji Using Algorithms");
	xm=getmaxx()/2;
	ym=getmaxy()/2;
	x=25;
	y=25;
	dda(xm-x-5,ym-y-5,xm-x-5,ym+y+5,0);
	dda(xm-x-5,ym+y+5,xm+x+5,ym+y+5,0);
	dda(xm+x+5,ym+y+5,xm+x+5,ym-y-5,0);
	dda(xm+x+5,ym-y-5,xm-x-5,ym-y-5,0);
	c1(0,0,x,14);
	ff4(xm,ym,getpixel(xm,ym),14);
	c2(2,2,x-6);
	drop(xm-5,ym-6);
	ff4(xm-x,ym-y,getpixel(xm-x,ym-y),0);
	getch();
}
void builtin(){
	int xz,yz,x,y,x1,x2,xm,ym;
	clrscr();
	printf("\n\t\tDrawing Emoji Using Built in function");
	xm=getmaxx()/2;
	ym=getmaxy()/2;
	x=25;
	y=25;
	setcolor(0);
	line(xm-x-5,ym-y-5,xm-x-5,ym+y+5);
	line(xm-x-5,ym+y+5,xm+x+5,ym+y+5);
	line(xm+x+5,ym+y+5,xm+x+5,ym-y-5);
	line(xm+x+5,ym-y-5,xm-x-5,ym-y-5);
	setcolor(14);
	ellipse(xm,ym,0,360,x,y);
	ff4(xm,ym,getpixel(xm,ym),14);
	c2(2,2,x-6);
	drop2(xm-5,ym-6);
	ff4(xm-x,ym-y,getpixel(xm-x,ym-y),0);
	getch();
}
int main(){
	int gd=DETECT,gm,i,c;
	clrscr();
	initgraph(&gd,&gm,"C:\TURBOC3\BGI");
	i=1;
	while(i!=0){
		clrscr();
		printf("\n\t\tRolling On The Floor Laughing Emoji");
		printf("\n\t\t1> Draw using algorithm");
		printf("\n\t\t2> Draw using inbuilt functions");
		printf("\n\t\t3> to Exit");
		scanf("%d",&c);
		if(c==1){
			algo();
		}else if(c==2){
		       builtin();
		}else if(c==3){
			i--;
		}else{
			printf("\n\t\tInvalid Input\n\t\t press enter to try again");
		}
	}
	closegraph();
return 0;
}