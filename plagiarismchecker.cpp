#include<iostream>
#include<fstream>
using namespace std;
void read(char arr1[],char arr2[],char arr3[]);
void removealphanumeric(char arr1[],char arr2[],char arr3[],char shuffle1[],char shuffle2[],char shuffle3[],char substring1[],char substring2[],char substring3[]);
void convertlowercase(char shuffle1[],char shuffle2[],char shuffle3[],char substring1[],char substring2[],char substring3[]);
void substringarrange(char shuffle1[],char shuffle2[],char shuffle3[],char substring1[],char substring2[],char substring3[]);
void matixformation();
void comparison();
int main()
{
	cout<< "***********************************************************"<<endl;
	cout<<"____________________________________________________________"<<endl;
	cout<<endl;
	cout<<"                     PALGIARISM CHECKER                     "<<endl;
	cout<<"____________________________________________________________"<<endl;
	cout<<endl;
	cout<<"*************************************************************"<<endl;
	char arr1[500]={'\0'};
	char arr2[500]={'\0'};
	char arr3[500]={'\0'};
	char shuffle1[500]={'\0'};
	char shuffle2[500]={'\0'};
	char shuffle3[500]={'\0'};
	char substring1[6]={'\0'};
	char substring2[6]={'\0'};
	char substring3[6]={'\0'};
	read(arr1,arr2,arr3);
	removealphanumeric(arr1,arr2,arr3,shuffle1,shuffle2,shuffle3,substring1,substring2,substring3);
	cout<<endl;
	return 0;
}
void read(char arr1[],char arr2[],char arr3[])
{   
	ifstream infile1;
	infile1.open("text1.txt",ios::in);
	infile1.getline(arr1,499);
	ifstream infile2;
	infile2.open("text2.txt",ios::in);
	infile2.getline(arr2,499);
	ifstream infile3;
	infile3.open("text3.txt",ios::in);
	infile3.getline(arr3,499);
	infile1.close();
	infile2.close();
	infile3.close();
}
void removealphanumeric(char arr1[],char arr2[],char arr3[],char shuffle1[],char shuffle2[],char shuffle3[],char substring1[],char substring2[],char substring3[])
{
	
	int j=0;
	for(int i=0;arr1[i]!='\0';i++)
	{
		if(arr1[i]>='a' && arr1[i]<='z' || arr1[i]>='A' && arr1[i]<'Z')
		{
			shuffle1[j]=arr1[i];
			j++;
			
		}
	}
	//cout<<shuffle1;
	//cout<<endl;
	int h=0;
	for(int g=0;arr2[g]!='\0';g++)
	{
		if(arr2[g]>='a'&& arr2[g]<='z' || arr2[g]>='A' && arr2[g] <='Z')
		{
			shuffle2[h]=arr2[g];
			h++;
		}
	}
//	cout<<shuffle2;
	//c out<<endl;
	int b=0;
	for(int a=0;arr3[a]!='\0';a++)
	{
		if(arr3[a]>='a'&& arr3[a]<='z' || arr3[a]>='A' && arr3[a]<='Z')
		{
			shuffle3[b]=arr2[a];
			b++;
		}
	}
	//cout<<shuffle3;
	//cout<<endl;
	convertlowercase(shuffle1,shuffle2,shuffle3,substring1,substring2,substring3);

}
void convertlowercase(char shuffle1[],char shuffle2[],char shuffle3[],char substring1[],char substring2[],char substring3[])
{
	for(int i=0;shuffle1[i]!='\0';i++)
	{
		if(shuffle1[i]>=65 && shuffle1[i]<90)
		{
			shuffle1[i]=shuffle1[i]+32;
		}
	}
//	cout<< shuffle1;
//	cout<<endl;
	for(int j=0;shuffle2[j]!='\0';j++)
	{
		if(shuffle2[j]>=65 && shuffle2[j]<=90)
		{
			shuffle2[j]=shuffle2[j]+32;
		}
	}
//	cout<<shuffle2;
	//cout<<endl;
	for(int k=0;shuffle3[k]!='\0';k++)
	{
		if(shuffle3[k]>=65 && shuffle3[k]<=90)
		{
			shuffle3[k]=shuffle3[k]+32;
		}
	}
	//cout<<shuffle3;
	//cout<<endl;
	substringarrange(shuffle1,shuffle2,shuffle3,substring1,substring2,substring3);
}
void substringarrange(char shuffle1[],char shuffle2[],char shuffle3[],char substring1[],char substring2[],char substring3[])
{
	int sum=0;
	int val=0;
	int value=0;
	ofstream fout1;
	fout1.open("blocksets1.txt",ios::out);
	//cout<<"Shuffle1::"<<shuffle1<<endl;
	for(int e=0;shuffle1[e+4]!='\0';e++)
	{
		for(int i=0;i<5;i++)
		{
		  substring1[i]=shuffle1[e+i];
		}

		for(int f=0;substring1[f]!='\0' ;f++)
		  {
			 // cout<<"Substring::"<<substring1[f]<<endl;
             value=value+int(substring1[f]-96);
			 
		   } 
		//cout<<substring1<<"   "<<value<<"   ";
		fout1<<value<<endl;
	    value=0;
	}
	ofstream fout2;
	fout2.open("blocksets2.txt",ios::out);
	//cout<< "shuffle2::"<< shuffle2 <<endl;
	for(int e=0;shuffle2[e+4]!='\0';e++)
	{
		for(int i=0;i<5;i++)
		{
			substring2[i]=shuffle2[i+e];
		}
		for(int f=0;substring2[f]!='\0';f++)
		{
			value=value+int(substring2[f]-96);
		}
		//cout<< substring2 <<"   "<< value <<"  "<<endl;
		fout2<<value<<endl;
		value=0;
	}
	ofstream fout3;
	fout3.open("blocksets3.txt",ios::out);
	for(int e=0;shuffle3[e+4]!='\0';e++)
	{
		for(int f=0;f<5;f++)
		{
			substring3[f]=shuffle3[f+e];
		}
		for(int j=0;substring3[j]!='\0';j++)
		{
			value=value+int(substring3[j]-96);
		}
	//	cout<< substring3 <<"  "<<value <<"  "<<endl;
       fout3<<value<<endl;
		value=0;
	}
		 for(int i=0;substring1[i+4]!='\0';i++)
		{
			substring1[i]='\0';
		}
		  matixformation();
	}

