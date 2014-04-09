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

		_cmd->CommandText = "INSERT INTO [dbo].[fr�gor] VALUES (@fr�geNo ,@examensID, @text, @r�ttsvar)";
		_cmd->Parameters->Add(gcnew SqlParameter("@fr�geNo", SqlDbType::Int));
		_cmd->Parameters["@fr�geNo"]->Value = _fr�geNo;
		_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
		_cmd->Parameters["@examensID"]->Value = _examensID;
		_cmd->Parameters->Add(gcnew SqlParameter("@text", SqlDbType::Char));
		_cmd->Parameters["@text"]->Value = _text;
		_cmd->Parameters->Add(gcnew SqlParameter("@r�ttsvar", SqlDbType::Int));
		_cmd->Parameters["@r�ttsvar"]->Value = _r�ttSvar;
		_cmd->ExecuteNonQuery();
		_cmd->Parameters->Clear();

		for (int i = 0; i < _svar->Length; i++)
		{
			_cmd->CommandText = "INSERT INTO [dbo].[svar] VALUES (@svarsNo ,@fr�geNo, @examensID, @text)";
			_cmd->Parameters->Add(gcnew SqlParameter("@svarsNo", SqlDbType::Int));
			_cmd->Parameters["@svarsNo"]->Value = i+1;
			_cmd->Parameters->Add(gcnew SqlParameter("@fr�geNo", SqlDbType::Int));
			_cmd->Parameters["@fr�geNo"]->Value = _fr�geNo;
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
	int _fr�geNo;
	String ^ _examensID;
	String ^ _text;
	array<String^>^ _svar;
	int _r�ttSvar;


};