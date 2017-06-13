#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<fstream>
#include <Windows.h>
#include <stdio.h>
using namespace std;
void  Submite(int value2,int value1,string doi_batch_id,string timestamp,string depositor_name, string email_address);
const int Max=1000;

int main()
{
	int value1=0;
	int value2=0;
	string doi_batch_id;
	string timestamp;
	string depositor_name;
	string email_address;
	
	

	cout<<"Enter doi_batch_id"<<endl;
	cin>>doi_batch_id;

	cout<<"Enter timestamp"<<endl;
	cin>>timestamp;

	cout<<"Enter depositor_name"<<endl;
	cin>>depositor_name;

	cout<<"Enter email_address"<<endl;
	cin>>email_address;

	

	cout<<"Please enter your collection start Number: "<<endl;
	cin>>value1;
	cout<<"Please enter your collection end Number: "<<endl;
	cin>>value2;

	
	Submite(value2,value1,doi_batch_id,timestamp,depositor_name,email_address);
	system("pause");
return 0;
}

void Submite(int value2,int value1,string doi_batch_id,string timestamp,string depositor_name, string email_address){
	char name[Max]=" ";
	char surname[Max]=" ";
	char month[Max]=" ";
	char day[Max]=" ";
	char year[Max]=" ";
	string first_page="0";
	string last_page="1";
	char dio1[Max]=" ";
	char dio2[Max]=" ";
	char tittle[Max]=" ";
	int x=0;
	//int count=0;
	//int count2=0;
	int file_2=1;
	int countcrosref=0;
	char ltr1[Max]=" ";
	int d=0;
		SYSTEMTIME str_t;
		GetSystemTime(&str_t);
		std::string year = std::to_string(str_t.wYear);
		std::string month = std::to_string(str_t.wMonth+00);
		std::string day = std::to_string(str_t.wDay);
		std::string hour = std::to_string(str_t.wHour+2+00);
		std::string minute = std::to_string(str_t.wMinute+00);
		std::string seconds = std::to_string(str_t.wSecond+00);

	ofstream outFile("crossreff_files/crossref("/*+countcrosref2+*/").xml");	
	/*--------------------------------------------------------------------------------------------------*/
	outFile<<"<head>"<<endl;
	outFile<<"<doi_batch_id>"+doi_batch_id+"</doi_batch_id>"<<endl;
	outFile<<"<timestamp>"+year+month+day+hour+minute+seconds+"</timestamp>"<<endl;
	outFile<<"<timestamp>"+timestamp+"</timestamp>"<<endl;
	outFile<<"<depositor>"<<endl;
	outFile<<"<depositor_name>"+depositor_name+"</depositor_name>"<<endl;
	outFile<<"<email_address>"+email_address+"</email_address>"<<endl;
	outFile<<"</depositor>"<<endl;
	outFile<<"<registrant>Crossref</registrant>"<<endl;
	outFile<<"</head>"<<endl;
	outFile<<"<body>"<<endl;
	/*---------------------------------------------------------------------------------------------------*/
	while(value1<value2+1){

			file_2=1;
	d=file_2;
	while(file_2<100){
		

			std::string values = std::to_string(value1);
			//second file opener 
			std::string file_22 = std::to_string(file_2);

			ifstream Infile("collections/collection_"+values+"/"+file_22+"/dublin_core.xml");

			stringstream strStream;
			strStream << Infile.rdbuf();//read the file
			string name2 = strStream.str();//str holds the content of the file
if(Infile.is_open()){
countcrosref++;
		Infile.close();

	

	for(int i=0;i<name2.size();i++){
		
		if(((name2[i]=='"')&&(name2[i+1]=='a'))&&((name2[i+5]=='o')&&(name2[i+6]=='r'))){
		i+=9;
			//cout<<i<<"/"<<name2.size()<<endl;

			
//cout<<name<<"/"<<name2.size()<<endl;
		if((name2[i]=='l')&&(name2[i+11]=='>')){
			i+=12;
				for(int count=0;name2[i]!=',';count++){
		if((name2[i]=='&')&&(name2[i+5]==';'))
					{
					name[count]=' ';
					i+=6;
					}
					else
					{
						if((name2[i]=='&')&&(name2[i+4]==';')){
					name[count]='"';
					i+=5;
					}
					else
					{
					name[count]=name2[i];
					i++;}
					}
				//cout<<name<<endl;
				}
		}else{
			
		for(int count=0;name2[i]!=',';count++){
		if((name2[i]=='&')&&(name2[i+5]==';'))
					{
					name[count]=' ';
					i+=6;
					}
					else
					{
						if((name2[i]=='&')&&(name2[i+4]==';')){
					name[count]='"';
					i+=5;
					}
					else
					{
					name[count]=name2[i];
					i++;}
					}
				//cout<<name<<endl;
				}
		}


				for(int count=0;name2[i]!=';';i++){
				name2[i];
				//cout<<name2[i]<<endl;
				}
				i++;
				for(int count=0;name2[i]!='<';count++){

				if((name2[i]=='&')&&(name2[i+5]==';'))
					{
					surname[count]=' ';
					i+=6;
					}
					else
					{
						if((name2[i]=='&')&&(name2[i+4]==';')){
					surname[count]='"';
					i+=5;
					}
					else
					{
					surname[count]=name2[i];
					i++;}
					}
			
				//cout<<surname<<endl;
				}
	

		}
		/////////////////////////////////////////////////////////////////////////////////////////
		else{
			if((name2[i]=='h')&&(name2[i+30]=='t')&&(name2[i+36]==';')){
			i+=37;
			
				for(int count=0;count<5;count++){
				dio1[count]=name2[i];
				//cout<<dio1<<endl;
				i++;
				}
				i+=6;
				for(int count=0;count<5;count++){
				dio2[count]=name2[i];
				//cout<<dio2<<endl;
				i++;
				}
			
				x++;
			
			}
			/////////////////////////////////////////////////////////////////////////////////////////////
			else{
			if(((name2[i]=='s')&&(name2[i+2]=='u'))&&((name2[i+5]=='"')&&(name2[i+6]=='>'))){
				
				i+=7;
				for(int count =0;count<4;count++){
				year[count]=name2[i];
					
				//cout<<year<<endl;
					i++;
				}
				i+=1;
				
				for(int count=0;count<2;count++){
					month[count]=name2[i];
					//cout<<month<<endl;
					i++;
				}
				i+=1;
				for(int count=0;count<2;count++){
				day[count]=name2[i];
				i++;
				//cout<<day<<endl;
				}

				/*count2=0; if(count==7){x+=1;}
					if(count<10){
						day[count2]=name2[x];
					count++;
					count2++;
					}*/
					
			}else{
				///////////////////////////////////////////////////////////////////////////////////////////////////
				if(((name2[i]=='t')&&(name2[i+1]=='='))&&((name2[i+6]=='l')&&(name2[i+7]=='e'))){
				i+=44;
				//cout<<"in"<<endl;
				//bool brek;
				for(int count=0;name2[i]!='<';count++){

					if((name2[i]=='&')&&(name2[i+5]==';'))
					{
					tittle[count]=' ';
					i+=6;
					}
					else
					{
						if((name2[i]=='&')&&(name2[i+4]==';')){
					tittle[count]='"';
					i+=5;
					}
					else
					{
					tittle[count]=name2[i];
					i++;}
					}
					//cout<<tittle<<endl;

					
				}
				/*while(name2[x]!='<'){
					tittle[count2]=name2[x];
				x++;
				count2++;
				}*/
				}else{
					//////////////////////////////////////////////////////////////////////////////////////////////////
				//	if(((name2[i]=='s')&&(name2[i+2]=='u'))&&((name2[i+5]=='"')&&(name2[i+18]=='>'))){
				//
				//i+=19;
				//for(int count =0;count<4;count++){
				//year[count]=name2[i];
				//	
				////cout<<year<<endl;
				//	i++;
				//}
				//i+=1;
				//
				//for(int count=0;count<2;count++){
				//	month[count]=name2[i];
				//	//cout<<month<<endl;
				//	i++;
				//}
				//i+=1;
				//for(int count=0;count<2;count++){
				//day[count]=name2[i];
				//i++;
				////cout<<day<<endl;
				//}
			
				//}
//else{
					//////////////////////////////////////////////////////////////////////////////////////
				if(((name2[i]=='e')&&(name2[i+1]=='-'))&&((d==1)&&(year!=" "))){
					i+=2;
					for(int count=0;name2[i]!='-';count++){
		ltr1[count]=name2[i];
		
					i++;}
	string yea(year);
	string ltr(ltr1);
		d=0;
				
				outFile<<"<journal>"<<endl;
				outFile<<"<journal_metadata language=\"en\">"<<endl;
				outFile<<"<full_title>South African Journal of Information and Communication</full_title>"<<endl;
				outFile<<"<abbrev_title>SAJIC</abbrev_title>"<<endl;
				outFile<<"</journal_metadata>"<<endl;
				outFile<<"<journal_issue>"<<endl;
				outFile<<"<publication_date media_type=\"print\">"<<endl;
				outFile<<"<year>"+yea+"</year>"<<endl;
				outFile<<"</publication_date>"<<endl;
				outFile<<"<journal_volume>"<<endl;
				outFile<<"<volume>0</volume>"<<endl;
				outFile<<"</journal_volume>"<<endl;
				outFile<<"<issue>"+ltr+"</issue>"<<endl;
				outFile<<"</journal_issue>"<<endl;
				
				}
				/*}*/}
			
			}

		
		}
	}
	
			
	}
		//std::string countcrosref2 = std::to_string(countcrosref);
				
    SYSTEMTIME str_t;
	string titl(tittle);
	string nam(name);
	string surn(surname);
	string mont(month);
	string da(day);
	string dio11(dio1);
	string dio22(dio2);
	string yea(year);

	GetSystemTime(&str_t);
		std::string year1 = std::to_string(str_t.wYear);
		std::string month1 = std::to_string(str_t.wMonth+00);
		std::string day1 = std::to_string(str_t.wDay);
		std::string hour = std::to_string(str_t.wHour+2);
		std::string minute = std::to_string(str_t.wMinute);
		std::string seconds = std::to_string(str_t.wSecond);

	outFile <<"<journal_article publication_type=\"full_text\">" << endl;
	outFile <<"<titles><title>"+titl+"</title></titles>"<<endl;
	outFile <<"<contributors>"<<endl;
	outFile <<"<person_name sequence='first' contributor_role='author'>"<<endl;
	outFile <<"<given_name>"+nam+"</given_name>"<<endl;
	outFile <<"<surname>"+surn+"</surname>"<<endl;
	outFile <<"</person_name>"<<endl;
	outFile <<"<organization sequence=\"additional\" contributor_role=\"author\">Wits</organization>"<<endl;
	outFile <<"</contributors>"<<endl;
	outFile <<"<publication_date media_type=\"print\">"<<endl;
	outFile <<"<year>"+yea+"</year>"<<endl;
	outFile <<"</publication_date>"<<endl;
	outFile <<"<pages>"<<endl;
	outFile <<"<first_page>"+first_page+"</first_page>"<<endl;
	outFile <<"</pages>"<<endl;
	outFile <<"<doi_data>"<<endl;
	outFile <<"<doi>10.23962/"+dio11+"/"+dio22+"</doi>"<<endl;
	outFile<<"<timestamp>"+year1+month1+day1+hour+minute+seconds+"</timestamp>"<<endl;
	outFile <<"<resource>http://hdl.handle.net/"+dio11+"/"+dio22+"</resource>"<<endl;
	outFile <<"</doi_data>"<<endl;
	outFile <<"</journal_article>"<<endl;
	//outFile <<"<!-- ============== -->"<<endl;
		


//////////////////////////////////////////////////////////////////////
	cout<<values<<endl;

	

	/*string name=" ";
	string surname=" ";
	string month=" ";
	string day=" ";
	string year=" ";
	string first_page="none";
	string last_page="none";
	string dio1=" ";
	string dio2=" ";
	string tittle=" ";*/

}else{
cout<<"collection not found"<<endl;
}
file_2++;
}
value1++;
	}
outFile <<"</body>"<<endl;
outFile <<"</doi_batch>"<<endl;
	outFile.close();			

}