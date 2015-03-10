#include<iostream>
#include<fstream>
#include"reader.h"
#include<vector>
#include<sstream>
#include<iterator>
#include<iomanip>
#include<algorithm>

int main(){

	std::string name;
	std::cout<<"Please input file name to be converted \n(make sure it's in the correct directory!): ";
	std::cin>>name;
	//zone-subzone relation list
        int zone_subzone[]={1,0,1,1,1,2,1,3,1,4,1,5,1,6,1,7,1,8,2,9,2,10,2,11,2,12,2,13,2,14,2,15,2,16,3,17,3,18,3,19,4,20,4,21,4,22,
4,23,5,24,5,25,5,26,5,27,5,28,5,29,5,30,5,31,5,32,6,33,6,34,6,35,6,36,6,37,6,38,6,39,6,40,6,41,6,42,6,43,6,44,6,45,6,46,6,47,7,48,7,
49,7,50,7,51,7,52,7,53,7,54,8,55,8,56,8,57,8,58,8,59,8,60,8,61,8,62,9,63,10,64,10,65,11,66,12,67,12,68,12,69,12,70,12,71,12,72,12,73,
13,74,13,75,13,76,13,77,13,78,13,79,13,80,13,81,14,82,14,83,15,84,15,85,15,86,15,87,15,88,16,89,16,90,16,91,16,92,16,93,16,94,17,95,17,
96,17,97,17,98,17,99,17,100,17,101,18,102,18,103,18,104,18,105,18,106,18,107,18,108,19,109,19,110,19,111,19,112,19,113,19,114,19,115,19,
116,20,117,21,118,22,119,23,120,24,121,24,122,24,123,24,124,24,125,25,126,25,127,25,128,26,129,26,130,26,131,26,132,27,133,28,134,28,135,
28,136,28,137,28,138,29,139,29,140,29,141,30,142,31,143,31,144,31,145,31,146,32,147,32,148,32,149,32,150,32,151,32,152,33,153,33,154,33,155,
33,156,33,157,34,158,34,159,34,160,34,161,34,162,35,163,35,164,35,165,35,166,35,167,36,168,36,169,36,170,36,171,36,172,36,173,36,174,36,175,
36,176,36,177,36,178,36,179,37,180,37,181,37,182,37,183,37,184,38,185,38,186,38,187,38,188,38,189,38,190,39,191,40,192,40,193,40,194,40,195,
40,196,40,197,41,198,41,199,41,200,41,201,41,202,41,203,42,204,42,205,42,206,42,207,43,208,44,209,44,210,45,211,45,212,46,213,47,214,47,215,
47,216,47,217,47,218,48,219,48,220,48,221,48,222,48,223,49,224,49,225,49,226,49,227,50,228,51,229,51,230,51,231,51,232,51,233,51,234,51,235,
51,236,51,237,51,238,51,239,51,240,52,241,52,242,52,243,52,244,52,245,52,246,53,247,53,248,54,249,55,250,55,251,55,252,55,253,55,254,55,255,
55,256,56,257,56,258,56,259,56,260,56,261,56,262,56,263,56,264,56,265};

	int subzone_newsub[]={0,0,1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,14,14,15,15,16,16,17,17,18,18,19,19,
24,20,25,21,26,22,27,23,28,24,29,25,30,26,31,27,33,28,34,29,35,30,36,31,37,32,38,33,39,34,40,35,41,36,42,37,43,38,44,39,45,40,46,
41,47,42,48,43,49,44,50,45,51,46,52,47,53,48,54,49,55,50,56,51,57,52,58,53,59,54,60,55,61,56,62,57,64,58,65,59,67,60,68,61,69,62,
70,63,71,64,72,65,73,66,74,67,75,68,76,69,77,70,78,71,79,72,80,73,81,74,82,75,83,76,84,77,85,78,86,79,87,80,88,81,89,82,90,83,91,
84,92,85,93,86,94,87,95,88,96,89,97,90,98,91,99,92,100,93,101,94,102,95,103,96,104,97,105,98,106,99,107,100,108,101,109,102,110,
103,111,104,112,105,113,106,114,107,115,108,116,109,118,110,121,111,122,112,123,113,129,114,130,115,131,116,132,117,134,118,135,
119,136,120,137,121,138,122,143,123,144,124,145,125,146,126,147,127,148,128,149,129,150,130,151,131,152,132,163,133,164,134,165,
135,166,136,167,137,168,138,169,139,170,140,171,141,172,142,173,143,174,144,175,145,176,146,177,147,178,148,180,149,181,150,182,
151,183,152,184,153,185,154,186,155,187,156,188,157,189,158,190,159,192,160,193,161,194,162,195,163,196,164,197,165,198,166,199,
167,200,168,201,169,202,170,203,171,204,172,205,173,206,174,207,175,209,176,210,177,219,178,220,179,221,180,222,181,224,182,225,
183,226,184,227,185,229,186,230,187,231,188,232,189,233,190,234,191,235,192,236,193,237,194,238,195,239,196,240,197,250,198,251,
199,252,200,253,201,254,202,255,203,256,204,257,205,258,206,259,207,260,208,261,209,262,210,263,211,264,212,265,213,142,214,20,
215,21,216,22,217,23,218,32,219,63,220,66,221,117,222,119,223,120,224,124,225,125,226,126,227,127,228,128,229,133,230,139,231,140,
232,141,233,153,234,154,235,155,236,156,237,157,238,158,239,159,240,160,241,161,242,162,243,179,244,191,245,208,246,211,247,212,248,
213,249,214,250,215,251,216,252,217,253,218,254,223,255,228,256,241,257,242,258,243,259,244,260,245,261,246,262,247,263,248,264,249,265};

	cout<<subzone_newsub[213*2]<<","<<subzone_newsub[213*2+1]<<endl;
	std::vector< int > zone_values;
	std::vector<Person> pvec;
	std::vector<Zone> zvec;
	std::ostringstream oss;
	std::string dummy;
	oss.str(name+".csv");//input filename
	std::ifstream iss(oss.str().c_str());
	
	if(!iss){
		std::cout<<"Sorry, "<<name<<" not found. Could it be somewhere else?\n";
		exit(-1);
	}
	getline(iss,dummy);
	while(iss.good()){
		Person p;
		char c;	iss>>p.id>>c>>p.exactAge>>c>>p.gender>>c>>p.race>>c>>p.citizen>>c>>p.marital>>c>>p.number_children>>c>>p.nSchoolType>>c>>p.qualification>>c>>p.work>>c>>
p.income>>c>>p.headhouse>>c>>p.occupation>>c>>p.religion>>c>>p.partnerid>>c>>p.family>>c>>p.dwelling>>c>>p.hasmaid>>c>>p.mobility>>c>>p.nhours>>c>>
p.industry>>c>>p.NS>>c>>p.trans_mode>>c>>p.trans_time>>c>>p.oversea>>c>>p.nFamilySize>>c>>p.f_nuclei>>c>>p.generation>>c>>p.youngest>>c>>p.numwork>>c>>
p.hincome>>c>>p.momid>>c>>p.dadid>>c>>p.unit_id>>c>>p.nHomeComm>>c>>p.postcode_home>>c>>p.x_coor_home>>c>>p.y_coor_home>>c>>p.nWorkplace>>c>>p. subzone_work>>c>>p.postcode_work>>c>>p.x_coor_work>>c>>p.y_coor_work>>c>>p.nSchplace>>c>>p.nSchComm>>c>>p.nSchNeighborhood>>c>>
p.x_coor_school>>c>>p.y_coor_school;
	if(iss.eof()) break;
		p.nHomeComm=subzone_newsub[2*p.nHomeComm];
		pvec.push_back(p);
		
	}
	iss.close();
	//pvec.pop_back();
//convert from subzone to zone
	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++){
		Person &p=*it;
		for(int i=1;i<266*2;i=i+2){
			if(p.nHomeComm==zone_subzone[i]){
				p.zone_home=zone_subzone[i-1];
				break;
			}
		}
	}

	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++)
	{
		Person &p = *it;
		for(int i=1;i<608;i=i+2){
				if(p.subzone_work==zone_subzone[i]&&p.subzone_work!=-1){
					p.zone_work=zone_subzone[i-1];
					break;
			}
		}
	}
	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++){
		Person &p=*it;
		if(p.exactAge>=0 && p.exactAge<=4)
			p.age=0;
		else if(p.exactAge>=5 && p.exactAge<=18)
			p.age=1;
		else if(p.exactAge>=19 && p.exactAge<=29)
			p.age=2;
		else if(p.exactAge>=30 && p.exactAge<=64)
			p.age=3;
		else 
			p.age=4;

	}
	std::vector< int > zone_work_id;
	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++){
		Person &p = *it;
		zone_work_id.push_back(p.postcode_work);
		zone_work_id.push_back(p.nSchNeighborhood);
	}
	sort(zone_work_id.begin(),zone_work_id.end());
	zone_work_id.erase(unique(zone_work_id.begin(),zone_work_id.end()),zone_work_id.end());
	for(int i=0;i<zone_work_id.size();i++)		
		for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++){
			Person &p=*it;
			if(p.postcode_work==zone_work_id[i] && p.nSchNeighborhood==-1){
				p.nWorkplace=i;
			}
			if(p.postcode_work==-1 && p.nSchNeighborhood==zone_work_id[i]){
				p.nWorkplace=i;
			}
			if(p.postcode_work==-1 && p.nSchNeighborhood==-1)
				p.nWorkplace=-1;
		}
	std::string Revise=name+"-Revised input.csv";
	std::ofstream file(Revise.c_str());
