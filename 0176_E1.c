#include <stdio.h>
 
inline int getn(){
	int n=0, c=getchar_unlocked();
	while(c<'0'||c>'9') 
		c= getchar_unlocked();
	while(c>='0'&&c<='9')
		n=(n<<3)+(n<<1)+c-'0',c=getchar_unlocked();
	return n;
}
int main(){
	int T = getn(), N, a[1001][1001],r,c, v;
	char b[1001][1001];
	while(T--){
		N=getn();
		for(r=0;r<N;r++) 
			gets(b[r]);
		for(c=N-1;c>=0;c--)
		{
			for(r=0;r<N;r++)
			{
				v = 0;
				if(c<N-1&&r< N-2) 
					v=v>a[r+2][c+1]?v:a[r+2][c+1];
				if(c<N-1&&r>1)
					v=v>a[r-2][c+1]?v:a[r-2][c+1];
				if(c<N-2&&r<N-1)
					v=v>a[r+1][c+2]?v:a[r+1][c+2];
				if(c<N-2&&r>0)
					v=v>a[r-1][c+2]?v:a[r-1][c+2];
				a[r][c]=v+(b[r][c]=='P'?1:0);
				if(b[r][c]=='K')
					break;
			}
			if(r< N)
				break;
		}
		printf("%d\n",a[r][c]);
	}
	return 0;
}
