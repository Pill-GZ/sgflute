#include"epimodel.h"
#include <cstdlib>
#include <cstring>
#include <climits>
#include <assert.h>


struct less_than_key
{
    inline bool operator() (const Person& struct1, const Person& struct2)
    {
        return (struct1.nHomeComm < struct2.nHomeComm);
    }
};

int main(){
	std::vector<Person> pvec;
	std::vector<int> ider;  					//temporary vector to store id information
	std::string name;						//for input filename
	char c;
	std::string dummy;
	std::cout<<"Input FileName: ";
	std::cin>>name;							//read input filename
	name=name+"-Revised input.csv";
	std::ifstream iss(name.c_str());
	std::vector<int> temp;
	int count=0;
	if(!iss){
		std::cout<<"No such file exist (not yet at least)"<<std::endl;
		exit(-1);
	}
	getline(iss,dummy);//this skips the first line of the input file
	while(iss.good()){
		Person p;
iss>>p.id>>c>>p.exactAge>>c>> p.age>>c>>p.gender>>c>>p.race>>c>>p.citizen>>c>>p.marital>>c>>p.number_children
>>c>>p.nSchoolType>>c>>p.qualification>>c>>p.work>>c>>p.income>>c>>p.headhouse>>c>>p.occupation>>c>>p.religion
>>c>>p.partnerid>>c>>p.family>>c>>p.dwelling>>c>>p.hasmaid>>c>>p.mobility>>c>>p.nhours>>c>>p.industry>>c>>p.NS
>>c>>p.trans_mode>>c>>p.trans_time>>c>>p.oversea>>c>>p.nFamilySize>>c>>p.f_nuclei>>c>>p.generation>>c>>p.youngest
>>c>>p.numwork>>c>>p.hincome>>c>>p.momid>>c>>p.dadid>>c>>p.unit_id>>c>>p.nHomeTract>>c>>p.nHomeComm>>c>>p.nHomeNeighborhood     //Maybe don't need to read all these
>>c>>p.x_coor_home>>c>>p.y_coor_home>>c>>p.nWorkplace>>c>>p.nDayTract>>c>>p.nDayComm>>c>>p.nDayNeighborhood
>>c>>p.x_coor_work>>c>>p.y_coor_work>>c>>p.nSchplace>>c>>p.nSchComm>>c>>p.nSchNeighborhood>>c>>p.x_coor_school
>>c>>p.y_coor_school;
	count++;
	if(count%1000==0)
		std::cout<<count<<" number read."<<endl;
	if(iss.eof()) break;
			pvec.push_back(p);
			temp.push_back(p.nHomeComm);
		
	}
	iss.close();
	sort(pvec.begin(),pvec.end(),less_than_key());
	sort(temp.begin(),temp.end());
	temp.erase(unique(temp.begin(),temp.end()),temp.end());

	int counter=0;
	std::vector<Person>::iterator pend=pvec.end();
	for(std::vector<Person>::iterator it=pvec.begin();it!=pend;it++){
		Person &p=*it;
		p.id=counter++;
	}
	std::string Revise=name+"2.csv";
	std::ofstream file(Revise.c_str());
	count=0;
//file<<"id"<<","<<"exactAge"<<","<<"age"<<","<<"gender"<<","<<"race"<<","<<"citizen"<<","<<"marital"<<","<<"number_children"<<","<<"nSchoolType"<<","<<"qualification"<<","<<"work"<<","<<"income"<<","<<"headhouse"<<","<<"occupation"<<","<<"religion"<<","<<"partnerid"<<","<<"family"<<","<<"dwelling"<<","<<"hasmaid"<<","<<"mobility"<<","<<"nhours"<<","<<"industry"<<","<<"NS"<<","<<"trans_mode"<<","<<"trans_time"<<","<<"oversea"<<","<<"nFamilySize"<<","<<"f_nuclei"<<","<<"generation"<<","<<"youngest"<<","<<"numwork"<<","<<"hincome"<<","<<"momid"<<","<<"dadid"<<","<<"unit_id"<<","<<"zone_home"<<","<<"nHomeComm"<<","<<"postcode_home"<<","<<"x_coor_home"<<","<<"y_coor_home"<<","<<"nWorkplace"<<","<<"zone_work"<<","<<"subzone_work"<<","<<"postcode_work"<<","<<"x_coor_work"<<","<<"y_coor_work"<<","<<"nSchplace"<<","<<"nSchComm"<<","<<"nSchNeighborhood"<<","<<"x_coor_school"<<","<<"y_coor_school"<<std::endl;
file<<"id"<<","<<"exactAge"<<","<<"age"<<","<<"gender"<<","<<"nSchoolType"<<","<<"work"<<","<<"family"<<","<<"nFamilySize"<<","<<"nHomeTract"<<","<<"nHomeComm"<<","<<"nHomeNeighborhood"<<","<<"x_coor_home"<<","<<"y_coor_home"<<","<<"nWorkplace"<<","<<"nDayTract"<<","<<"nDayComm"<<","<<"nDayNeighborhood"<<","<<"x_coor_work"<<","<<"y_coor_work"<<","<<"nSchplace"<<","<<"nSchComm"<<","<<"nSchNeighborhood"<<","<<"x_coor_school"<<","<<"y_coor_school"<<std::endl;
	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++){
		Person &p=*it;
/*
file<<p.id<<","<<p.exactAge<<","<< p.age<<","<<p.gender<<","<<p.race<<","<<p.citizen<<","<<p.marital<<","<<p.number_children
<<","<<p.nSchoolType<<","<<p.qualification<<","<<p.work<<","<<p.income<<","<<p.headhouse<<","<<p.occupation<<","<<p.religion
<<","<<p.partnerid<<","<<p.family<<","<<p.dwelling<<","<<p.hasmaid<<","<<p.mobility<<","<<p.nhours<<","<<p.industry<<","<<p.NS
<<","<<p.trans_mode<<","<<p.trans_time<<","<<p.oversea<<","<<p.nFamilySize<<","<<p.f_nuclei<<","<<p.generation<<","<<p.youngest
<<","<<p.numwork<<","<<p.hincome<<","<<p.momid<<","<<p.dadid<<","<<p.unit_id<<","<<p.nHomeTract<<","<<p.nHomeComm<<","<<p.nHomeNeighborhood     
<<","<<p.x_coor_home<<","<<p.y_coor_home<<","<<p.nWorkplace<<","<<p.nDayTract<<","<<p.nDayComm<<","<<p.nDayNeighborhood
<<","<<p.x_coor_work<<","<<p.y_coor_work<<","<<p.nSchplace<<","<<p.nSchComm<<","<<p.nSchNeighborhood<<","<<p.x_coor_school
<<","<<p.y_coor_school<<std::endl;
*/
file<<p.id << ","<<p.exactAge << ","<<p.age << ","<<p.gender << ","<<p.nSchoolType << ","<<p.work << ","<<p.family << ","<<p.nFamilySize << ","<<p.nHomeTract << ","<<p.nHomeComm << ","<<p.nHomeNeighborhood << ","<<p.x_coor_home << ","<<p.y_coor_home << ","<<p.nWorkplace << ","<<p.nDayTract << ","<<p.nDayComm << ","<<p.nDayNeighborhood << ","<<p.x_coor_work << ","<<p.y_coor_work << ","<<p.nSchplace << ","<<p.nSchComm << ","<<p.nSchNeighborhood << ","<<p.x_coor_school << ","<<p.y_coor_school <<std::endl;
	count++;
	if(count%1000==0)
		std::cout<<count<<" number done."<<endl;
	}
	file.close();
	std::cout<<temp.size()<<","<<pvec[0].nHomeComm<<","<<pvec[pvec.size()-1].nHomeComm<<std::endl;

}