void matixformation()
{
	int term1=0;
	int term2=0;
	int term3=0;
	int term4=0;
	int count=0;
	ifstream infile;
	infile.open("blocksets1.txt",ios::in);
	infile>>term1>>term2>>term3>>term4;
	ofstream write1;
	
	if(count==0)
	{
		write1.open("matrix1.txt",ios::out);
	}
	else
	{
		write1.open("matrix1.txt",ios::out);
	}
	
	count=1;
		while(1)
		{
			if(infile.eof())
			{
				break;
			}
			write1<< term1 << "     "<<term2<<endl;
			write1<< term3 << "     "<<term4<<endl;
							write1<<endl;
							write1<<endl;
			
				//cout<<term1 <<  "    " <<term2<<endl;
				//cout<<term3 <<  "    " <<term3<<endl;
							//cout<< endl;
							//cout<< endl;
				term1=term2;
				term2=term3;
				term3=term4;
				infile>>term4;
		}
	
	infile.close();
	write1.close();
	
	ifstream infile2;
	infile2.open("blocksets2.txt",ios::in);
	infile2>>term1>>term2>>term3>>term4;
	ofstream write2;
	 if(count=0)
	 {
		 write2.open("matrix2.txt",ios::out);
	 }
	 else
	 {
		 write2.open("matrix2.txt",ios::out);
	 }
	 count=1;
	 //cin.get();
	 while(1)
	 {
	
			if(infile2.eof())
			 {
			 break;
			 }
			 write2 << term1<<"    "<<term2<<endl;
			 write2 << term3<<"    "<<term3<<endl;
				       write2<<endl;
				       write2<<endl;
		//     cout << term1<<"    "<<term2<<endl;
			// cout << term3<<"    "<<term3<<endl;
			  //         cout<<endl;
				//	   cout<<endl;
		    term1=term2;
			term2=term3;
			term3=term4;
			infile2>>term4;
	 }
	 infile2.close();
	 write2.close();
	 ifstream infile3;
	 infile3.open("blocksets3.txt",ios::in);
	 infile3>>term1>>term2>>term3>>term4;
	 ofstream write3;
	 if(count=0)
	 {
		 write3.open("matrix3.txt",ios::out);
	 }
	 else
	 {
		 write3.open("matrix3.txt",ios::out);
	 }
	 count=1;
	 //cin.get();
	   while(1)
	   {
		   if(infile3.eof())
		   {
			   break;
		   }
		   write3<<term1<<"  "<<term2<<endl;
		   write3<<term3<<"  "<<term4<<endl;
		            write3<<endl;
					write3<<endl;
		 // cout << term1<<"    "<<term2<<endl;
		//  cout << term3<<"    "<<term3<<endl;
		  //          cout<<endl;
			//		cout<<endl;
			term1=term2;
			term2=term3;
			term3=term4;
			infile3>>term4;
	   }
	   infile3.close();
	   write3.close();
	   comparison();

}
void comparison()
{
	int count=0;
	int counter=0;
	int term1=0;
	int term2=0;
	int term3=0;
	int term4=0;
	int num1=0;
	int num2=0;
	int num3=0;
	int num4=0;
	int val1=0;
	int val2=0;
	int val3=0;
	int val4=0;
	int match12=0;
	int match23=0;
	int match31=0;
	int arr12[50]={0};
    int arr23[50]={0};
	int arr13[50]={0};
	int avg12=0;
	int avg23=0;
	int avg31=0;
	ifstream fin1;
	fin1.open("matrix1.txt",ios::in);
	ifstream fin2;
	fin2.open("matrix2.txt",ios::in);
	ifstream fin3;
	fin3.open("matrix3.txt",ios::in);
		while(count!=10)
		{
		        fin1>>term1>>term2>>term3>>term4;
				fin2>>val1>>val2>>val3>>val4;
				fin3>>num1>>num2>>num3>>num4;
				counter++;
				int i=0;
				if(counter%10==0)
				{
					arr12[i]=0;
					arr23[i]=0;
					arr13[i]=0;
		        fin1>>term1>>term2>>term3>>term4;
				fin2>>val1>>val2>>val3>>val4;
				fin3>>num1>>num2>>num3>>num4;

					match12=match12+(term1-val1)+(term2-val2)+(term3-val3)+(term4-val4);
					match23=match23+(val1-num1)+(val2-num2)+(val3-num3)+(val4-num4);
					match31=match31+(num1-term1)+(num2-term2)+(num3-term3)+(num4-term4);
					count++;
					arr12[i]=match12;
					match12=0;
					arr23[i]=match23;
					match23=0;
					arr13[i]=match31;
					match31=0;
					i++;
				}
		}
		for(int i=0;i<10;i++)
		{
			if(arr12[i]<60)
			{
				avg12++;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(arr23[i]<60)
			{
				avg23++;
			}
		}
		for(int i=0;i<10;i++)
		{
			if(arr13[i]<60)
			{
				avg31++;
			}
		}
				
			avg12=(avg12/10)*100;
			avg23=(avg23/10)*100;
			avg31=(avg31/10)*100;
			if(avg12>60)
			{
				cout<< "similarity of ist and 2nd file"<<"     "<<avg12 <<"%"<<endl;
			}
			else
			{
				cout<<"Files are not same"<<endl;
			}
			if(avg23>60)
			{
				cout<< "similarity of 2nd and 3nd file"<<"     "<<avg23<<"%" <<endl;
			}
			else
			{
				cout<<"Files are not same"<<endl;
			}
			if(avg31>60)
			{
				cout<<  "similarity of 3rd and ist file"<<"     "<<avg31<<"%" <<endl;
			}
			else
			{
				cout<<"Files are not same"<<endl;
			}
	}
	//changed the 3rd text file for thr purpose of checking correction of code
