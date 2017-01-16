#include "StringMathApril.h"


int main(){
	ofstream WriteIT;
	string downlimit = "0";
	string uplimit = "5000";
	string sol = "0/1";
	string threadC = "0";
	while (isLessthan(downlimit, uplimit)){
		string a = "0", b = "0", c = "0", d = "0", e = "0";
		thread f(&PI, downlimit, AddTwoStrings(downlimit, IntDivision(uplimit, "100")), threadC, ref(a));
		downlimit = AddTwoStrings(downlimit, IntDivision(uplimit, "100")); 
		threadC = AddTwoStrings(threadC, "1");
		cout << downlimit << endl;
		thread g(&PI, downlimit, AddTwoStrings(downlimit, IntDivision(uplimit, "100")), threadC, ref(b));
		downlimit = AddTwoStrings(downlimit, IntDivision(uplimit, "100"));
		threadC = AddTwoStrings(threadC, "1");
		cout << downlimit << endl;
		thread h(&PI, downlimit, AddTwoStrings(downlimit, IntDivision(uplimit, "100")), threadC, ref(c));
		downlimit = AddTwoStrings(downlimit, IntDivision(uplimit, "100"));
		threadC = AddTwoStrings(threadC, "1");
		thread i(&PI, downlimit, AddTwoStrings(downlimit, IntDivision(uplimit, "100")), threadC, ref(d));
		downlimit = AddTwoStrings(downlimit, IntDivision(uplimit, "100"));
		threadC = AddTwoStrings(threadC, "1");
		thread j(&PI, downlimit, AddTwoStrings(downlimit, IntDivision(uplimit, "100")), threadC, ref(e));
		downlimit = AddTwoStrings(downlimit, IntDivision(uplimit, "100"));
		threadC = AddTwoStrings(threadC, "1");
		f.join();
		g.join();
		h.join();
		i.join();
		j.join();

		sol = AddingFractions(a, sol);
		sol = AddingFractions(b, sol);
		sol = AddingFractions(c, sol);
		sol = AddingFractions(d, sol);
		sol = AddingFractions(e, sol);

		
		WriteIT.open("PiThisFile.txt", ios::app);

		WriteIT << PrintTime() << "\n";
		WriteIT << sol << " \n";
		WriteIT.close();
	}
	//string value = BuildPiVal();
	//string x = "100120461139116270424863257857365052519382268078921631620663432149259523543115966781107636748334046880520649264425521227395859117503556027708402084703287802550382311630644065294338898250114264022349406791845474886097793265055226833090553363196494195966669312299275589470003214352942833195908724288618867539511488431046935797658986145244168956405292836369260113213350576454494300713465746710001403337310577415648364605850712096402852078885187831724413514945870900546282886254611150804383235202613248";
	//string y = "31869332589860736967112531625923865361073023590090733957225495923444918819883643281979529632713726286534578248205315331035613877750869355101073849835964128398339643160153193516602236646374081182960515578471354935767251217871584790729828899910298211379109613063670407847850629187731641544283268056769035773987289916268893154656057146586402572939394395818446193959706734265676771373046888142999086349927806095753980478979935458670564967979832746705606583878506568940474716483803760281546110740593375";
	WriteIT.open("PiVal.txt");
	WriteIT << sol << "\n \n";
	string x = sol.substr(0, sol.find('/'));
	string y = sol.substr(sol.find('/') + 1);
	sol = BigNumDivision(x,y);
	WriteIT << sol << "\n";
	cout << sol << endl;
	cout << endl;
	string acc = decimalAcc(sol, piVal);
	cout << "Accurate to : " << acc << " decimal places. " << endl;
	WriteIT << "Accurate to : " << acc << " decimal places. " << endl;
	WriteIT.close();
	system("pause");
}


/*
string BigNumDivision(string x, string y){
	string solution = "";
	// we are taking x divided by y
	// develop the multiples of y
	vector<string> MultY;
	int k = 0;
	for(string i = "0"; isLessthan(i , "11"); i = AddTwoStrings(i, "1"))
		{
			MultY.push_back(MULTI(i, y));
			cout << i << " : " << MultY[k] << endl;
			k += 1;
		}
	// we can develop a list of y multiples which we can check if y is lessthan or equal to x if so then subtract that number from the current x
	int Len = x.length();
	string NewX = "";
	k = 0;
	while(k < Len){
		NewX = NewX + x[k];
		k++;
		for(int j = 0; j < 11; j++)
		if(!isLessthan(MultY[j], NewX)){
			if(isEqualTo(MultY[j],NewX)){
				NewX = "0";
				solution = solution + (char)(j + 48);
			}
			else{
				NewX = SUB(NewX, MultY[j-1]);
				solution = solution + (char)(j + 47);
				j += 11;
			}
		}

		while(NewX[0] == '0'){
			if(NewX.length() == 1){
				break;
			}
			else{
				NewX = NewX.substr(1);
			}

		}
		while(solution[0] == '0'){
			if(solution.length() == 1){
				break;
			}
			else{
				solution = solution.substr(1);
			}

		}
	}
	string dec = "0";
	solution = solution + ".";
	while(!isEqualTo(NewX, "0") && isLessthan(dec, T)){
		NewX = NewX + "0";
		for(int j = 0; j < 11; j++){
		if(!isLessthan(MultY[j], NewX)){
			if(isEqualTo(MultY[j],NewX)){
				NewX = "0";
				solution = solution + (char)(j + 48);
			}
			else{
				NewX = SUB(NewX, MultY[j-1]);
				solution = solution + (char)(j + 47);
				j += 11;
			}
		}
	}	
	dec = AddTwoStrings(dec, "1");
	
		while(NewX[0] == '0'){
			if(NewX.length() == 1){
				return solution;
			}
			else{
				NewX = NewX.substr(1);
			}

		}
	
	}

	return solution;
}


string decimalAcc(string check, string value){
	bool error = true;
	string start = "0";
	while(check.length() != 0 && error){
		char C = check[0];
		char V = value[0];
		check = check.substr(1);
		value = value.substr(1);
		if(C != V){
			error = false;
		}
		else
		{
			start = AddTwoStrings(start, "1");
		}
	}

	return start;

}


*/