file<<"id"<<","<<"exactAge"<<","<<"age"<<","<<"gender"<<","<<"race"<<","<<"citizen"<<","<<"marital"<<","<<"number_children"<<","<<"nSchoolType"<<","<<"qualification"<<","<<"work"<<","<<"income"<<","<<"headhouse"<<","<<"occupation"<<","<<"religion"<<","<<"partnerid"<<","<<"family"<<","<<"dwelling"<<","<<"hasmaid"<<","<<"mobility"<<","<<"nhours"<<","<<"industry"<<","<<"NS"<<","<<"trans_mode"<<","<<"trans_time"<<","<<"oversea"<<","<<"nFamilySize"<<","<<"f_nuclei"<<","<<"generation"<<","<<"youngest"<<","<<"numwork"<<","<<"hincome"<<","<<"momid"<<","<<"dadid"<<","<<"unit_id"<<","<<"zone_home"<<","<<"nHomeComm"<<","<<"postcode_home"<<","<<"x_coor_home"<<","<<"y_coor_home"<<","<<"nWorkplace"<<","<<"zone_work"<<","<<"subzone_work"<<","<<"postcode_work"<<","<<"x_coor_work"<<","<<"y_coor_work"<<","<<"nSchplace"<<","<<"nSchComm"<<","<<"nSchNeighborhood"<<","<<"x_coor_school"<<","<<"y_coor_school"<<std::endl;
	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++){
		Person &p=*it;
file<<p.id<<","<<p.exactAge<<","<<(int)p.age<<","<<p.gender<<","<<p.race<<","<<p.citizen<<","<<p.marital<<","<<p.number_children<<","<<p.nSchoolType<<","<<p.qualification<<","<<p.work<<","<<p.
income<<","<<p.headhouse<<","<<p.occupation<<","<<p.religion<<","<<p.partnerid<<","<<p.family<<","<<p.dwelling<<","<<p.hasmaid<<","<<p.mobility<<","<<p.nhours<<","<<p.
industry<<","<<p.NS<<","<<p.trans_mode<<","<<p.trans_time<<","<<p.oversea<<","<<(int)p.nFamilySize<<","<<p.f_nuclei<<","<<p.generation<<","<<p.youngest<<","<<p.numwork<<","<<p.
hincome<<","<<p.momid<<","<<p.dadid<<","<<p.unit_id<<","<<p.zone_home<<","<<p.nHomeComm<<","<<p.postcode_home<<","<<p.x_coor_home<<","<<p.y_coor_home<<","<<p.nWorkplace<<","<<p.zone_work<<
","<<p.subzone_work<<","<<p.postcode_work<<","<<p.x_coor_work<<","<<p.y_coor_work<<","<<p.nSchplace<<","<<p.nSchComm<<","<<p.nSchNeighborhood<<","<<p.x_coor_school<<","<<p.y_coor_school<<std::endl;
	}
	file.close();
