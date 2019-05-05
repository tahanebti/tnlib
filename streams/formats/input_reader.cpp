		int number;
		cin>>number;
		cin.good(); cin.bad(); cin.eof();

		//check valid argument
		if(!cin.fail()) {cout<<"read integer success "<<endl;}
		else{cout<<"sorry invalid_argument "<<endl;}

		//keep enter to get the valid argument
		while(cin.fail()){
			cout<<"Enter a valid integer, Try again:";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			cin>>number;
		}
		cout<<"\nthe number is: "<<number<<endl;