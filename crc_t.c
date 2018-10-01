#include<stdio.h>
#include<stdlib.h> 


int divide(int *r,int *m,int *p,int * temp,int mlen,int plen)
{
	int j=0,k=0,i;
	while(j<(mlen))
	{
	while(k<plen && j<(mlen))
	temp[k++]=m[j++];

	if(k==plen)
	{
	
	for(i=0;i<plen;i++)
	{
		r[i]=temp[i]^p[i];
	}
	i=0;
	while(r[i]==0)
	i++;
	

	if(j<(mlen))
	{
	k=0;
	
	
	while(i<plen)
	temp[k++]=r[i++];
	}
	}

	else
	{
	
	for(i=0;i<k;i++)
	r[i]=temp[i];
	}
	}
	return k;
}


void accept(int *m,int *p,int mlen,int plen)
{
	int i;
	printf("Enter the message :");
	for (i=0;i<mlen;i++)
	scanf("%d",&m[i]);
	
	printf("Enter the key :");
	for (i=0;i<plen;i++)
	scanf("%d",&p[i]);
}
int main()
{
	int mlen,plen,i,j,k;
	int *m;
	int *p;
	int *r;
	int *temp;
	/* encoding */
	printf("-----------------ENCODING----------------\n");
	printf("Enter the message length: ");
	scanf("%d",&mlen);

	

	printf("Enter the key length: ");
	scanf("%d",&plen);
	
	m=malloc((mlen+plen-1)*sizeof(int));
	p=malloc(plen*sizeof(int));

	r=malloc((plen)*sizeof(int));
	temp=malloc(plen*sizeof(int));

	accept(m,p,mlen,plen);

	


	for(i=mlen;i<(mlen+plen-1);i++)
	m[i]=0;

	

	
	
	k=divide(r,m,p,temp,mlen+plen-1,plen);

	printf("The remainder is :");
	
	for(i=0;i<k;i++)
	printf("%d",r[i]);

	
	for(j=(mlen+plen-2),i=k-1;i>=0;j--,i--)
	{
		m[j]=m[j]+r[i];
	}
	
	printf("\nThe message to be sent is : ");
	for(j=0;j<(mlen+plen-1);j++)
	{
		printf("%d",m[j]);
	}
	
	printf("\n");



	/* decoding */

	printf("-----------------DECODING----------------\n"); //using array m and p to find out the message

	printf("Enter the codeword length:");
	scanf("%d",&mlen);
	printf("Enter the key length :");
	scanf("%d",&plen);
	
	m=malloc(mlen*sizeof(int));
	p=malloc(plen*sizeof(int));
	r=malloc((plen)*sizeof(int));
	temp=malloc(plen*sizeof(int));
	accept(m,p,mlen,plen);
	k=divide(r,m,p,temp,mlen,plen);
	
	
	
	for(i=0;i<k;i++)
	if(r[i]!=0)
	{
	printf("Wrong message!!!\n");
	return 0;
	}

	printf("Correct message!!!\n");
	return 0;
	
}
