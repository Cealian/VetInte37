#pragma once
//	#using <System.Data.dll>
	#using <System.Data.Entity.dll>
	#include"Jobb.h"
	#include"Anställd.h"	
	#include"Personal.h"
	#include "Login.h"
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  gprPersonal;
	private: System::Windows::Forms::Button^  button2;





	protected: 











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
			this->gprPersonal = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->grpStudent->SuspendLayout();
			this->gprPersonal->SuspendLayout();
			this->SuspendLayout();
			// 
			// grpStudent
			// 
			this->grpStudent->Controls->Add(this->button1);
			this->grpStudent->Location = System::Drawing::Point(12, 12);
			this->grpStudent->Name = L"grpStudent";
			this->grpStudent->Size = System::Drawing::Size(88, 100);
			this->grpStudent->TabIndex = 0;
			this->grpStudent->TabStop = false;
			this->grpStudent->Text = L"Student";
			// 
			// gprPersonal
			// 
			this->gprPersonal->Controls->Add(this->button2);
			this->gprPersonal->Location = System::Drawing::Point(106, 12);
			this->gprPersonal->Name = L"gprPersonal";
			this->gprPersonal->Size = System::Drawing::Size(89, 100);
			this->gprPersonal->TabIndex = 0;
			this->gprPersonal->TabStop = false;
			this->gprPersonal->Text = L"Personal";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Skriv tenta";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Skapa tenta";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(205, 122);
			this->Controls->Add(this->gprPersonal);
			this->Controls->Add(this->grpStudent);
			this->Name = L"Form2";
			this->Text = L"Meny";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->grpStudent->ResumeLayout(false);
			this->gprPersonal->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e){
				MyForm ^ loginForm = gcnew MyForm();

				loginForm->setCmd(cmd);

				loginForm->ShowDialog();
			 }
	};
}
