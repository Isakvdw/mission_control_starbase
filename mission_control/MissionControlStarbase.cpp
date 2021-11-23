#include <exception>
#include <vector>
#include <iostream>
using namespace std;

#include "MissionControlStarbase.h"

/**
 * @brief Construct a rocket
 * @details Use a passed builder to build
 * 			and put a rocket together for use.
 * 			Also allow user to change builder
 * 			parameters.
 * @param aBuilder 
 * @return Rocket* 
 */
Rocket* MissionControlStarbase::construct(Builder* aBuilder) {
	string input1="";
	while(input1 != "1" && input1 != "2"){
		cout<<"Please select a rocket?"<<endl;
		cout<<"1. Falcon 9"<<endl;
		cout<<"2. Falcon Heavy"<<endl;
		getline(cin,input1);
		cout<<endl;
	}
	aBuilder->setFirstStageBoosters();
	string input2="";
	while(input2 != "1" && input2 != "2" && input2 != "3"){
		cout<<"Please select a payload?"<<endl;
		cout<<"1. Cargo"<<endl;
		cout<<"2. Cargo and crew"<<endl;
		cout<<"3. Starlink"<<endl;
		getline(cin,input2);
		cout<<endl;
	}
	if (input1 == "1")
	{
		aBuilder->setRocketType(Rocket::FALCON9);
	}
	else
	{
		aBuilder->setRocketType(Rocket::FALCONHEAVY);
	}
	if (input2 == "1")
	{
		aBuilder->setPayloadType(Payload::CARGO);
		string DESC = "";
		cout<<"Please input cargo!"<<endl;
		getline(cin,DESC);
		cout<<endl;
		aBuilder->setPayload(DESC);
	}
	else if (input2 == "2")
	{
		vector<string> names;
		vector<string> ranks;
		string nm;
		string rk;
		aBuilder->setPayloadType(Payload::CREW);
		int pos = 0;
		bool done = false;
		while(pos < 7 && !done)
		{
			cout<<"Enter Astronaut name!"<<endl;
			getline(cin,nm);
			cout<<"Enter Rank!"<<endl;
			getline(cin,rk);
			cout<<endl;
			names.push_back(nm);
			ranks.push_back(rk);
			cout<<"Continue? (Y/N)"<<endl;
			getline(cin,nm);
			cout<<endl;
			if (nm == "N" || nm == "n")
			{
				done = true;
			}
			pos++;
		}	
		aBuilder->setPayload(names,ranks);
	}
	else
	{
		aBuilder->setPayloadType(Payload::STARLINK);
		string in = "";
		int amount = -1;
		while(amount < 0)
		{
			cout<<"Please input number of satellites!"<<endl;
			getline(cin,in);
			amount = stoi(in);
			cout<<endl;
		}
		aBuilder->setPayload(amount);
	}
	return aBuilder->buildRocket();
}

/**
 * @brief Launch Rocket
 * @details Use rocket's states to go through
 * 			it preparations and then launch.
 * @param R 
 */
void MissionControlStarbase::launch(Rocket * R) {
	throw "Not implemented yet";
}
