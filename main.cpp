#include <iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

int factorial(int n)
{
  if(n==0)
  {
    return 1;
  }
  return n*factorial(n-1);
}

int fibonacci(int n)
{
  if(n==0)
  {
    return 0;
  }
  if(n==1)
  {
    return 1;
  }
  return fibonacci(n-1)+fibonacci(n-2);
}

int firstindex(int input[],int size,int n)
{
  if(size==0)
  {
    return -1;
  }
  if(input[0]==n)
  {
    return 0;
  }
  int answer = firstindex(input+1,size-1,n);
  if(answer!=-1)
  {
    return answer+1;
  }
  else{
    return answer;
  }
}

int lastindex(int input[],int size,int n)
{
  if(size==0)
  {
    return -1;
  }
  int answer=lastindex(input+1,size-1,n);
  if(answer!=-1)
  {
    return answer+1;
  }  
  if(input[0]==n)
  {
    return 0;
  }
  else
  {
    return answer;
  }
}

void allindexes(int input[],int size,int n)
{
  vector<int> output;
  for(int i=0;i<size;i++)
  {
    if(input[i]==n)
    {
      output.push_back(i);
    }
  }
  for(int i=0;i<output.size();i++)
  {
    cout<<output[i]<<" ";
  }
  if(output.empty())
  {
    cout<<-1;
  }
}

int countzeroes(int n)
{
  if(n<=9)
  {
    if(n==0)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  int last = n%10;
  int count =0;
  if (last==0)
  {
    count++;
  }
  return count+countzeroes(n/10);
}

int gsum(int k)
{
  if(k==0)
  {
    return 1;
  }
  return gsum(k-1)+1/pow(2,k);
}

bool checkpalindrome(string str,int start,int end)
{
  if(start>=end)
  {
    return true;
  }
  if(str[start]==str[end])
  {
    return checkpalindrome(str, start+1, end-1);
  }
  else{
    return false;
  }
}

string replacepi(string str)
{
  if(str.length()==0 || str.length()==1) 
  {
    return str;
  }
  if(str[0]=='p' && str[1]=='i')
  {
    return "3.14" + replacepi(str.substr(2));
  }
  else
  {
    return str[0]+ replacepi(str.substr(1));
  }
}

int stringtonumber(string str,int last)
{
  if(last==0)
  {
    return str[last]-'0';
  }
  int smallans=stringtonumber(str,last-1);
  int a=str[last]-'0';
  return  smallans*10 +a;
}
int stringtonum(string str)
{
  return stringtonumber(str,str.length()-1);
}

void towerofhanoi (int n,char source,char auxilliary,char destination)
{
  if(n==0)
  {
    return;
  }
  towerofhanoi(n-1,source,destination,auxilliary);
  cout<<source<<" "<<destination<<endl;
  towerofhanoi(n-1,auxilliary,source,destination);
}
int main() 
{
int input[]={1,2,3,4,5,3,7};
int n ;
cin>>n;
string str;
cin>>str;
cout<<factorial(n)<<endl;
cout<<fibonacci(n)<<endl;
cout<<firstindex(input,7,n)<<endl;
cout<<lastindex(input,7,n)<<endl;
allindexes(input, 7,n);
cout<<endl;
cout<<countzeroes(2000)<<endl;
cout<<gsum(0)<<endl;
cout<<checkpalindrome(str, 0, str.length()-1
)<<endl;
cout<<replacepi(str)<<endl;
cout<<stringtonum(str)<<endl;
towerofhanoi(4,'A','B','C');
cout<<endl;
}