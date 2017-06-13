#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
/*-----END OF C++ Libraries---*/
void file_editor(string edit);//function prototype
int main()
{
	
	string edit="\n";//enables the user to edit the abstract. 
	cout<<"display message: "<<endl;//prompt the user to edit abstract, if there is nothing to adit type "none" 
	cin>>edit;


	file_editor(edit);//function responsible for editing the xml file
	cout<<"Done"<<endl;//display the message when function done
	system("pause");
	return 0;
}

void file_editor(string edit)//function definition
{
	int dio1=0;//represents the array address where the first dio code is
	int dio2=0;//represents the array address where the second dio code is
	ifstream Infile("merged_file.xml");//opens and copies the merged file contant to Infile

	if(Infile.is_open())//loop confirming whether the merged_file is open or not
	{
		
		cout<<"merged file is open"<<endl;//message that confirms that the file is open

stringstream strStream;
strStream << Infile.rdbuf();//read the file
string name2 = strStream.str();//str holds the content of the file and sends it to name2
Infile.close();//closes the merged_file after the contant it holds has been read
int count=0;//interger responsible for counting number of xml lines that need to be deleted 
int i=0;//variable used to ensure that each charecter in the array is evaluated

	ofstream outfile("Merged_file(edited).xml");//creating the xml file that will carry the contant that has been edited
while(i<name2.size())//loop ensuring that the number of loops does not ecit the number of charecters in the array
{
	count=0;//reserting the count each time the new xml issue is reviewed
	if((name2[i]=='h')&&(name2[i+13]=='t')&&(name2[i+14]=='&'))// loop ensuring that the http sub adresses are read
	{
	//outfile<<"doi.org";
	int x1=0;
int n=i+19;//reads where the first dio initial number starts

		dio1=n;//n assigns the bigining of the array adress first dio code to dio1
		
		n=i+26;//reads the second dio code initial number starts

		dio2=n;//n asigns the array adress  intitial number to dio2
		

	
	}else{

	if((name2[i]=='<')&&(name2[i+19]=='e')){
		
		while(count<2)//ensures that two lines of description is skipped
		{
				i++;//advances the array address
				if((name2[i]=='<')&&(name2[i+1]=='d'))// confirms the description line
				{
			count++;//counts everytime the destreption line starts
				
				}
			}
		
	}
	
	}

	if((count<3)&&(count>1))//chechs if the number of description ines are there or not, they can be replaced
	{
		
		
		char dioconv2= NULL;//variable that manipultes the system to accept the char arrays in the mxl file
		std::string count_iss1 = std::to_string(dioconv2);//converting char to string
		outfile<<"<dcvalue element=\"identifier\" qualifier=\"uri\">https:&#x2F;&#x2F;doi.org&#x2F;1"+count_iss1+"539&#x2F;"+name2[dio2+5]+name2[dio2+6]+name2[dio2+7]+name2[dio2+8]+name2[dio2+9]+"</dcvalue>"<<endl;//inserting the dio code in xml
		outfile<<"<dcvalue element=\"description\" qualifier=\"abstract\" language=\"en_ZA\">"+edit+"</dcvalue>"<<endl;//inserting abstract in xml file
		
		outfile<<name2[i];//insert the rest of info in the file
		
		}
	
	else{
	outfile<<name2[i];// will continue copying information if deistcription not found
	
	}
	i++;//incriments array address
}



	outfile.close();// closes xml editing file when done edditing
		
	
	}
	else{
	
	cout<<"Could not open file"<<endl;//display message if file not found.
	}

	



}