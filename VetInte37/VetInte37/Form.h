#pragma once
//	#using <System.Data.dll>
	#using <System.Data.Entity.dll>
	#include"Jobb.h"
	#include"Anställd.h"	
	#include"Personal.h"
	#include "Login.h"
	#include "SkapaTentaForm.h"
	#include "valjTentamen.h";
	#include <cliext\vector>

namespace Forms{

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
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:

		 int _loginState;

		Form2(void)
		{
			InitializeComponent();
			fac = DbProviderFactories::GetFactory("System.Data.SqlClient");
			conn = fac->CreateConnection();
			conn->ConnectionString = "Data Source=jth-stud.hj.se;Initial Catalog=DBruli1337;Integrated Security=False;User ID=ruli1337;Password=Ifqa871;Connect Timeout=15;Encrypt=False;TrustServerCertificate=False";
			conn->Open();
			cmd = fac->CreateCommand();
			cmd->Connection = conn;


		}

	protected:
		~Form2()
		{
			if (components)
			{
				delete components;
			}

			if (conn != nullptr) conn->Close();
		}
	private: 
		DbProviderFactory^ fac;
		DbConnection^ conn;
		DbCommand^ cmd;
	private: System::Windows::Forms::GroupBox^  grpStudent;
	private: System::Windows::Forms::Button^  btnSkrivTentamen;

	private: System::Windows::Forms::GroupBox^  grpPersonal;
	private: System::Windows::Forms::Button^  btnSkapaTentamen;

	/* ----------- */
	protected: 
	/* ----------- */


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->grpStudent = (gcnew System::Windows::Forms::GroupBox());
			this->btnSkrivTentamen = (gcnew System::Windows::Forms::Button());
			this->grpPersonal = (gcnew System::Windows::Forms::GroupBox());
			this->btnSkapaTentamen = (gcnew System::Windows::Forms::Button());
			this->grpStudent->SuspendLayout();
			this->grpPersonal->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpStudent
			// 
			this->grpStudent->Controls->Add(this->btnSkrivTentamen);
			this->grpStudent->Location = System::Drawing::Point(12, 12);
			this->grpStudent->Name = L"grpStudent";
			this->grpStudent->Size = System::Drawing::Size(88, 100);
			this->grpStudent->TabIndex = 0;
			this->grpStudent->TabStop = false;
			this->grpStudent->Text = L"Student";
			// 
			// btnSkrivTentamen
			// 
			this->btnSkrivTentamen->Enabled = false;
			this->btnSkrivTentamen->Location = System::Drawing::Point(6, 19);
			this->btnSkrivTentamen->Name = L"btnSkrivTentamen";
			this->btnSkrivTentamen->Size = System::Drawing::Size(75, 23);
			this->btnSkrivTentamen->TabIndex = 0;
			this->btnSkrivTentamen->Text = L"Skriv tenta";
			this->btnSkrivTentamen->UseVisualStyleBackColor = true;
			this->btnSkrivTentamen->Click += gcnew System::EventHandler(this, &Form2::btnSkrivTentamen_Click);
			// 
			// grpPersonal
			// 
			this->grpPersonal->Controls->Add(this->btnSkapaTentamen);
			this->grpPersonal->Location = System::Drawing::Point(106, 12);
			this->grpPersonal->Name = L"grpPersonal";
			this->grpPersonal->Size = System::Drawing::Size(89, 100);
			this->grpPersonal->TabIndex = 0;
			this->grpPersonal->TabStop = false;
			this->grpPersonal->Text = L"Personal";
			// 
			// btnSkapaTentamen
			// 
			this->btnSkapaTentamen->Enabled = false;
			this->btnSkapaTentamen->Location = System::Drawing::Point(6, 19);
			this->btnSkapaTentamen->Name = L"btnSkapaTentamen";
			this->btnSkapaTentamen->Size = System::Drawing::Size(75, 23);
			this->btnSkapaTentamen->TabIndex = 0;
			this->btnSkapaTentamen->Text = L"Skapa tenta";
			this->btnSkapaTentamen->UseVisualStyleBackColor = true;
			this->btnSkapaTentamen->Click += gcnew System::EventHandler(this, &Form2::btnSkapaTentamen_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(205, 122);
			this->Controls->Add(this->grpPersonal);
			this->Controls->Add(this->grpStudent);
			this->Name = L"Form2";
			this->Text = L"Meny";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->grpStudent->ResumeLayout(false);
			this->grpPersonal->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e){

				_loginState = 0;

				MyForm ^ loginForm = gcnew MyForm();

				loginForm->setCmd(cmd);

				loginForm->ShowDialog();

				_loginState = loginForm->_loginState;

				if (_loginState == 1)
				{
					btnSkapaTentamen->Enabled = true;
				}
				else if (_loginState == 2)
				{
					btnSkrivTentamen->Enabled = true;
				}
				else
				{
					Environment::Exit(0);
				}
			 }

private: System::Void btnSkapaTentamen_Click(System::Object^  sender, System::EventArgs^  e) {

			 SkapaTentaForm ^ stForm = gcnew SkapaTentaForm();

			 stForm->setCmd(cmd);

			 stForm->ShowDialog();

		 }
private: System::Void btnSkrivTentamen_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 väljTentamen ^ vtForm = gcnew väljTentamen();

			 vtForm->setCmd(cmd);

			 vtForm->ShowDialog();

		 }
};
}