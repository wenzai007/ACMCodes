void  divider(int n)
{
 if (n==1)
 {
  a[0][0]=1;
  return;
 }
 else
 {
      divider(n/2);
   int m=n/2;
   for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
    {
     a[i][j+m]=a[i][j]+m;
     a[i+m][j]=a[i][j+m];
     a[i+m][j+m]=a[i][j];
    }
 }
}