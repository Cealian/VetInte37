#pragma once

#include "stdafx.h"
#using <System.Data.Entity.dll>

namespace Forms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Data::Common;
	using namespace System::Configuration;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
		{
			InitializeComponent();
		}
		
		void setCmd(DbCommand ^ cmd)
		{
			_cmd = cmd;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtPersonnummer;
	private: System::Windows::Forms::TextBox^  txtLösen;
	private: System::Windows::Forms::ComboBox^  cbTyp;
	protected: 

	protected: 


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnLogin;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		DbCommand ^ _cmd;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtPersonnummer = (gcnew System::Windows::Forms::TextBox());
			this->txtLösen = (gcnew System::Windows::Forms::TextBox());
			this->cbTyp = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtPersonnummer
			// 
			this->txtPersonnummer->Location = System::Drawing::Point(118, 12);
			this->txtPersonnummer->Name = L"txtPersonnummer";
			this->txtPersonnummer->Size = System::Drawing::Size(232, 20);
			this->txtPersonnummer->TabIndex = 0;
			// 
			// txtLösen
			// 
			this->txtLösen->Location = System::Drawing::Point(118, 38);
			this->txtLösen->Name = L"txtLösen";
			this->txtLösen->Size = System::Drawing::Size(232, 20);
			this->txtLösen->TabIndex = 1;
			this->txtLösen->UseSystemPasswordChar = true;
			// 
			// cbTyp
			// 
			this->cbTyp->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbTyp->FormattingEnabled = true;
			this->cbTyp->Location = System::Drawing::Point(118, 64);
			this->cbTyp->Name = L"cbTyp";
			this->cbTyp->Size = System::Drawing::Size(232, 21);
			this->cbTyp->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Personnummer";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(61, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Lösenord";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(63, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Kontotyp";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(275, 91);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(75, 23);
			this->btnLogin->TabIndex = 6;
			this->btnLogin->Text = L"Logga in";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::btnLogin_Click);
			// 
			// MyForm
			// 
			this->AcceptButton = this->btnLogin;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(364, 128);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbTyp);
			this->Controls->Add(this->txtLösen);
			this->Controls->Add(this->txtPersonnummer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
				 cbTyp->Items->Add("Personal");
				 cbTyp->Items->Add("Student");

				 cbTyp->Text = "Personal";

			 }

			 
			
	private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e) {
				 
				String ^ personnummer = txtPersonnummer->Text;
				String ^ lösen = txtLösen->Text;

				DbDataReader ^ reader;

				if (cbTyp->SelectedItem->ToString() == "Personal")
				{
					_cmd->CommandText = "SELECT * FROM [dbo].[personal] WHERE personnummer=@personnummer AND lösen = @lösen";
					_cmd->Parameters->Add(gcnew SqlParameter( "@personnummer", SqlDbType::Char));
					_cmd->Parameters->Add(gcnew SqlParameter( "@lösen", SqlDbType::Char));
					_cmd->Parameters["@personnummer"]->Value=personnummer;
					_cmd->Parameters["@lösen"]->Value=lösen;
					reader = _cmd->ExecuteReader();
				}
				else if (cbTyp->SelectedItem->ToString() == "Student")
				{
					_cmd->CommandText = "SELECT * FROM [dbo].[student] WHERE personnummer=@personnummer AND lösen = @lösen";
					_cmd->Parameters->Add(gcnew SqlParameter( "@personnummer", SqlDbType::Char));
					_cmd->Parameters->Add(gcnew SqlParameter( "@lösen", SqlDbType::Char));
					_cmd->Parameters["@personnummer"]->Value=personnummer;
					_cmd->Parameters["@lösen"]->Value=lösen;
					reader = _cmd->ExecuteReader();
				}
				else
				{
					return;
				}

				reader->Read();

				if(reader->HasRows)
				{
					MessageBox::Show("Inloggad");
				}

				reader->Close();
				_cmd->Parameters->Clear();
			 }
};
}
