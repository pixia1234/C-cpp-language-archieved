# include <stdio.h>
int main( )
{
	char w[]={'C','h','i','n','a'} ;
	int i;
	for(i=0;i<=4;i++) 
	{
	    if(w[i]<='Z'){	
    		w[i]+=4;
    		if(w[i]>='Z') w[i]-=26;
    		putchar(w[i]);
	    }
	    else {
	    	w[i]+=4;
    		if(w[i]>='z') w[i]-=26;
    		putchar(w[i]);
		}
	}
	return 0;
}

