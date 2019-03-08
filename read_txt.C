    TString filename=this->dirname+"/"+this->i_process+"/"+it->first+".txt";
    //cout<<filename<<endl;                                                                                                                    
    ifstream openFile(filename);
    if( openFile.is_open() ){
      string line;
      while(getline(openFile, line)){
	//cout << line << endl;                                                                                                                
	this->m_value[it->first]=std::stod(line);
        cout<<"check value="<<it->second<<endl;

      }
      openFile.close();
    }
