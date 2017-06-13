#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<fstream>
#include <direct.h>
//#include<sys/stat.h>
using namespace std;
#define _CRT_NONSTDC_NO_DEPRECATE
/*------END OF C++ LIBRARIES------*/
void readdata();//function prototype

int main()
{

readdata();//function call
system("pause");
return 0;
}

void readdata()//function definition
{

	
	ifstream Infile("Merged_file(edited).xml");//opens mergrd file
		
	if(Infile.is_open())//loop to confirm when file is openned
	{
	
	cout<<"Merged_file is openned"<<endl;//messege desplayed to confirm when file is openned
	
	stringstream strStream;
strStream << Infile.rdbuf();//read the file
string name2 = strStream.str();//str holds the content of the file to name2
Infile.close();//closes the file

int up=0;
int down=0;
int j=1;
int dnum=0;
int unum=0;
string collec_no;
int count_coll1=0;
int count_coll2=0;
int count_iss=0;
int x=0;
int reminder=0;
int dwn1=0;
int up2=0;
int total=0;
mkdir("c:/users/avril/Desktop/collections");//create the file in desktop directry
for(int i=0;i<name2.size()+1;i++)//raeds content by content
{
	reminder=0;//reserts the variable
	if((name2[i]=='c')&&(name2[i+10]=='_'))//loop confirms the collection number of content
	{
		count_coll1=i+11;//takes the first digit of collection

		/*while(name2[count_coll1]!='-'){
		collec_no[count_coll2]=name2[count_coll1];
		
		count_coll2++;
		count_coll1++;
		
		}
		count_coll2=0;*/
		count_iss=0;

		
		std::string path = "c:/users/avril/Desktop/collections/collection_";//sets the directory to path
		

		
		mkdir((path+name2[count_coll1]+name2[count_coll1+1]+name2[count_coll1+2]).c_str());//creates the collection number folder under the directry of collection number
         
	
	}else{
	
	if((name2[i]=='<')&&(name2[i+1]=='?'))//confirms the strting line of xml
	{

		up=i;//takes the array address of the first xml line
		up2=up;//assigns array adress of the first xml to up2
		/*cout<<"up="<<up<<endl;*/
	}
	else{
		if((name2[i]=='<')&&(name2[i+1]=='!'))//confirms the last line of xml code
		{
		
	down=i;//assigns the array address of the last xml line
	dwn1=down;//assigns array adress of the last xml to dwn1

	}

	else{
		if((up>=0)&&(down!=0))//if both avariables certisfy the condition, then we have valus copied
		{
			for(int y=up;y<down;y++)//confirms that we only have one xml issue contant
			{
				if((name2[y]=='<')&&(name2[y+1]=='?'))//if there is only one xml contant in then reminder will be incrimented once
				{
					reminder++;}
				}
			total=up2-x;//redundency test
					if((reminder<2))//confirms that there is only one xml issue content
					{
		count_iss++;// sets up the issue folder number
		std::string count_iss1 = std::to_string(count_iss);//converts it to string
		//char const *pchar = count_iss1.c_str();
		std::string secondpath="/"+count_iss1;//sets the directry divider for folder number 
		std::string path = "c:/users/avril/Desktop/collections/collection_";//sets directry to path
		total=up2;

		
		mkdir((path+name2[count_coll1]+name2[count_coll1+1]+name2[count_coll1+2]+secondpath).c_str());//creates the folder where the xml dublin_core will stay
        ofstream outFile(path+name2[count_coll1]+name2[count_coll1+1]+name2[count_coll1+2]+secondpath+"/dublin_core.xml");//creates the xml file inside the directory
	x=up;//assign x to the begining address of the xml content
	
	
	while(x<down)//ensures that the content writen belongs to the xml issue content
	{
	
			outFile<<name2[x];//print
			
x++;//incriments the array address where the xml contant is
	}/*cout<<reminder<<endl;*/
	
	cout<<"first file complete:"<<name2[count_coll1]<<name2[count_coll1+1]<<name2[count_coll1+2]<<endl;//message confiming that the xml issue content has been created 
	
	outFile.close();//closes the dublin_core file
			
	up=0;//resets the values
	down=0;//resets the values
	j++;}
					else{
						ofstream outFile("/dublin_core.xml");//creates junk file to ensure that the array address progesses to the next vital content
						x=up;
					while(x<down){

	
			outFile<<name2[x];//prints junk content
			
x++;
	}outFile.close();//closes junk file
			
	up=0;
	down=0;
					}
	}

}

}
}

}
	}
	else{
	cout<<"file not found"<<endl;//displays message when file not found
	}

	
}