#pragma once
#include <string>
#include "stdafx.h"

using namespace std;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::Common;
using namespace System::Configuration;
using namespace System::Data::SqlClient;

ref class Fr�ga 
{
public:
	Fr�ga (DbCommand ^ cmd, int fr�geNo, String ^ examensID, String ^ text, array<String^>^ svar, int r�ttSvar)
	{
		_cmd = cmd;
		_fr�geNo = fr�geNo;
		_examensID = examensID;
		_text = text;
		_svar = svar;
		_r�ttSvar = r�ttSvar;
	}

	void addToDb()
	{
		
	}

private:
	DbCommand ^ _cmd;
	int _fr�geNo;
	String ^ _examensID;
	String ^ _text;
	array<String^>^ _svar;
	int _r�ttSvar;


};