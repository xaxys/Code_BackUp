#include <stdio.h>
int main(){
    int n,a,b,i;
    scanf("%d\n",&n);
    for(i=n;i>-1;i--){
        scanf("%d",&a);
        if(i!=0){
			if (i!=1){
			    if (a!=0){
			        if(a!=1 && a!=-1){
			   	    	if(i==n) printf("%dx^%d",a,i);
					    else printf("%+dx^%d",a,i);
			    	}
			     	else if (a==1){
                        if(i==n) printf("x^%d",i);
				    	else printf("+x^%d",i);
			    	}
				else printf("-x^%d",i);
				}
			}
			else if(i==1){
			    	if (a!=0){
			            if(a!=1 && a!=-1) printf("%+dx",a);
			           	else if (a==1) printf("+x");
			   	        else printf("-x");
					}
			}
		}
        else if(a!=0) printf("%+d",a);
    }
}