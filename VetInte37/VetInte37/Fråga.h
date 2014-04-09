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

		_cmd->CommandText = "INSERT INTO [dbo].[frågor] VALUES (@frågeNo ,@examensID, @text, @rättsvar)";
		_cmd->Parameters->Add(gcnew SqlParameter("@frågeNo", SqlDbType::Int));
		_cmd->Parameters["@frågeNo"]->Value = _frågeNo;
		_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
		_cmd->Parameters["@examensID"]->Value = _examensID;
		_cmd->Parameters->Add(gcnew SqlParameter("@text", SqlDbType::Char));
		_cmd->Parameters["@text"]->Value = _text;
		_cmd->Parameters->Add(gcnew SqlParameter("@rättsvar", SqlDbType::Int));
		_cmd->Parameters["@rättsvar"]->Value = _rättSvar;
		_cmd->ExecuteNonQuery();
		_cmd->Parameters->Clear();

		for (int i = 0; i < _svar->Length; i++)
		{
			_cmd->CommandText = "INSERT INTO [dbo].[svar] VALUES (@svarsNo ,@frågeNo, @examensID, @text)";
			_cmd->Parameters->Add(gcnew SqlParameter("@svarsNo", SqlDbType::Int));
			_cmd->Parameters["@svarsNo"]->Value = i+1;
			_cmd->Parameters->Add(gcnew SqlParameter("@frågeNo", SqlDbType::Int));
			_cmd->Parameters["@frågeNo"]->Value = _frågeNo;
			_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
			_cmd->Parameters["@examensID"]->Value = _examensID;
			_cmd->Parameters->Add(gcnew SqlParameter("@text", SqlDbType::Char));
			_cmd->Parameters["@text"]->Value = _svar[i];
			_cmd->ExecuteNonQuery();
			_cmd->Parameters->Clear();
		}

	}

private:
	DbCommand ^ _cmd;
	int _frågeNo;
	String ^ _examensID;
	String ^ _text;
	array<String^>^ _svar;
	int _rättSvar;


};