#pragma once
#include "stdafx.h"
#include <cliext\vector>

using namespace System;
using namespace cliext;

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Data::Common;
using namespace System::Configuration;
using namespace System::Data::SqlClient;


ref class Personal
{

public:
	Personal (DbCommand ^ cmd, String ^ personnummer)
	{
		_cmd = cmd;
		_personnummer = personnummer;
	}


	static String ^ hämtaFörnamn(DbCommand^ cmd, int sid)
	{
		cmd->CommandText="SELECT * FROM [dbo].[Personal] WHERE id=@sid";
		cmd->Parameters->Add(gcnew SqlParameter("@sid", SqlDbType::Int));
		cmd->Parameters["@sid"]->Value=sid;
		DbDataReader^ reader = cmd->ExecuteReader();
		reader->Read();
		String ^returner = reader->GetString(1);
		reader->Close();
		cmd->Parameters->Clear();
		return returner;
	}

	void getPersonalDetails()
	{
		_cmd->CommandText = "SELECT * FROM [dbo].[personal] WHERE personnummer=@personnummer";
		_cmd->Parameters->Add(gcnew SqlParameter( "@personnummer", SqlDbType::Char));
		_cmd->Parameters["@personnummer"]->Value=_personnummer;
		DbDataReader ^ reader = _cmd->ExecuteReader();
		reader->Read();

		reader->Close();
		_cmd->Parameters->Clear();
	}

private:
	String ^ _personnummer;
	String ^ _namn;
	String ^ _hemadress;
	String ^ _hemtelefonnummer;
	String ^ _jobbtelefonnummer;
	String ^ _emejl;
	String ^ _anställningsnummer;
	String ^ _titel;
	int _lönetillägg; //Pekare?
	bool _lärareFLAG;
	bool _kursansvarigFLAG;
	bool _programansvarigFLAG;
	bool _avdelningschefFLAG;
	DbCommand ^ _cmd;

};