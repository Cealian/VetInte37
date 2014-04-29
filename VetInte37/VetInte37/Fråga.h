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
	/* ----- Set Q ----- */
	void setDetails(DbCommand ^ cmd, int fr�geNo, String ^ examensID, String ^ text, array<String^>^ svar, int r�ttSvar)
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

	/* ----- Get Q ----- */

	
	void setDetails(DbCommand ^ cmd, int fr�geNo, String ^ examensID)
	{
		_cmd = cmd;
		_fr�geNo = fr�geNo;
		_examensID = examensID;

		getQuestion();

	}

	String ^ getText()
	{
		return _text;
	}
	
	String ^getAnswer(int svarsNo)
	{
		_cmd->CommandText="SELECT * FROM [dbo].[svar] WHERE fr�geNo=@fr�geNo AND examensID = @examensID AND svarsNo = @svarsNo";
		
		_cmd->Parameters->Add(gcnew SqlParameter("@fr�geNo", SqlDbType::Int));
		_cmd->Parameters["@fr�geNo"]->Value=_fr�geNo;

		_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
		_cmd->Parameters["@examensID"]->Value=_examensID;

		_cmd->Parameters->Add(gcnew SqlParameter("@svarsNo", SqlDbType::Int));
		_cmd->Parameters["@svarsNo"]->Value=svarsNo;

		DbDataReader^ reader = _cmd->ExecuteReader();

		reader->Read();

		String ^text = reader->GetString(3);

		reader->Close();
		_cmd->Parameters->Clear();

		return text;
	}

	int getR�ttSvar()
	{
		return _r�ttSvar;
	}

	int noOfQuestions()
	{
		
		_cmd->CommandText="SELECT COUNT(*) FROM [dbo].[fr�gor] WHERE examensID = @examensID";
		
		_cmd->Parameters->Add(gcnew SqlParameter("@fr�geNo", SqlDbType::Int));
		_cmd->Parameters["@fr�geNo"]->Value=_fr�geNo;

		_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
		_cmd->Parameters["@examensID"]->Value=_examensID;

		DbDataReader^ reader = _cmd->ExecuteReader();

		reader->Read();

		int antal = reader->GetInt32(0);

		reader->Close();
		_cmd->Parameters->Clear();

		return antal;
	}

private: void getQuestion()
	{
		_cmd->CommandText="SELECT * FROM [dbo].[fr�gor] WHERE fr�geNo=@fr�geNo AND examensID = @examensID";
		
		_cmd->Parameters->Add(gcnew SqlParameter("@fr�geNo", SqlDbType::Int));
		_cmd->Parameters["@fr�geNo"]->Value=_fr�geNo;

		_cmd->Parameters->Add(gcnew SqlParameter("@examensID", SqlDbType::Char));
		_cmd->Parameters["@examensID"]->Value=_examensID;

		DbDataReader^ reader = _cmd->ExecuteReader();

		reader->Read();
		String ^returner = reader->GetString(1);

		_text = reader->GetString(2);
		_r�ttSvar = reader->GetInt32(3);

		reader->Close();
		_cmd->Parameters->Clear();
	}

private:
	DbCommand ^ _cmd;
	int _fr�geNo;
	String ^ _examensID;
	String ^ _text;
	array<String^>^ _svar;
	int _r�ttSvar;


};