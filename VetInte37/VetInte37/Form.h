#pragma once
//	#using <System.Data.dll>
	#using <System.Data.Entity.dll>
	#include"Jobb.h"
	#include"Anst�lld.h"	
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
			this->SuspendLayout();
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(451, 371);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
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
