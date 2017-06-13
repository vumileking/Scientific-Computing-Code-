#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
using namespace std;
/*--------------END OF LIBRARIES-----------*/
void Filecollector( int value, int value2);//function definition. This function opens and reads collections and dublincore files then copies them all in one xml file.
											//value and value2 are variables that indicate the begining of collection number and the end of the collection number.

int main(){

	int value1=0;//initialisation of variable that indincates the collection start number
	int value2=0;//initialisation of variable that indincates the collection end number
	/*string xml;
	string ltr2=" ";
	string ltr1=" ";
	int file_2=1;
	string data=" ";
	int x=1;
	ofstream outFile;*/
	cout<<"Please enter your collection start Number: "<<endl;// message prompting the user to insert the first collection number
	cin>>value1;
	cout<<"Please enter your collection end Number: "<<endl;// message prompting the user to insert the last collection
	cin>>value2;
	Filecollector(value1,value2);// the function which search trough the collections
	/*while(file_2<100){
	

	 if(x=1){
	 ofstream outFile("Issue-"+ltr1+ltr2+".xml");
	 x++;
	 }
	outFile<<data<< endl;
	file_2++;
	}
	outFile.close();*/
	system("pause");//program end

	return 0;
}
//////////////////////////////////////

void Filecollector( int value, int value2 )//function operations are listed below
{
	int x=1;
	string name2;
	string ltr2=" ";
	string ltr1=" ";
	int file_2=1;// variable that opens issue folder

	ofstream outFile("Merged_file.xml");// create the xml document where all xml will be merged
	while(value<value2+1)//ensures that the incriment of collection is within the range of collection start and end folder
	{


		std::string values = std::to_string(value);//converts values to a string data type since values is in interger data type  
	//second file opener 
		std::string file_22 = std::to_string(file_2);//converts int to a string data type since int is in interger data type
   
std:: ifstream fileInput("collections/collection_"+values+"/"+file_22+"/dublin_core.xml");//opens and copies whats in collection folders with respet to thier dicrectry
if(fileInput.is_open())//if the xml file is found and has been openned the operation of copying take place
{
	fileInput.close();// closes the document openned, since all content that are in the xml are in fileInput 

	
while(file_2<100){
	
	
	std::string values = std::to_string(value);//converts values to a string data type since values is in interger data type
	//second file opener 
	
	std::string file_22 = std::to_string(file_2);//converts int to a string data type since int is in interger data type
   
std:: ifstream fileInput("collections/collection_"+values+"/"+file_22+"/dublin_core.xml");//opens and copies whats in collection folders with respet to thier dicrectry


	//file opener incriment


	if(fileInput.is_open()){
	
	//cout<<"The file is openned"<<endl;
	
	stringstream strStream;
strStream << fileInput.rdbuf();//read the file
string name2 = strStream.str();//str holds the content of the file
fileInput.close();

if(file_2==1){
	
		//outFile<<"<!-- "+values+" -->"<<endl;
	outFile<<"<!--collection_"+values+"-->"<<endl;//shows us the collection number for the firs copied issue
		outFile<<name2<< endl;//copies the content of issue one to the merged xml
			outFile<<"<!-- ============== -->"<<endl;//this shows the end of an xml
			/*value++;*/
			file_2++;//incriment the number of issue under the same xml
}
else{
			outFile<<name2<< endl;//if the first issue have been copied, other xmls will be copied with respect to their issue number
			outFile<<"<!-- ============== -->"<<endl;//this shows the end of an xml
file_2++;//incriment the number of issue number
}
}
	
	else{
	cout<<"issue file not found"<<endl;// message will be displayed if issue folder is not found
		file_2++;// then searches for the next folder
	}

}
cout<<"Done"<<endl;// display message when done with a spacific collection

	}
else{
	cout<<"collection not found"<<endl;////display message when collection not found
	value++;//will incriment the collection number to check onother possible collection
	file_2=1;//resets the issue number
}
	}
	outFile.close();//closes the merged file when done with all collections
}

	///////////////////////