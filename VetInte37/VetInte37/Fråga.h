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

ref class Fråga 
{
public:
	Fråga (DbCommand ^ cmd, int frågeNo, String ^ examensID, String ^ text, array<String^>^ svar, int rättSvar)
	{
		_cmd = cmd;
		_frågeNo = frågeNo;
		_examensID = examensID;
		_text = text;
		_svar = svar;
		_rättSvar = rättSvar;
	}

	void addToDb()
	{
		
	}

private:
	DbCommand ^ _cmd;
	int _frågeNo;
	String ^ _examensID;
	String ^ _text;
	array<String^>^ _svar;
	int _rättSvar;


};