//for file
/*	for(std::vector<Person>::iterator it = pvec.begin();it!=pvec.end();it++)
	{
		Person &p = *it;
		zone_values.push_back(p.zone_home);
	}
	sort(zone_values.begin(),zone_values.end());
	zone_values.erase(unique(zone_values.begin(),zone_values.end()),zone_values.end());

	for(int i= 0;i<zone_values.size();i++)
	{
		Zone z;
		z.id=zone_values[i];
		z.pop=0;
		z.employable=0;
		z.employed=0;
		z.x=0;
		z.y=0;
		std::vector<int> temp_z;
		for(std::vector<Person>::iterator it=pvec.begin();it!=pvec.end();it++)
		{
			Person &p = *it;
			if(p.zone_home==z.id)
			{
				z.pop++;
				z.x+=p.x_coor_home;
				z.y+=p.y_coor_home;
				if(p.exactAge>=16 && p.exactAge<=65)
				{
					z.employable++;
					if(p.occupation!=0)
					{
						z.employed++;
						z.workzones.push_back(p.zone_work);
					}
				}
				
			}
		}
		temp_z=z.workzones;
		sort(z.workzones.begin(),z.workzones.end());
		z.workzones.erase(unique(z.workzones.begin(),z.workzones.end()),z.workzones.end());
		for(int i=0;i<z.workzones.size();i++)
		{
			z.workpop.push_back(std::count(temp_z.begin(),temp_z.end(),z.workzones[i]));
		}
		z.x=z.x/z.pop;
		z.y=z.y/z.pop;
		zvec.push_back(z);
	}

/*
//writing into input files
	std::string tract_file=name+"-tracts.dat";
	std::string employment_file=name+"-employment.dat";
	std::string wf_file=name+"-wf.dat";
	std::ofstream file(tract_file.c_str());
	for(std::vector<Zone>::iterator it=zvec.begin();it!=zvec.end();it++)
	{
		Zone &z=*it;
		file<<1<<","<<std::setfill('0')<<std::setw(3)<<1<<","<<std::setfill('0')<<std::setw(6)<<z.id<<","<<z.pop<<","<<z.x<<","<<z.y<<endl;
	}
	file.close();
	file.open(employment_file.c_str());
	for(std::vector<Zone>::iterator it=zvec.begin();it!=zvec.end();it++)
	{
		Zone &z=*it;
		file<<1<<" "<<std::setfill('0')<<std::setw(3)<<1<<" "<<std::setfill('0')<<std::setw(6)<<z.id<<" "<<z.employed<<" "<<z.employable<<endl;
	}
	file.close();
	file.open(wf_file.c_str());
	for(std::vector<Zone>::iterator it=zvec.begin();it!=zvec.end();it++)
	{
		Zone &z=*it;
		for(int i=0;i<z.workzones.size();i++)
			file<<1<<" "<<std::setfill('0')<<std::setw(3)<<1<<" "<<std::setfill('0')<<std::setw(6)<<z.id<<" "<<1<<" "<<std::setfill('0')<<std::setw(3)<<1<<" "<<std::setfill('0')<<std::setw(6)<<z.workzones[i]<<" "<<z.workpop[i]<<endl;
	}
	file.close();*/
}
